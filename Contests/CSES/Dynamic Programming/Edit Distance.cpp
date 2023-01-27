#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int ms = 5000 + 10;
int dp[ms][ms];

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    string s1, s2;
    cin >> s1 >> s2;

    for(int i = 0; i <= s1.size(); i++){
        for(int j = 0; j <= s2.size(); j++){
            if(i == 0) dp[i][j] = j;
            else if(j == 0) dp[i][j] = i;
            else if(s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1]; 
            else{
                dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
            }
        }
    }
    
    cout << dp[s1.size()][s2.size()] << '\n';
    return 0;
}