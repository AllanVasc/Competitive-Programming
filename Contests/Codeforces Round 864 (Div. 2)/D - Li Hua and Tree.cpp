#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

vector<vector<int>> tree;
vector<int> v;
const int ms = 1e5 + 100;
int dp[ms], sz[ms], parent[ms];

void precalc(int u, int p){
    parent[u] = p;
    sz[u] = 1;
    dp[u] = v[u];
    for(auto v : tree[u]){
        if(v == p) continue;
        precalc(v, u);
        sz[u] += sz[v];
        dp[u] += dp[v];
    }
}

vector<set<ii>> g;
void rotate(int u){
    if(g[u].size() == 0) return;
    int pu = parent[u];
    auto [szHc, Hc] = *g[u].begin();
    g[u].erase(g[u].begin());
    g[pu].erase({-sz[u], u});
    parent[u] = Hc;
    parent[Hc] = pu;

    sz[u] -= sz[Hc];
    sz[Hc] += sz[u];
    dp[u] -= dp[Hc];
    dp[Hc] += dp[u];

    // Falta atualizar o grafo
    g[pu].insert({-sz[Hc], Hc});
    g[Hc].insert({-sz[u], u});
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    tree.assign(n, vector<int>());
    v.assign(n, 0);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    precalc(0, 0);
    g.assign(n, set<ii>());
    for(int i = 0; i < n; i++){
        for(int j = 0; j < tree[i].size(); j++){
            int v = tree[i][j];
            if(parent[i] == v) continue;
            g[i].insert({-sz[v], v});
        }
    }

    while(m--){
        int cmd, u;
        cin >> cmd >> u;
        u--;

        if(cmd == 1){
            cout << dp[u] << '\n';
        }
        else{
            // reroot
            rotate(u);
        }
    }
    return 0;
}