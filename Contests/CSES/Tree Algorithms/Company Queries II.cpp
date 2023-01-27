#include <bits/stdc++.h>
using namespace std;
  
#define int long long
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
 
const int ms = 2*1e6 + 10;
const int LOG = 20;
 
vector<vector<int>> g;
vector<int> depth;
int up[ms][LOG];
 
void dfs(int u, int parent){
    for(auto v : g[u]){
        if(v == parent) continue;
        depth[v] = depth[u] + 1;
        up[v][0] = u;
        for(int i = 1; i < LOG; i++){
            up[v][i] = up[ up[v][i - 1] ][i - 1];
        }
        dfs(v, u);
    }
}
 
int lca(int u, int v){
    if(depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
 
    for(int i = LOG - 1; i >= 0; i--){
        if(diff & (1 << i)){
            u = up[u][i];
        }
    }
    if(u == v) return u;
    for(int i = LOG - 1; i >= 0; i--){
        if(up[u][i] != up[v][i]){
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n, q;
    cin >> n >> q;
 
    g.assign(n, vector<int>());
    for(int i = 1; i < n; i++){
        int u;
        cin >> u;
        g[i].push_back(u - 1);
        g[u - 1].push_back(i);
    }
 
    depth.assign(n, 0);
    dfs(0, 0);
 
    for(int i = 0; i < q; i++){
        int u, v;
        cin >> u >> v;
        cout << lca(u - 1, v - 1) + 1 << '\n';
    }
    return 0;
}