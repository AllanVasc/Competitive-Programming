// 
#include <bits/stdc++.h>
using namespace std;
  
#define int long long
  
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 998244353 ;

vector<int> fat;
vector<int> inv_fat;

int fexpo(int x, int y){
    int answ = 1;
    x = x % MOD;
    while(y){
        if(y&1) answ = answ*x%MOD;
        x = x*x%MOD;
        y = y >> 1;
    }
    return answ;
}

int comb(int n, int k){
    if(k > n) return 0;
    return fat[n]*inv_fat[k]%MOD *inv_fat[n-k]%MOD;
}
int dp[65][3];

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;

    fat.assign(65,1);
    inv_fat.assign(65,1);
    for(int i = 1; i < 65; i++){
        fat[i] = i*fat[i-1]%MOD;
        inv_fat[i] = fexpo(fat[i], MOD-2);
    }

    // Base case
    dp[2][0] = 1;   // Alex
    dp[2][1] = 0;   // Boris
    dp[2][2] = 1;   // Draw

    for(int i = 4; i <= 60; i+=2){
        dp[i][0] = (comb(i-1, i/2) + dp[i-2][1])%MOD;
        dp[i][1] = (comb(i-2, i/2) + dp[i-2][0])%MOD;
        dp[i][2] = dp[i-2][2];
    }

    while(t--){
        int n;
        cin >> n;

        cout << dp[n][0] << " " << dp[n][1] << " " << dp[n][2] << '\n';
    }
    
    return 0;
}