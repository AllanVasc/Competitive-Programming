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

    vector<vector<char>> grid(n, vector<char>(n,'!'));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> dp(n + 5, vector<int>(n + 5, 0));

    if(grid[0][0] != '*') dp[0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] != '*'){
                if(i - 1 >= 0) dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
                if(j - 1 >= 0) dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
            }
        }
    }

    cout << dp[n-1][n-1] << '\n';

    return 0;
}