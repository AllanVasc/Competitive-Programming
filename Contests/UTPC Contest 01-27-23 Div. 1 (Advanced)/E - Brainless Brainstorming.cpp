#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int ms = 1e3 + 10;
int dp[ms][2];

vector<int> a, b, c;
int solve(int idx, int flag){
    int n = a.size();
    if(idx >= n) return 0;
    int& answ = dp[idx][flag];
    if(answ != -1) return answ;

    answ = 0;
    if(flag){
        answ = max({a[idx] + solve(idx + 1, !flag),
                   b[idx] + solve(idx + 1, !flag),
                   c[idx] + solve(idx + 1, !flag),
                   solve(idx + 1, flag)});
    }
    else{
        answ = solve(idx + 1, !flag);
    }
    return answ;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    a.assign(n, 0);
    b.assign(n, 0);
    c.assign(n, 0);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) cin >> c[i];

    memset(dp, -1, sizeof dp);
    cout << solve(0, 1) << '\n';

    return 0;
}