#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int ms = 1e6 + 100;
int dp[ms][2];

// O(n * k)
int solve(int idx, bool flag, int n, int k){
    if(idx >= n) return 1;
    int& answ = dp[idx][flag];
    if(answ != -1) return answ;
    answ = 0;
    answ += solve(idx + 1, 0, n, k);
    if(!flag){
        int limit = min(idx + k - 1, n);
        for(int i = idx; i < limit; i++){
            answ += solve(i + 1, true, n, k);
        }
    }
    return answ;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, k;
    cin >> n >> k;
    
    // dp[idx][0]   -> No idx posso colocar "B" ou "S"
    // dp[idx][1]   -> No idx obrigatoriamente coloco "B"
    dp[0][0] = dp[0][1] = 1;
    vector<int> ps(ms, 0);
    ps[0] = 1;

    for(int i = 1; i <= n; i++){
        dp[i][0] = dp[i - 1][0];
        dp[i][0] += ps[i - 1];
        dp[i][0] %= MOD;
        if(i - k >= 0) dp[i][0] -= ps[i - k];
        dp[i][0] = (dp[i][0] + MOD) % MOD;

        dp[i][1] = dp[i - 1][0];

        ps[i] = ps[i - 1] + dp[i][1];
        ps[i] %= MOD;
    }
    // cout << "dp = " << "\n";
    // for(int i = 0; i <= n; i++){
    //     cout << i << " - 0 :" << dp[i][0] << '\n';
    //     cout << i << " - 1 :" << dp[i][1] << '\n';
    // }

    cout << dp[n][0] << '\n';
    return 0;
}