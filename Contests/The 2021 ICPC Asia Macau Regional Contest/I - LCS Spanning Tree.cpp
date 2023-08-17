#include <bits/stdc++.h>
using namespace std;

#define optimize ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int ms = 4*1e6 + 10;

struct Edge{
    int u, v, w;
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
    bool operator < (Edge & other) { return w < other.w; }
};

const char separator = '#';
vector<int> patStart;
int par[ms], sz[ms];
vector<Edge> edges;

void initDSU(int n){
    for(int i = 0; i < n; i++){
        par[i] = i;
        sz[i] = 1;
    }
}
int find(int u){ return u == par[u] ? u : par[u] = find(par[u]); }
void merge(int u, int v){
    u = find(u), v = find(v);
    if(u == v) return;
    if(sz[u] < sz[v]) swap(u, v);
    par[v] = u;
    sz[u] += sz[v];
}

// O(nlogn)
void suffix_array(string & s, vector<int> & sa, vector<int> & rnk){
    s += '$';
    int n = s.size();
    int cntSz = max(n, 260);
    sa.resize(n);
    rnk.resize(n);
    for(int i = 0; i < n; i++) sa[i] = i, rnk[i] = s[i];

    patStart.resize(n);
    int cnt = 0;
    for(int i = 0; i < n; i++){
        cnt += (s[i] == separator);
        patStart[i] = cnt;
    }

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
}

// Kasai lcp O(n)
// lcp[i] = lcp(sa[i], sa[i + 1]) 
void kasai(string & s, vector<int> & sa, vector<int> & rnk){
    int n = s.size(), h = 0;
    for(int i = 0; i < n; i++){
        if(rnk[i] == n - 1) { h = 0; continue; }
        int nxt = sa[rnk[i] + 1];
        while(i + h < n && nxt + h < n && s[i + h] == s[nxt + h] && s[i + h] != separator) h++; // && s[i + h] != separator, if needed
        int u = patStart[sa[rnk[i]]];
        int v = patStart[sa[rnk[i] + 1]];
        if(u != v) edges.push_back(Edge(u, v, h));
        if(h) h--;
    }
    sort(edges.rbegin(), edges.rend());
}

signed main() {
    optimize;
    int n; cin >> n;
    string text;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        text += s;
        if(i != n - 1) text += separator;
    }
    n = text.size() + 1;
    vector<int> sa, rnk;
    suffix_array(text, sa, rnk);
    kasai(text, sa, rnk);
    long long answ = 0;
    initDSU(n + 5);
    for(auto e : edges){
        if(e.w == 0) continue;
        int pu = find(e.u), pv = find(e.v);
        if(pu == pv) continue;
        answ += e.w;
        merge(e.u, e.v);
    }
    cout << answ << endl;
    return 0;
}