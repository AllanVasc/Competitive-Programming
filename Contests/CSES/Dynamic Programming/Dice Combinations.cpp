#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

vector<int> dp;

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    dp.assign(n + 100, 0);

    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 6; j++){
            if(i - j >= 0){
                //cout << "joguei j = " << j << '\n';
                // cout << "dp[i - j] = " << dp[i - j] << '\n';
                dp[i] = (dp[i] + dp[i - j]) % MOD;

            }
        }

        // cout << "i = " << i << " :" << dp[i] << '\n';
    }

    cout << dp[n] << '\n';
    return 0;
}