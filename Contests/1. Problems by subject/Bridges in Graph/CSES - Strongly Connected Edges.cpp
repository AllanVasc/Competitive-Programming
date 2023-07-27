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

vector<vector<int>> g;
vector<int> lvl, dp;
vector<pii> bridges;
vector<pii> spanedge, backedge;
int comp = 0;

void dfs(int u, int p = -1){
    dp[u] = 0;
    for(auto v : g[u]){
        if(lvl[v] == 0){ // undiscovered (spanedge)
            lvl[v] = lvl[u] + 1;
            spanedge.push_back({u, v});
            dfs(v, u);
            dp[u] += dp[v];
        }
        else if(lvl[v] > lvl[u]){
            dp[u]--;
        }
        else if(lvl[v] < lvl[u]){
            dp[u]++;
            if(v != p) backedge.push_back({u, v});
        }
    }
    if(p != -1) dp[u]--;
    if(p != -1 && dp[u] == 0){
        bridges.push_back({u, p});
    }
}

void find_bridges(int n){
    lvl.assign(n, 0);
    dp.assign(n, 0);
    comp = 0;
    for(int i = 0; i < n; i++){
        if(!lvl[i]){
            lvl[i] = 1;
            dfs(i);
            comp++;
        }
    }
}

signed main() {
    optimize;
    int n, m;
    cin >> n >> m;
    g.assign(n, vector<int>());
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    find_bridges(n);
    if(bridges.size() || comp > 1){
        cout << "IMPOSSIBLE" << '\n';
    }
    else{
        for(auto [u, v] : spanedge){
            cout << u + 1 << " " << v + 1 << '\n';
        }
        for(auto [u, v] : backedge){
            cout << u + 1 << " " << v + 1 << '\n';
        }
    }
    return 0;
}