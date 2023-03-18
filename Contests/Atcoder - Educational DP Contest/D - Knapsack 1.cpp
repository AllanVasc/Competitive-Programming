#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int MAXN = 100 + 10;
const int MAXW = 1e5 + 100;
vector<ii> v;
int dp[MAXN][MAXW];

int solve(int idx, int cur_w){
    int n = v.size();

    if(cur_w < 0) return -INF;
    if(idx >= n){
        return 0;
    }

    int& answ = dp[idx][cur_w];
    if(answ != -1) return answ;

    auto [w, val] = v[idx];
    answ = max(val + solve(idx + 1, cur_w - w), solve(idx + 1, cur_w));

    return answ;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, w;
    cin >> n >> w;
    v.assign(n, {0,0});
    for(int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
    memset(dp, -1, sizeof dp);
    cout << solve(0, w) << '\n';
    return 0;
}