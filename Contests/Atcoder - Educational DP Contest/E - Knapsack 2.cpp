#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int MAXN = 1e3 + 100;
const int MAXVAL = 100 * 1e3 + 100;
int dp[MAXN][MAXVAL];
vector<ii> v;

int solve(int idx, int value){
    int n = v.size();
    if(value <= 0) return 0;
    if(idx >= n){
        return INF;
    }
    int & answ = dp[idx][value];
    if(answ != -1) return answ;
    
    auto [w, curr_v] = v[idx];
    answ = min(solve(idx + 1, value), w + solve(idx + 1, value - curr_v));
    return answ;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, W;
    cin >> n >> W;
    v.assign(n, {-1, -1});
    for(int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
    }
    memset(dp, -1, sizeof dp);
    int answ = 0;
    for(int i = 100 * 1e3; i >= 0; i--){
        if(solve(0, i) <= W) answ = max(answ, i);
    }
    cout << answ << '\n';

    return 0;
}