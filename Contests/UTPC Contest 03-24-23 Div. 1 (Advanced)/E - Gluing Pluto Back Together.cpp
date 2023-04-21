#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int ms = 12 + 1;
const int mmask = (1 << ms);
int dp[ms][ms][mmask];
vector<vector<int>> mat;

int solve(int first, int last, int mask){
    int n = mat.size();
    
    if(__builtin_popcount(mask) == n) return mat[first][last];
    int& answ = dp[first][last][mask];
    if(answ != -1) return answ;

    answ = INF;
    for(int i = 0; i < n; i++){
        if((mask & (1 << i)) == 0){
            answ = min(answ, mat[last][i] + solve(first, i, mask ^ (1 << i)));
        }
    }
    return answ;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    mat.assign(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> mat[i][j];
        }
    }
   
    int answ = INF;
    for(int i = 0; i < n; i++){
        memset(dp, -1, sizeof dp);
        answ = min(answ, solve(i, i, (1 << i)));
    }
    cout << answ << '\n';

    return 0;
}