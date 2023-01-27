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
    
    vector<int> dp(n + 5, INF);

    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        int number = i;
        while(number){
            int digit = number % 10;
            number = number / 10;
            if(digit != 0){
                dp[i] = min(dp[i], 1 + dp[i - digit]);
            }
        }
    }

    cout << dp[n] << '\n';
    return 0;
}