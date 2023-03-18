#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

string s;
const int ms = 1e6 + 100;
int dp[ms];
int solve(int idx){
    int n = s.size();
    if(idx >= n) return 1;
    int& answ = dp[idx];
    if(answ != -1) return answ;

    answ = 0;
    if(s[idx] == 'T' || s[idx] == 'C'){
        answ += (solve(idx + 1)) % MOD;
        answ %= MOD;
    }
    if(idx + 1 < n){
        if((s[idx] == 'T' && s[idx + 1] == 'C') ||
           (s[idx] == 'C' && s[idx + 1] == 'C') ){
            answ += (solve(idx + 2)) % MOD;
            answ %= MOD;
           }
    }
    return answ;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> s;
    memset(dp, -1, sizeof dp);
    cout << solve(0) % MOD << '\n';

    return 0;
}