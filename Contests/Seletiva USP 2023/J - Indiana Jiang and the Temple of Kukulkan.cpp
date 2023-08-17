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

vector<int> answ;
vector<vector<pii>> g;
vector<int> vis, state;

int dfs(int u){
    vis[u] = true;
    for(auto [v,id] : g[u]){
        if(vis[v]) continue;
        bool flag = dfs(v);
        if(flag){
            answ.push_back(id);
            state[v] = 1 - state[v];
            state[u] = 1 - state[u];
        }
    }
    return state[u];
}

signed main() {
    optimize;
    int n, m;
    cin >> m >> n;
    g.assign(n, vector<pii>());
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
    }
    state.assign(n, false);
    for(int i = 0; i < n; i++) cin >> state[i];
    bool flag = false;
    vis.assign(n, false);
    for(int i = 0; i < n; i++){
        if(vis[i]) continue;
        flag |= dfs(i);
    }
    if(flag){
        cout << -1 << '\n';
    }
    else{
        cout << answ.size() << '\n';
        for(auto x : answ) cout << x + 1 << " ";
        cout << '\n';
    }
    return 0;
}