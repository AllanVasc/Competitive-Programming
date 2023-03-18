#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

void printps(vector<int> ps, int n){
    cout << "ps = ";
    for(int i = 0; i <= n; i++){
        cout << ps[i] << " ";
    }
    cout << "\n";
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, k;
    cin >> n >> k;
    
    const int ms = 100 + 10;
    const int mk = 1e5 + 100;

    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    vector<vector<int>> dp(ms, vector<int>(mk, 0));
    vector<int> ps(mk, 0); 

    for(int i = 0; i <= v[0]; i++) dp[0][i] = 1;
    
    for(int i = 0; i < mk; i++){
        if(i == 0) ps[i] = dp[0][i];
        else ps[i] = ps[i - 1] + dp[0][i];
        ps[i] %= MOD;
    }
    
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= k; j++){
            dp[i][j] = ps[j];
            if(j - v[i] > 0) dp[i][j] -= ps[j - v[i] - 1];
            dp[i][j] = (dp[i][j] + MOD) % MOD;
        }
        for(int j = 0; j <= k; j++){
            if(j == 0) ps[j] = (dp[i][j]) % MOD;
            else{
                ps[j] = (ps[j - 1] + dp[i][j]) % MOD;
            }
        }
    }
    
    cout << (dp[n - 1][k] + MOD) % MOD << '\n';
    return 0;
}