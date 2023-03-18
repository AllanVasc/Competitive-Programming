#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int ms = 3*1e3 + 100;
int dp[ms][ms];
vector<int> v;

int solve(int i, int j){
    if(i == j) return v[i];
    int & answ = dp[i][j];
    if(answ != -1) return answ;
    answ = max(v[i] - solve(i + 1, j), v[j] - solve(i, j - 1));
    return answ;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    v.assign(n, 0);
    for(int i = 0; i < n; i++) cin >> v[i];
    // recursive
    // memset(dp, -1, sizeof dp);
    // cout << solve(0, n - 1) << '\n';
    
    for(int l = n - 1; l >= 0; l--){
        for(int r = l; r < n; r++){
            if(l == r) dp[l][r] = v[l];
            else dp[l][r] = max(v[l] - dp[l + 1][r], v[r] - dp[l][r - 1]);
        }
    }

    cout << dp[0][n - 1] << '\n';
    return 0;
}