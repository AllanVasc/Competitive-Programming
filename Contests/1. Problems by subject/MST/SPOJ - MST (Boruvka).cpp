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

const int ms = 10000 + 100;
int par[ms], sz[ms];
void initDSU(int n){
    for(int i = 0; i < n; i++){
        par[i] = i;
        sz[i] = 1;
    }
}

int find(int u){ return u == par[u] ? u : par[u] = find(par[u]); }
void merge(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v) return;
    if(sz[u] < sz[v]) swap(u, v);
    par[v] = u;
    sz[u] += sz[v];
}

struct Edge{
    int u, v, w, id;
    Edge() {}
    Edge(int u, int v, int w = 0, int id = 0) : u(u), v(v), w(w), id(id) {}
    bool operator < (Edge & other) const { return w < other.w; }
};

// Algorithm to find the Minimum Spanning Tree of a graph
vector<Edge> boruvka(vector<Edge> & edges, int n){
    vector<Edge> mst;
    vector<Edge> best(n);
    initDSU(n); // Use Path Compression & Union-by-size/rank
    bool f = true;
    while(f){
        f = false;
        for(int i = 0; i < n; i++) best[i] = Edge(i, i, INF);
        for(auto e : edges){
            int pu = find(e.u), pv = find(e.v);
            if(pu == pv) continue;
            if(e < best[pu]) best[pu] = e;
            if(e < best[pv]) best[pv] = e;
        }
        for(int i = 0; i < n; i++){
            Edge e = best[find(i)];
            if(find(e.u) == find(e.v)) continue;
            merge(e.u, e.v);
            mst.push_back(e);
            f = true;
        }
    }
    return mst;
}

signed main() {
    optimize;
    int n, m;
    cin >> n >> m;
    vector<Edge> edges;
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edges.push_back(Edge(u, v, w, i));
    }
    vector<Edge> mst = boruvka(edges, n);
    int cost = 0;
    for(int i = 0; i < mst.size(); i++){
        Edge e = mst[i];
        cost += e.w;
    }
    cout << cost << '\n';
    return 0;
}