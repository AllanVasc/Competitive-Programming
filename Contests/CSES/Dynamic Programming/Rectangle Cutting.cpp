#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int ms = 500 + 10;
int dp[ms][ms];

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int a, b;
    cin >> a >> b;

    for(int i = 0; i < ms; i++){
        for(int j = 0; j < ms; j++){
            dp[i][j] = INF;
        }
    }

    for(int i = 1; i < ms; i++){
        for(int j = 1; j < ms; j++){
            if(i == j){
                dp[i][j] = 0;
                continue;
            }
            for(int k = 1; k < i; k++){
                dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i - k][j]);
            }
            for(int k = 1; k < j; k++){
                dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j - k]);
            }
        }
    }

    cout << dp[a][b] << '\n';
    return 0;
}