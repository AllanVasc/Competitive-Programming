#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int ms = 1e5 + 100;
int dp[ms][2];
vector<vector<int>> g;

void solve(int u, int p = -1){
    int currB = 1;
    int currP = 1;
    for(auto v : g[u]){
        if(v == p) continue;
        solve(v, u);
        currB = currB * ((dp[v][0] + dp[v][1]) % MOD) % MOD;
        currP = currP * dp[v][0] % MOD;
    }
    dp[u][0] = currB;
    dp[u][1] = currP;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    g.assign(n, vector<int>());
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    solve(0);

    cout << (dp[0][0] + dp[0][1]) % MOD << '\n';
    return 0;
}