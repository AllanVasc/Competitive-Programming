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

    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    const int MAXN = 1e5 + 10;
    int dp[MAXN][5];
    for(int i = 0; i < MAXN; i++){
        for(int j = 0; j < 5; j++){
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 4; j++){
            if(j == 0) dp[i][j + (s[i - 1] == 'h')] = min(dp[i][j + (s[i - 1] == 'h')], dp[i - 1][j]);
            else if(j == 1) dp[i][j + (s[i - 1] == 'a')] = min(dp[i][j + (s[i - 1] == 'a')], dp[i - 1][j]);
            else if(j == 2) dp[i][j + (s[i - 1] == 'r')] = min(dp[i][j + (s[i - 1] == 'r')], dp[i - 1][j]);
            else dp[i][j + (s[i - 1] == 'd')] = min(dp[i][j + (s[i - 1] == 'd')], dp[i - 1][j]);

            dp[i][j] = min(dp[i][j], dp[i - 1][j] + v[i - 1]);
        }
    }

    int answ = INF;
    for(int i = 0; i < 4; i++){
        answ = min(answ, dp[n][i]);
    }
    cout << answ << '\n';
    return 0;
}