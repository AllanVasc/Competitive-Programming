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

struct Seg{
    vector<int> seg, v;
    int n;

    Seg(vector<int> & v) : v(v), n(v.size()){
        seg.assign(4 * n, 0);
        build(1, 0, n - 1);
    }

    void build(int p, int l, int r){
        if(l == r) seg[p] = v[l];
        else{
            int m = (l + r) >> 1;
            int lc = 2*p;
            int rc = lc + 1;
            build(lc, l, m);
            build(rc, m + 1, r);
            seg[p] = min(seg[lc], seg[rc]);
        }
    }

    // primeira posicao < val em [ql, qr] (ou -1 se nao tem)
    int get_left(int p, int l, int r, int ql, int qr, int val){
        if(r < ql || l > qr || seg[p] >= val) return -1;
        if(l == r) return l;
        int m = (l + r) >> 1;
        int lc = 2*p;
        int rc = lc + 1;
        int x = get_left(lc, l, m, ql, qr, val);
        if(x != -1) return x;
        return get_left(rc, m + 1, r, ql, qr, val);
    }

    // ultima posicao < val em [ql, qr] (ou -1 se nao tem)
    int get_right(int p, int l, int r, int ql, int qr, int val){
        if(r < ql || l > qr || seg[p] >= val) return -1;
        if(l == r) return l;
        int m = (l + r) >> 1;
        int lc = 2*p;
        int rc = lc + 1;
        int x = get_right(rc, m + 1, r, ql, qr, val);
        if(x != -1) return x;
        return get_right(lc, l, m, ql, qr, val);
    }
};

struct SuffixArray{
public:
    int n, realSz;
    string text;
    vector<int> sa, rank, lcp;
    vector<int> patStart, ps;
    char separator = 'A' - 1; // If you need, apply Suffix Array to integers

    SuffixArray(string & s) : text(s), realSz(s.size()) {}

    void add_pattern(string & s){
        n = text.size();
        text += separator + s;
        patStart.push_back(n + 1);
        separator--;
    }

    void build(){
        text += '$'; // Needs to be lexicographically smaller than all separators
        n = text.size();
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

        ps.assign(n, 0); // Prefix Sum of the suffixes that are part of the original text
        for(int i = 0; i < n; i++){
            ps[i] = sa[i] < realSz;
            if(i) ps[i] += ps[i - 1];
        }

        build_lcp();
    }

    // Kasai lcp O(n)
    // lcp[i] = lcp(sa[i], sa[i + 1]) 
    void build_lcp(){
        lcp.assign(n, 0);
        int h = 0;
        for(int i = 0; i < n; i++) rank[sa[i]] = i;
        for(int i = 0; i < n; i++){
            if(rank[i] == n - 1){
                h = 0;
                continue;
            }
            int nxt = sa[rank[i] + 1];
            while(text[i + h] == text[nxt + h]) h++;
            lcp[rank[i]] = h;
            if(h) h--;
        }
        // build_RMQ(lcp)
    }

    void print_SA(){
        cout << "text = " << text << '\n';
        for(int i = 0; i < sa.size(); i++){
            cout << i << " = " << sa[i] << " : ";
            for(int j = sa[i]; j < text.size(); j++) cout << text[j];
            cout << '\n';
        }
        cout << '\n';
    }
};

signed main() {
    optimize;
    int n, m;
    cin >> n >> m;
    string s; cin >> s;
    SuffixArray sa(s);
    cin >> s;
    sa.add_pattern(s);
    sa.build();
    Seg seg(sa.lcp);
    int q; cin >> q;
    // sa.print_SA();
    while(q--){
        int l, r;
        cin >> l >> r;
        l--, r--;

        int sz = r - l + 1;
        int pos = sa.rank[sa.patStart[0] + l];
        // cout << "[" << l << "," << r << "]" << " pos = " << pos << '\n';

        int L = seg.get_right(1, 0, seg.n - 1, 0, pos - 1, sz);
        // cout << "L = " << L << '\n';
        L++;

        int R = seg.get_left(1, 0, seg.n - 1, pos, seg.n - 1, sz);
        // cout << "R = " << R << '\n';
        //if(R == -1) R = seg.n - 1;

        // cout << "ps[R] = " << sa.ps[R] << '\n';
        cout << sa.ps[R] - (L ? sa.ps[L - 1] : 0) << '\n';
    }
    return 0;
}