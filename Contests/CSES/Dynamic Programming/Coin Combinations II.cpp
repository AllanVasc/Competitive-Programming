#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int maxn = 1e2 + 5;
const int maxx = 1e6 + 5;

int dp[maxn][maxx];
int n;
vector<int> v;

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x;
    cin >> n >> x;

    v.assign(n + 1,0);
    for(int i = 1; i <= n; i++) cin >> v[i];

    for(int i = 0; i < maxn; i++){
        dp[i][0] = 1;
    }

    sort(v.begin(), v.end());
    for(int i = 1; i <= n; i++){
        for(int x = 1; x < maxx; x++){
            dp[i][x] = dp[i - 1][x];

            if(x - v[i] >= 0){
                dp[i][x] = (dp[i][x] + dp[i][x - v[i]]) % MOD;
            }
        }
    }

    cout << dp[n][x] << '\n';
    return 0;
}