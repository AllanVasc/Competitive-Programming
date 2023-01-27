#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

vector<vector<int>> g;

vector<int> dp, nodes;
int answ;

void precalc(int u, int parent){
    nodes[u] = 1;
    dp[u] = 1;
    for(auto v : g[u]){
        if(v != parent){
            precalc(v, u);
            nodes[u] += nodes[v];
            dp[u] += dp[v] + nodes[v];
        }
    }
}

void dfs(int u, int parent){ // Reroot
    answ = max(answ, dp[u]);
    for(auto v : g[u]){
        if(v != parent){
            int newValue = dp[u] - dp[v] - nodes[v];
            dp[v] += newValue + nodes[u] - nodes[v];
            nodes[v] = nodes[u];
            dfs(v, u);
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;
    g.assign(n + 1, vector<int>());
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }

    dp.assign(n, 0);
    nodes.assign(n, 0);
    precalc(0, 0);
    dfs(0,0);

    cout << answ << '\n';

    return 0;
}