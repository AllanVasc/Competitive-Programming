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

    int n, x;
    cin >> n >> x;
    
    vector<int> coins(n);
    for(int i = 0; i < n; i++) cin >> coins[i];

    dp.assign(x + 100, INF);
    sort(coins.begin(), coins.end());

    dp[0] = 0;
    for(int i = 1; i <= x; i++){
        for(int j = 0; j < n; j++){
            if(coins[j] > i) break;
            dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
        }
    }

    cout << (dp[x] == INF ? -1 : dp[x]) << '\n';
    return 0;
}