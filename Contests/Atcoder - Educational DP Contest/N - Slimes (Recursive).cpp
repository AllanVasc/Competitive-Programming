#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int ms = 405;
int dp[ms][ms];
int ps[ms];

int solve(int i, int j){
    if(i == j) return 0;
    int& answ = dp[i][j];
    if(answ != -1) return answ;

    answ = INF;
    for(int mid = i; mid < j; mid++){
        answ = min(answ, ps[j] - ps[i - 1] + solve(i, mid) + solve(mid + 1, j));
    }

    return answ;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> v(n + 1);
    for(int i = 1; i <= n; i++) cin >> v[i];
    for(int i = 1; i <= n; i++) ps[i] = ps[i - 1] + v[i];

    memset(dp, -1, sizeof dp);
    cout << solve(1, n) << '\n';

    return 0;
}