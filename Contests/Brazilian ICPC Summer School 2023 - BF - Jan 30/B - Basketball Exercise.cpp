#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int MAXN = 1e5 + 10;
const int STATES = 5;
int dp[MAXN][STATES];

vector<vector<int>> v;
int solve(int idx, int estado){
    int n = v[0].size();
    if(idx >= n) return 0;
    int & answ = dp[idx][estado];
    if(answ != -1) return answ;

    if(estado == 0){
        answ = max(answ, solve(idx + 1, 0));
        answ = max(answ, v[0][idx] + solve(idx + 1, 1));
        answ = max(answ, v[1][idx] + solve(idx + 1, 2));
    }
    else if(estado == 1){
        answ = max(answ, solve(idx + 1, 0));
        answ = max(answ, v[1][idx] + solve(idx + 1, 2));
    }
    else{
        answ = max(answ, solve(idx + 1, 0));
        answ = max(answ, v[0][idx] + solve(idx + 1, 1));
    }

    return answ;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    v.assign(2, vector<int>(n, 0));
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < n; j++){
            cin >> v[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));

    cout << solve(0, 0) << '\n';
    return 0;
}