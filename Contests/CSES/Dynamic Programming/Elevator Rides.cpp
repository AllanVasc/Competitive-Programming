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
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    vector<pii> dp(1 << n, {n + 1, x});
    // dp[mask][0] = minimum number of rides
    // dp[mask][1] = minimum weight in the last ride
    dp[0] = {1, 0};
    for(int mask = 1; mask < (1 << n); mask++){
        for(int j = 0; j < n; j++){
            pii option = {n + 1, 0};
            if(mask & (1 << j)){
                if(v[j] + dp[mask ^ (1 << j)].second <= x){
                    option = dp[mask ^ (1 << j)];
                    option.second += v[j];
                }
                else{
                    option.first = dp[mask ^ (1 << j)].first + 1;
                    option.second = v[j];
                }
            }
            dp[mask] = min(dp[mask], option);
        }
    }
    cout << dp[(1 << n) - 1].first << '\n';
    return 0;
}