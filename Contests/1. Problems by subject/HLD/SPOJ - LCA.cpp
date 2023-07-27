#include <bits/stdc++.h>
using namespace std;

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

const int ms = 1e4 + 10;
vector<vector<int>> g;
pair<int,int> edges[ms];
int sobe[ms];
int sz[ms], par[ms], head[ms], pos[ms];
int seg[4 * ms], v[ms];
int t;

void dfs_sz(int u, int p = -1){
    sz[u] = 1;
    for(auto & v : g[u]){
        if(v == p) continue;
        par[v] = u;
        dfs_sz(v, u);
        if(g[u][0] == p || sz[g[u][0]] < sz[v]) swap(v, g[u][0]);
    }
}

void dfs_hld(int u, int p = -1){
    pos[u] = t++;
    for(auto v : g[u]){
        if(v == p) continue;
        head[v] = (v == g[u][0] ? head[u] : v);
        dfs_hld(v, u);
    }
}

void build_hld(int root = 0){
    dfs_sz(root);
    t = 0;
    head[root] = root;
    dfs_hld(root);
}

int lca(int a, int b){
    if(pos[a] < pos[b]) swap(a, b);
    return (head[a] == head[b] ? b : lca(par[head[a]], b));
}

int32_t main() {
    optimize;
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++){
        cout << "Case " << cs << ":\n"; 
        int n;
        cin >> n;
        g.assign(n, vector<int>());
        vector<bool> isRoot(n, true);
        for(int i = 0; i < n; i++){
            int qtt; cin >> qtt;
            for(int j = 0; j < qtt; j++){
                int v; cin >> v;
                v--;
                isRoot[v] = false;
                g[i].push_back(v);
            }
        }
        for(int i = 0; i < n; i++){
            if(isRoot[i]) build_hld(i);
        }
        int q;
        cin >> q;
        while(q--){
            int u, v;
            cin >> u >> v;
            u--, v--;
            cout << lca(u, v) + 1 << '\n';
        }
    }
    return 0;
}