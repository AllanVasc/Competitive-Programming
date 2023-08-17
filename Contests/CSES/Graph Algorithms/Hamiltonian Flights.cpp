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

vector<vector<int>> g;
const int ms = 20;
int dp[ms][1 << ms];

int solve(int last, int mask){
    int n = g.size();
    int bits = __builtin_popcount(mask);
    if(bits == n){
        return last == n - 1;
    }
    int & answ = dp[last][mask];
    if(answ != -1) return answ;
    answ = 0;
    for(int u : g[last]){
        if(mask & (1 << u)) continue;
        if(u == n - 1 && bits != n - 1) continue;
        answ += solve(u, mask ^ (1 << u));
        answ %= MOD;
    }
    return answ;
}

signed main() {
    optimize;
    int n, m;
    cin >> n >> m;
    g.assign(n, vector<int>());
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
    }
    memset(dp, -1, sizeof dp);
    cout << solve(0, 1) << '\n';
    return 0;
}