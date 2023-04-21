#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int ms = 3*1e3 + 1;
int dp[ms][ms];

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string s;
    int k;
    cin >> s >> k;
    int n = s.size();

    for(int l = n - 1; l >= 0; l--){
        for(int r = l + 1; r < n; r++){
            dp[l][r] = (s[l] != s[r]);
            if(r - l > 1) dp[l][r] += dp[l + 1][r - 1];
            // cout << "l = " << l << " r = " << r << " " << dp[l][r] << endl;
        }
    }

    int answ = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            // cout << "[" << i << "," << j << "] = " << dp[i][j] << endl;
            if(dp[i][j] <= k) answ++;
        }
    }
    cout << answ << '\n';
    return 0;
}