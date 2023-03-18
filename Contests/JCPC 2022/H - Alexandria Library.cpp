#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int ms = 3*1e5 + 100;
const int LOG = 20;
vector<vector<int>> g;
int sz[ms], depth[ms], up[ms][LOG];

void dfs(int u, int p){
    sz[u] = 1;
    for(auto v : g[u]){
        if(v == p) continue;
        depth[v] = depth[u] + 1;
        up[v][0] = u;
        for(int i = 1; i < LOG; i++){
            up[v][i] = up[ up[v][i - 1] ][i - 1];
        }
        dfs(v, u);
        sz[u] += sz[v];
    }
}

int kAncestor(int u, int k){
    if(depth[u] < k) return -1;
    for(int i = 0; i < LOG; i++){
        if(k & (1 << i)) u = up[u][i];
    }
    return u;
}

int lca(int u, int v){
    if(depth[u] < depth[v]) swap(u, v);
    int k = depth[u] - depth[v];
    for(int i = LOG - 1; i >= 0; i--){
        if(k & (1 << i)){
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

int calcDist(int u, int v){
    return (depth[u] + depth[v] - 2 * depth[(lca(u, v))]);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    freopen("library.in", "r", stdin);

    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        g.assign(n, vector<int>());

        for(int i = 0; i < n - 1; i++){
            int u, v;
            cin >> u >> v;
            u--, v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        dfs(0, -1);

        while(q--){
            int u, v;
            cin >> u >> v;
            u--, v--;
            if(depth[u] < depth[v]) swap(u, v); // u esta embaixo
            
            int answ = 0;
            int dist = calcDist(u, v);
            if(dist == 0){ // u == v
                answ = n;
            }
            else if(dist % 2 != 0){ // no answ
                answ = 0;
            }
            else{
                int cm = kAncestor(u, dist / 2);
                int check = lca(cm, v);
                if(check == cm){
                    // ambos embaixo!
                    int subU = kAncestor(u, dist/2 - 1);
                    int subV = kAncestor(v, dist/2 - 1);
                    answ = n - sz[subU] - sz[subV];
                }
                else{
                    int subU = kAncestor(u, dist/2 - 1);
                    answ = sz[cm] - sz[subU];
                }
            }
            cout << answ << '\n';
        }
    }
    return 0;
}