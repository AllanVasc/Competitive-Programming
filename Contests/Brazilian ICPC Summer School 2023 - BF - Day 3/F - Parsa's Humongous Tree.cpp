#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int MAXN = 1e5 + 10;
int dp[MAXN][2];
vector<vector<int>> g;
vector<vector<int>> points;

void solve(int vtx, int parent){
    dp[vtx][0] = dp[vtx][1] = 0;
    for(auto u : g[vtx]){
        if(u == parent) continue;
        solve(u, vtx);
        dp[vtx][0] += max( abs(points[vtx][0] - points[u][0]) + dp[u][0], abs(points[vtx][0] - points[u][1]) + dp[u][1]);
        dp[vtx][1] += max( abs(points[vtx][1] - points[u][0]) + dp[u][0], abs(points[vtx][1] - points[u][1]) + dp[u][1]);
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        points.assign(n, {0,0});
        for(int i = 0 ; i < n; i++) cin >> points[i][0] >> points[i][1];
        
        g.assign(n, vector<int>());
        for(int i = 0; i < n - 1; i++){
            int u, v;
            cin >> u >> v;
            u--, v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        solve(0, 0);
        cout << max(dp[0][0], dp[0][1]) << '\n';
    }
    return 0;
}