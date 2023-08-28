#include <bits/stdc++.h>
using namespace std;

#define int long long
#define optimize ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define iii tuple<int,int,int>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

// O(nlogn)
vector<int> suffix_array(string & s){
    s += '$';
    int n = s.size();
    int cntSz = max(n, 260LL);
    vector<int> sa(n), rnk(n);
    for(int i = 0; i < n; i++) sa[i] = i, rnk[i] = s[i];

    for(int k = 0; k < n; k ? k *= 2 : k++){
        vector<int> nsa(sa), nrnk(n), cnt(cntSz);

        for(int i = 0; i < n; i++) nsa[i] = (nsa[i] - k + n) % n, cnt[rnk[i]]++;
        for(int i = 1; i < cntSz; i++) cnt[i] += cnt[i - 1];
        for(int i = n - 1; i >= 0; i--) sa[--cnt[rnk[nsa[i]]]] = nsa[i];

        for(int i = 1, r = 0; i < n; i++){
            r += rnk[sa[i]] != rnk[sa[i - 1]] || rnk[(sa[i] + k) % n] != rnk[(sa[i - 1] + k) % n];
            nrnk[sa[i]] = r;
        }
        rnk = nrnk;
        if(rnk[sa[n - 1]] == n - 1) break;
    }
    return sa;
}

// Kasai lcp O(n)
// lcp[i] = lcp(sa[i], sa[i + 1]) 
vector<int> kasai(string & s, vector<int> & sa){
    int n = s.size(), h = 0;
    vector<int> rnk(n), lcp(n);
    for(int i = 0; i < n; i++) rnk[sa[i]] = i;
    for(int i = 0; i < n; i++){
        if(rnk[i] == n - 1) { h = 0; continue; }
        int nxt = sa[rnk[i] + 1];
        while(i + h < n && nxt + h < n && s[i + h] == s[nxt + h]) h++; // && s[i + h] != separator, if needed
        lcp[rnk[i]] = h;
        if(h) h--;
    }
    return lcp;
}

const int ms = 1e6;
int seg1[4 * ms];

void build1(int p, int l, int r, vector<int> & v){
    if(l == r){
        seg1[p] = v[l];
    }
    else{
        int m = (l + r) >> 1;
        int lc = 2*p;
        int rc = lc + 1;
        build1(lc, l, m, v);
        build1(rc, m + 1, r, v);
        seg1[p] = min(seg1[lc], seg1[rc]);
    }
}
int query1(int p, int l, int r, int ql, int qr){
    if(l >= ql && r <= qr) return seg1[p];
    int m = (l + r) >> 1;
    int lc = 2*p;
    int rc = lc + 1;
    if(qr <= m) return query1(lc, l, m, ql, qr);
    else if(ql > m) return query1(rc, m + 1, r, ql, qr);
    else return min(query1(lc, l, m, ql, qr), query1(rc, m + 1, r, ql, qr));
}

vector<int> precompute(string s1, string s2){
    string text = s1 + "#" + s2;
    vector<int> sa = suffix_array(text);
    vector<int> lcp = kasai(text, sa);

    int n = text.size();
    vector<int> closest_left(n, -1);
    for(int i = 0; i < n; i++){
        if(sa[i] > s1.size()){ // representa S2
            closest_left[i] = i;
        }
        else closest_left[i] = closest_left[i - 1];
    }
    vector<int> closest_right(n, INF);
    for(int i = n - 1; i >= 0; i--){
        if(sa[i] > s1.size()){
            closest_right[i] = i;
        }
        else{
            if(i == n - 1) continue;
            closest_right[i] = closest_right[i + 1];
        }
    }
    // Para cada sufixo de S1, precomputar o max prefixo que da match com S2
    build1(1, 0, n - 1, lcp);
    vector<int> mxPrefix_suffix(s1.size(), 0);
    vector<int> rnk(n);
    for(int i = 0; i < n; i++) rnk[sa[i]] = i;
    for(int i = 0; i < s1.size(); i++){
        int lansw = 0, ransw = 0;
        int pos = rnk[i];
        if(closest_left[pos] != -1){
            lansw = query1(1, 0, n - 1, closest_left[pos], pos - 1);
        }
        if(closest_right[pos] != INF){
            ransw = query1(1, 0, n - 1, pos, closest_right[pos] - 1);
        }
        mxPrefix_suffix[i] = max(lansw, ransw);
    }
    return mxPrefix_suffix;
}

