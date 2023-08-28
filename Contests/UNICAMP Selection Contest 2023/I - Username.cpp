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

const int ms = 4 * 1e5;
int seg[4 * ms];
void build(int p, int l, int r, vector<int> & v){
    if(l == r){
        seg[p] = v[l];
    }
    else{
        int m = (l + r) >> 1;
        int lc = 2*p;
        int rc = lc + 1;
        build(lc, l, m, v);
        build(rc, m + 1, r, v);
        seg[p] = min(seg[lc], seg[rc]);
    }
}

int query(int p, int l, int r, int ql, int qr){
    if(l > qr || r < ql) return INF;
    if(l >= ql && r <= qr) return seg[p];
    int m = (l + r) >> 1;
    int lc = 2*p;
    int rc = lc + 1;
    return min(query(lc, l, m, ql, qr), query(rc, m + 1, r, ql, qr));
}

int solve(string & s1, string & s2){
    string text = s1 + "#" + s2;
    vector<int> sa = suffix_array(text);
    vector<int> lcp = kasai(text, sa);
    
    int n = sa.size();
    vector<int> next_left(n, 0);
    for(int i = 0; i < n; i++){
        if(sa[i] > s1.size()) next_left[i] = i;
        else next_left[i] = next_left[i - 1]; 
    }

    vector<int> next_right(n, INF);
    for(int i = n - 1; i >= 0; i--){
        if(sa[i] > s1.size()) next_right[i] = i;
        else{
            if(i == n - 1) continue;
            next_right[i] = next_right[i + 1];
        }
    }
    vector<int> rnk(n, 0);
    for(int i = 0; i < n; i++) rnk[sa[i]] = i;
    build(1, 0, n - 1, lcp);
    int answ = INF;
    for(int i = 0; i < s1.size(); i++){
        int pos = rnk[i];
        int cnt = 0;
        cnt = max(cnt, query(1, 0, n - 1, next_left[pos], pos - 1));
        if(next_right[pos] != INF){
            cnt = max(cnt, query(1, 0, n - 1, pos, next_right[pos] - 1));
        }
        // cnt eh o maior prefixo do sufixo que deu match
        int sz = s1.size() - i;
        if(cnt + 1 <= sz) answ = min(answ, cnt + 1);
    }
    return (answ == INF ? -1 : answ);
}

signed main() {
    optimize;
    string s1, s2;
    cin >> s1 >> s2;
    cout << solve(s1, s2) << '\n';
    return 0;
}