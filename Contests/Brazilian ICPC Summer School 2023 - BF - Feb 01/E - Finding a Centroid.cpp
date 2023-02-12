#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int MAXN = 2e5 + 100;
int dp[MAXN];

int n;
int answ = -1;
vector<vector<int>> g;

int dfs(int v, int p){
    bool is_centroid = true;
    dp[v] = 1;
    for(auto u : g[v]){
        if(u == p) continue;
        dfs(u, v);
        dp[v] += dp[u];
        if(dp[u] > n / 2) is_centroid = false;
    }
    if(is_centroid && n - dp[v] <= n / 2) answ = v;
    return dp[v];
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    g.assign(n, vector<int>());
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0,0);

    cout << answ + 1 << '\n';
    return 0;
}