#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1000000009;

const int MAXB = 130;
const int MAXR = 1e3 + 100;
int dp[MAXB][MAXR][MAXB];
int pw[MAXB];
int k, b;

int solve(int idx, int resto, int sum){
    if(idx == b){
        if(resto == 0) return sum;
        else return 0;
    }
    int & answ = dp[idx][resto][sum];
    if(answ != -1) return answ;

    int one = solve(idx + 1, (resto + pw[idx]) % k, sum + 1);
    int zero = solve(idx + 1, resto, sum);

    return answ = (one + zero) % MOD;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> k >> b;
    memset(dp, -1, sizeof dp);
    pw[0] = 1;
    for(int i = 1; i < MAXB; i++){
        pw[i] = pw[i - 1] * 2 % k;
    }
    cout << solve(0, 0, 0) << '\n';
    return 0;
}