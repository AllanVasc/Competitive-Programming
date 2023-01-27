#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int ms = 1e6 + 10;
const int linked = 2;
const int mask = 4;

int dp[ms][linked][mask];

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    dp[0][1][0] = 1;
    for(int i = 1; i < ms; i++){
        // 00 = 0 -> Close
        // 01 = 1 -> rigth open
        // 10 - 2 -> left open
        // 11 - 3 -> all open
        dp[i][0][0] = ((((dp[i - 1][0][0] + dp[i - 1][0][1]) % MOD + dp[i - 1][0][2]) % MOD +
                      dp[i - 1][0][3]) % MOD + dp[i - 1][1][0]) % MOD;
        
        dp[i][0][1] = dp[i][0][0];
        dp[i][0][2] = dp[i][0][1];
        dp[i][0][3] = dp[i][0][2];

        dp[i][1][0] = ((dp[i - 1][1][3] + dp[i - 1][1][0]) % MOD + dp[i - 1][0][0]) % MOD;
        dp[i][1][1] = 0;
        dp[i][1][2] = 0;
        dp[i][1][3] = dp[i][1][0];
    }

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << (dp[n][0][0] + dp[n][1][0]) % MOD << '\n';
    }
    
    return 0;
}