struct query{
    int l, r, idx;
    query(int l, int r, int idx) : l(l), r(r), idx(idx) {}
};

struct node{
    int sum, qtt, sumPref;
    node(){}
    node(int x){
        sum = x;
        qtt = 1;
        sumPref = 0;
    }
    node(const node & a, const node & b){
        sum = a.sum + b.sum;
        qtt = a.qtt + b.qtt;
        sumPref = a.sumPref + b.sumPref;
    }
};

node seg2[4 * ms];
void build2(int p, int l, int r){
    if(l == r){
        seg2[p] = node(-l + 1);
    }
    else{
        int m = (l + r) >> 1;
        int lc = 2*p;
        int rc = lc + 1;
        build2(lc, l, m);
        build2(rc, m + 1, r);
        seg2[p] = node(seg2[lc], seg2[rc]);
    }
}

void update2(int p, int l, int r, int idx, int val){
    if(l == r){
        seg2[p].sum = 0;
        seg2[p].qtt = 0;
        seg2[p].sumPref = val;
    }
    else{
        int m = (l + r) >> 1;
        int lc = 2*p;
        int rc = lc + 1;
        if(idx <= m) update2(lc, l, m, idx, val);
        else update2(rc, m + 1, r, idx, val);
        seg2[p] = node(seg2[lc], seg2[rc]);
    }
}

node query2(int p, int l, int r, int ql, int qr){
    if(l >= ql && r <= qr) return seg2[p];
    int m = (l + r) >> 1;
    int lc = 2*p;
    int rc = lc + 1;
    if(qr <= m) return query2(lc, l, m, ql, qr);
    else if(ql > m) return query2(rc, m + 1, r, ql, qr);
    else return node(query2(lc, l, m, ql, qr), query2(rc, m + 1, r, ql, qr));
}

signed main() {
    optimize;
    freopen("curse.in", "r", stdin); // NAO ESQUECER
    int t; cin >> t;
    for(int cs = 1; cs <= t; cs++){
        cout << "Case " << cs << ":" << '\n';
        string s1, s2;
        cin >> s1 >> s2;
        vector<int> mxPrefix_suffix = precompute(s1, s2);

        // cout << "Max Prefix of Suffix: ";
        // for(auto x : mxPrefix_suffix) cout << x << " ";
        // cout << '\n';

        vector<pii> conj;
        for(int i = 0; i < s1.size(); i++){
            conj.push_back({mxPrefix_suffix[i] + i - 1, i});
        }
        sort(conj.rbegin(), conj.rend());

        int q; cin >> q;
        vector<query> queries;
        for(int i = 0; i < q; i++){
            int l, r; cin >> l >> r;
            l--, r--;
            queries.push_back(query(l, r, i));
        }
        sort(queries.begin(), queries.end(), [&](query & a, query & b){
            return a.r < b.r;
        });
        build2(1, 0, s1.size() - 1);
        vector<int> answ(q, 0);
        for(int i = 0; i < q; i++){
            auto [l, r, idx] = queries[i];
            while(!conj.empty()){
                auto [val, idxConj] = conj.back();
                if(val <= r){
                    update2(1, 0, s1.size() - 1, idxConj, mxPrefix_suffix[idxConj]);
                    conj.pop_back();
                }
                else break;
            }
            node aux = query2(1, 0, s1.size() - 1, l, r);
            answ[idx] = aux.sum + aux.qtt * r + aux.sumPref;
        }

        for(int i = 0; i < q; i++) cout << answ[i] << '\n';
    }
    return 0;
}