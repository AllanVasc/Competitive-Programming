#include <bits/stdc++.h>
using namespace std;

#define int long long
#define optimize ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define iii tuple<int,int,int>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int ms = 3e5;
int dp[ms][2], ps[ms];
// 0 1 2 3 4
int solve(int idx, int f, vector<int> & v, vector<int> & state, int & k){
    int n = v.size();
    if(idx >= n) return 0;
    int & answ = dp[idx][f];
    if(answ != -1) return answ;
    if(!f){
        int val = ps[idx + k] - ps[idx];
        // cout << "idx = " << idx << " f = " << f << " val = " << val << '\n';
        answ = max(answ, val + solve(idx + k, true, v, state, k));
    }
    int val = (state[idx] ? v[idx] : 0);
    answ = max(answ, val + solve(idx + 1, f, v, state, k));
    return answ;
}

signed main() {
    optimize;
    int n, k;
    cin >> n >> k;
    vector<int> v(n), state(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 0; i < n; i++) cin >> state[i];
    for(int i = 1; i < ms; i++){
        ps[i] = ps[i - 1] + (i <= n ? v[i - 1] : 0);
    }
    memset(dp, -1, sizeof dp);
    cout << solve(0, 0, v, state, k) << '\n';
    return 0;
}