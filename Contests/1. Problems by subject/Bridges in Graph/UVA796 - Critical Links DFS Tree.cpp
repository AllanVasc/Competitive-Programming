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

void dfs(int u, int p = -1){
    dp[u] = 0;
    for(auto v : g[u]){
        if(lvl[v] == 0){ // Edge to child
            lvl[v] = lvl[u] + 1;
            dfs(v, u);
            dp[u] += dp[v];
        }
        else if(lvl[v] < lvl[u]){ // Edge upwards
            // cout << "upward " << u << "," << v << '\n';
            dp[u]++;
        }
        else if(lvl[v] > lvl[u]){ // Edge downwards
            // cout << "downwards " << u << "," << v << '\n';
            dp[u]--;
        }
    }
    if(p != -1) dp[u]--; // Parent edge isn't a back-edge
    if(p != -1 && dp[u] == 1){
        bridges.push_back({min(p, u), max(p, u)});
    }
    // cout << "dp de " << u << " = " << dp[u] << '\n';
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

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    while(cin >> n){
        g.assign(n, vector<int>());
        for(int i = 0; i < n; i++){
            int u;
            cin >> u;
            char trash;
            int qtd;
            cin >> trash >> qtd >> trash;
            for(int j = 0; j < qtd; j++){
                int v; 
                cin >> v;
                g[u].push_back(v);
                g[v].push_back(u);
            }
        }
        find_bridges(n);
        cout << bridges.size() << " critical links\n";
        sort(bridges.begin(), bridges.end());
        for(int i = 0; i < bridges.size(); i++){
            cout << bridges[i].first << " - " << bridges[i].second << "\n";
        }
        cout << '\n';
        bridges.clear();
    }
    return 0;
}