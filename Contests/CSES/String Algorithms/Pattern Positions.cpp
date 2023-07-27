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

class SuffixArray{
public:
    string text;
    vector<int> sa;
    vector<int> rank;
    vector<int> lcp;
    vector<int> seg;

    void build(int p, int l, int r){
        if(l == r){
            seg[p] = sa[l];
        }
        else{
            int m = (l + r) >> 1;
            int lc = 2*p;
            int rc = lc + 1;
            build(lc, l, m);
            build(rc, m + 1, r);
            seg[p] = min(seg[lc], seg[rc]);
        }
    }
    int query(int p, int l, int r, int ql, int qr){
        if(l >= ql && r <= qr) return seg[p];
        int m = (l + r) >> 1;
        int lc = 2*p;
        int rc = lc + 1;
        if(qr <= m) return query(lc, l, m, ql, qr);
        if(ql > m) return query(rc, m + 1, r, ql, qr);
        return min(query(lc, l, m, ql, qr), query(rc, m + 1, r, ql, qr));
    }
    void process(string & s){
        text = s;
        text += '$';
        int n = text.size();
        sa.resize(n);
        rank.resize(n);

        vector<pii> list;
        for(int i = 0; i < n; i++){
            list.push_back({text[i], i});
        }
        sort(list.begin(), list.end());
        for(int i = 0; i < n; i++) sa[i] = list[i].second;
        rank[sa[0]] = 0;
        int classe = 0;
        for(int i = 1; i < n; i++){
            if(text[sa[i]] != text[sa[i - 1]]) classe++;
            rank[sa[i]] = classe;
        }
        
        int k = 1;
        while(k < n){
            vector<int> aux(n);
            vector<int> count(n, 0);
            for(int i = 0; i < n; i++) count[rank[i]]++;
            for(int i = 1; i < n; i++) count[i] += count[i - 1];
            for(int i = n - 1; i >= 0; i--){
                int idx = (sa[i] - k + n) % n;
                aux[count[rank[idx]] - 1] = idx;
                count[rank[idx]]--;
            }
            swap(sa, aux);
            aux[sa[0]] = 0;
            classe = 0;
            for(int i = 1; i < n; i++){
                if(rank[sa[i]] != rank[sa[i - 1]] ||
                   rank[(sa[i] + k) % n] != rank[(sa[i - 1] + k) % n]){
                    classe++;
                }
                aux[sa[i]] = classe;
            }
            swap(rank, aux);
            k += k;
        }

        // lcp O(n)
        // lcp[i] = lcp(sa[i], sa[i - 1])
        lcp.assign(n, 0);
        int h = 0;
        for(int i = 0; i < n; i++) rank[sa[i]] = i;
        for(int i = 0; i < n; i++){
            if(rank[i]){
                k = sa[rank[i] - 1];
                while(text[i + h] == text[k + h]) h++;
                lcp[rank[i]] = h;
                if(h) h--;
            }
        }
        seg.assign(4 * sa.size(), INF);
        build(1, 0, sa.size() - 1);
    }

    int find(string & pat){
		int l = 0;
		int r = sa.size() - 1;
        for(int i = 0; i < pat.size(); i++){
            int st = l;
            int en = r;
            int answ = text.size();
            while(st <= en){
                int m = (st + en) >> 1;
                int idx = sa[m];
                if(text[idx + i] >= pat[i]){
                    if(text[idx + i] == pat[i]){
                        answ = min(answ, m);
                    }
                    en = m - 1;
                }
                else{
                    st = m + 1;
                }
            }
            if(answ == text.size()) return -1;
            l = answ;
            st = answ;
            en = r;
            while(st <= en){
                int m = (st + en) >> 1;
                int idx = sa[m];
                if(text[idx + i] <= pat[i]){
                    if(text[idx + i] == pat[i]){
                        answ = max(answ, m);
                    }
                    st = m + 1;
                }
                else{
                    en = m - 1;
                }
            }
            r = answ;
        }
        return (query(1, 0, sa.size() - 1, l, r) + 1);
    }
};

signed main() {
    optimize;
    
    string s;
    cin >> s;
    SuffixArray sa;
    sa.process(s);
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        cout << sa.find(s) << '\n';
    }
    return 0;
}