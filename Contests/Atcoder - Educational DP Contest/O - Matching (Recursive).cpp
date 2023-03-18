#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int ms = 25;
const int mmask = (1 << 21);
int dp[ms][mmask];
vector<vector<int>> comp;

int solve(int i, int mask){
    int n = comp.size();
    if(i >= n){
        int match = __builtin_popcount(mask);
        if(match == n) return 1;
        else return 0;
    }
    int& answ = dp[i][mask];
    if(answ != -1) return answ;

    answ = 0;
    for(int j = 0; j < n; j++){
        if(comp[i][j] && ((mask & (1 << j)) == 0)){
            answ += solve(i + 1, mask | (1 << j));
            answ %= MOD;
        }
    }
    return answ;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    comp.assign(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> comp[i][j];
        }
    }

    memset(dp, -1, sizeof dp);
    cout << solve(0,0) << '\n';

    return 0;
}