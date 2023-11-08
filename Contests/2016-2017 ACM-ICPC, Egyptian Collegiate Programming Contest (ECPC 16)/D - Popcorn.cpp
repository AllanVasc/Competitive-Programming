#include <bits/stdc++.h>
using namespace std;

#define int long long
#define optimize ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define iii tuple<int,int,int>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

signed main() {
    optimize;
    
    freopen("popcorn.in", "r", stdin); // CHANGE
    vector<vector<int>> dp(22, vector<int>(22, 0));
    dp[0][0] = 1;
    for(int i = 1; i < 22; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0) dp[i][j] = 1;
            else{
                dp[i][j] = dp[i - 1][j];
                if(j - 1 >= 0) dp[i][j] += dp[i - 1][j - 1];
            }
        }
    }

    // for(int i = 0 ;i < 22; i++){
    //     cout << "i = " << i << ": ";
    //     for(int j = 0; j <= i; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        cout << dp[n][m] << '\n';
    }

    return 0;
}