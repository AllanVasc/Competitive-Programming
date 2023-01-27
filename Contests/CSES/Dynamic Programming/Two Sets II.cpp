#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int fexp(int x, int y){
    x = x % MOD;
    int answ = 1;
    while(y){
        if(y & 1) answ = answ * x % MOD;
        x = x * x % MOD;
        y >>= 1;
    }
    return answ;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;

    int totalsum = ((1 + n)*n) / 2;
    if(totalsum % 2 != 0){
        cout << 0 << '\n';
    }
    else{
        int half = totalsum / 2;

        vector<vector<int>> dp(n + 5, vector<int>(half + 5, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++){ // coins
            for(int j = 0; j <= half; j++){ // sum
                dp[i][j] = dp[i - 1][j];
                if(j - i >= 0) dp[i][j] = (dp[i][j] + dp[i - 1][j - i]) % MOD;
            }
        }

        cout << dp[n][half] * fexp(2, MOD - 2) % MOD << '\n';
    }
    return 0;
}