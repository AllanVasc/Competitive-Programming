#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int h, w;
    cin >> h >> w;

    vector<string> grid(h);
    for(int i = 0; i < h; i++) cin >> grid[i];
    
    vector<vector<int>> dp(h + 1, vector<int>(w + 1, 0));
    dp[1][1] = 1;
    for(int i = 1; i <= h; i++){
        for(int j = (i == 1? 2 : 1); j <= w; j++){
            if(grid[i - 1][j - 1] == '.') dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
        }
    }
    cout << dp[h][w] << '\n';
    return 0;
}