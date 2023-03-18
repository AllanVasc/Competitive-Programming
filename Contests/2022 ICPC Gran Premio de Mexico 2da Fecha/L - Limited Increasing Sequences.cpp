#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int cntBackTrack = 0;
void backtrack(vector<int>& v, int prefix, int sum, int k){
    if(sum > k) return;
    if(sum == k){
        cntBackTrack++;
        for(auto x : v) cout << x << " ";
        cout << '\n';
    }
    else{
        for(int i = 1; i <= prefix; i++){
            v.push_back(i);
            backtrack(v, prefix + i, sum + i, k);
            v.pop_back();
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int k;
    cin >> k;
    vector<int> dp(k + 5, 0);
    vector<int> ps(k + 5, 0);
    dp[1] = ps[1] = 1;
    for(int i = 2; i <= k; i++){
        dp[i] = ((ps[i - 1] - ps[ ((i + 1) / 2) - 1]) + MOD) % MOD;
        ps[i] = (ps[i - 1] + dp[i]) % MOD;
    }
    cout << dp[k] << '\n';
    return 0;
}