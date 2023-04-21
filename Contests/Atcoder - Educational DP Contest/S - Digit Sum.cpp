#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int ms = 10000 + 100;
const int mmod = 100 + 10;
int dp[ms][2][mmod];
string s;
int d;

int solve(int idx, bool flag, int sum){
    int n = s.size();
    if(idx >= n){
        return (sum % d == 0);
    }
    int& answ = dp[idx][flag][sum];
    if(answ != -1) return answ;

    int val = s[idx] - '0';

    answ = 0;
    if(flag){
        for(int i = 0; i <= val; i++){
            if(i != val) answ += solve(idx + 1, false, (sum + i) % d);
            else answ += solve(idx + 1, true, (sum + i) % d);
            answ %= MOD;
        }
    }
    else{
        for(int i = 0; i < 10; i++){
            answ += solve(idx + 1, false, (sum + i) % d);
            answ %= MOD;
        }
    }

    return answ;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> s;
    cin >> d;

    memset(dp, -1, sizeof dp);
    cout << (solve(0, 1, 0) - 1 + MOD) % MOD << '\n';

    return 0;
}