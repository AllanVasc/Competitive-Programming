#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 998244353;

const int offset = 1e5;
int old_dp[2 * offset];
int new_dp[2 * offset];
vector<int> v;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;
    v.assign(n, 0);
    for(int i = 0; i < n; i++) cin >> v[i];
    
    old_dp[offset + v[1]] = 1;
    for(int i = 1; i < n - 1; i++){
        memset(new_dp, 0, sizeof new_dp);
        for(int j = 0; j < 2 * offset; j++){
            if(!old_dp[j]) continue;

            int realValue = j - offset;
            new_dp[offset + v[i + 1] - realValue] += old_dp[j];
            new_dp[offset + v[i + 1] - realValue] %= MOD;
            if(realValue){
                new_dp[offset + v[i + 1] + realValue] += old_dp[j];
                new_dp[offset + v[i + 1] + realValue] %= MOD;
            }
        }
        swap(old_dp, new_dp);
    }

    int answ = 0;
    for(int i = 0; i < 2 * offset; i++){
        answ += old_dp[i];
        answ %= MOD;
    }

    cout << (answ + MOD) % MOD << '\n';
    return 0;
}