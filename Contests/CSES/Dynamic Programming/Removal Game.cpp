#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int ms = 5000 + 10;
int dp[ms][ms];
vector<int> v;

void build(){
    for(int i = 0; i < ms; i++){
        for(int j = 0; j < ms; j++){
            dp[i][j] = -1;
        }
    }
}

int solve(int i, int j){
    if(i == j){
        return dp[i][j] = v[i];
    }
    if(dp[i][j] != -1) return dp[i][j];
    int answ;
    answ = max(v[i] - solve(i + 1, j), v[j] - solve(i, j - 1));
    
    return dp[i][j] = answ;
}

void recursive(int sum, int n){
    build();
    cout << (sum + solve(0, n - 1)) / 2 << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;
    v.resize(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    int sum = 0;
    for(int i = 0; i < n; i++) sum += v[i];
    // recursive(sum, n);

    for(int i = 0; i < n; i++) dp[i][i] = v[i];
    for(int i = n - 1; i >= 0; i--){
        for(int j = i + 1; j < n; j++){
            dp[i][j] = max(v[i] - dp[i + 1][j],
                            v[j] - dp[i][j - 1]);
        }
    }

    cout << (sum + dp[0][n - 1]) / 2 << '\n';
    return 0;
}