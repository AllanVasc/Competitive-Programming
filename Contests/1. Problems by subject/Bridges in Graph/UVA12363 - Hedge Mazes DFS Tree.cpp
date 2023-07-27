#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using pii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

vector<vector<int>> g_orig;
vector<vector<int>> g_changed;

vector<int> lvl, dp;
vector<pii> bridges;

vector<int> component;

void dfs(int u, int p = -1){
    dp[u] = 0;
    for(auto v : g_orig[u]){
        if(lvl[v] == 0){ // Edge to child
            lvl[v] = lvl[u] + 1;
            dfs(v, u);
            dp[u] += dp[v];
        }
        else if(lvl[v] < lvl[u]){ // Edge upwards
            dp[u]++;
        }
        else if(lvl[v] > lvl[u]){ // Edge downwards
            dp[u]--;
        }
    }
    if(p != -1) dp[u]--;    // Parent edge isn't a back-edge
    if(p != -1 && dp[u] == 0){
        bridges.push_back({p, u});
        g_changed[p].push_back(u);
        g_changed[u].push_back(p);
    }
}

void find_bridges(int n){
    lvl.assign(n, 0);
    dp.assign(n, 0);
    for(int i = 0; i < n; i++){
        if(!lvl[i]){
            lvl[i] = 1;
            dfs(i);
        }
    }
}

void dfs2(int u, int id){
    component[u] = id;
    for(auto i : g_changed[u]){
        if(component[i] == -1) dfs2(i, id);
    }
}

void solve(int n){
    component.assign(n, -1);
    for(int i = 0; i < n; i++){
        if(component[i] == -1) dfs2(i, i);
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int r, c, q;
    while(cin >> r >> c >> q){
        if(r == 0 && c == 0 && q == 0) return 0;

        g_orig.assign(r, vector<int>());
        for(int i = 0; i < c; i++){
            int u, v;
            cin >> u >> v;
            u--, v--;
            g_orig[u].push_back(v);
            g_orig[v].push_back(u);
        }

        g_changed.assign(r, vector<int>());
        find_bridges(r);
        solve(r);

        for(int i = 0; i < q; i++){
            int u, v;
            cin >> u >> v;
            u--, v--;
            cout << (component[u] == component[v] ? "Y" : "N") << '\n';
        }
        cout << "-" << '\n';
    }

    return 0;
}