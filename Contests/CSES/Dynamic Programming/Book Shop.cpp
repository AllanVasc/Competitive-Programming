#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int maxn = 1e3 + 1;
const int maxx = 1e5 + 1;
int dp[maxn][maxx];

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    vector<int> prices(n);
    vector<int> pages(n);

    for(int i = 0; i < n; i++) cin >> prices[i];
    for(int i = 0; i < n; i++) cin >> pages[i];

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= x; j++){
            dp[i][j] = dp[i-1][j];
            if(j - prices[i - 1] >= 0)
                dp[i][j] = max(dp[i][j], pages[i - 1] + dp[i - 1][j - prices[i - 1]]);
        }
    }

    cout << dp[n][x] << '\n';
    return 0;
}