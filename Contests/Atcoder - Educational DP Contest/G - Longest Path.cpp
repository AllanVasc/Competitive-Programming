#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int MAXN = 1e5 + 100;
int dp[MAXN];
vector<vector<int>> g;
void dfs(int u, int p = -1){
    if(dp[u] != -1) return;
    dp[u] = 0;
    for(auto v : g[u]){
        if(v == p) continue;
        dfs(v, u);
        dp[u] = max(dp[u], 1 + dp[v]);
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    g.assign(n, vector<int>());
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
    }
    memset(dp, -1, sizeof dp);
    int answ = 0;
    for(int i = 0; i < n; i++){
        if(dp[i] == -1) dfs(i);
        answ = max(answ, dp[i]);
    }

    cout << answ << '\n';
    return 0;
}