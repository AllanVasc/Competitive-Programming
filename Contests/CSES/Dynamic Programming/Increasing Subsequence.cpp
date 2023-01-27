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
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    vector<int> dp(n + 1, INF);
    dp[0] = -INF;

    for(int i = 0; i < n; i++){
        auto pos = upper_bound(dp.begin(), dp.end(), v[i]) - dp.begin();
        if(dp[pos - 1] < v[i] && dp[pos] > v[i]){
            dp[pos] = v[i];
        }
    }

    int answ = 0;
    while(answ != dp.size() && dp[answ] != INF) answ++;
    cout << answ - 1 << '\n';

    return 0;
}