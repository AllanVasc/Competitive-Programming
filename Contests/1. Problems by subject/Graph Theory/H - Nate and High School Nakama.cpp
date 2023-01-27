// 
#include <bits/stdc++.h>
using namespace std;
  
#define int long long
  
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int MAXN = 3010;

vector<int> fat(MAXN, 1);
vector<int> inv_fat(MAXN, 1);
vector<int> dp;

int fexpo(int x, int y){
    int answ = 1;
    x = x % MOD;
    while(y){
        if(y & 1) answ = (answ*x)%MOD;
        x = x*x%MOD;
        y = y >> 1;
    }
    return answ;
}

int comb(int n, int k){
    if(k > n) return 0;
    return fat[n]*inv_fat[k]%MOD * inv_fat[n-k]%MOD;
}

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 1; i < MAXN; i++){
        fat[i] = fat[i-1]*i%MOD;
        inv_fat[i] = fexpo(fat[i], MOD-2);
    }

    int n;
    cin >> n;

    vector<int>dp(MAXN, 1);

    for(int i = 2; i <= n; i++){
        int answ = 0;
        for(int j = 1; j <= i-1; j++){
            answ = (answ + comb(i-1,j-1)*dp[j]%MOD * fexpo(2, comb(i-j,2)%MOD))%MOD;
        }
        dp[i] = ((fexpo(2, comb(i, 2)) - answ) + MOD)%MOD;
    }

    int answ = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n-i+1; j++){
            answ = (answ + comb(n-i, j-1)*dp[j]%MOD *fexpo(2, comb(n-j,2))%MOD)%MOD;
        }
    }

    cout << answ << '\n';

    return 0;
}