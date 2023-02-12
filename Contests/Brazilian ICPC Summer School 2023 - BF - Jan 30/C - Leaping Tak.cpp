#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 998244353;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<ii> interv;
    for(int i = 0; i < k; i++){
        int l, r;
        cin >> l >> r;
        interv.push_back({l, r});
    }

    vector<int> dp(n + 10, 0), ps(n + 10, 0);
    dp[1] = ps[1] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 0; j < k; j++){
            auto [l, r] = interv[j];
            if(i - l >= 0){
                dp[i] += ps[i - l];
                dp[i] %= MOD;
            }
            if(i - r - 1 >= 0){
                dp[i] -= ps[i - r - 1];
                dp[i] %= MOD;
            }
        }
        ps[i] = (ps[i - 1] + dp[i]);
        ps[i] %= MOD;
    }

    cout << (dp[n] + MOD) % MOD << '\n';

    return 0;
}