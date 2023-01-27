// 
#include <bits/stdc++.h>
using namespace std;
  
#define int long long
  
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18;
const int MOD = 1e9 + 7;

const int MAXN = 1e5 + 10;
vector<int> fat;
vector<int> inv_fat;

int fExpo(int x, int y, int MOD){
    int answ = 1;
    x = x % MOD;
    if(x == 0) return 0;
    while(y){
        if(y & 1) answ = (answ*x)%MOD;
        y = y >> 1;
        x = x*x%MOD;
    }
    return answ;
}

int ModMulInv(int x){
    return fExpo(x, MOD-2, MOD);
}

int comb(int n, int k){
    if(k < 0 || k > n) return 0;
    return fat[n] * inv_fat[k] % MOD * inv_fat[n-k] % MOD;
}

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    fat.assign(n + 5, 1);
    inv_fat.assign(n + 5, 1);

    for(int i = 1; i < n; i++){
        fat[i] = fat[i-1]*i%MOD;
        inv_fat[i] = ModMulInv(fat[i]);
    }

    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    int answ = 0;
    for(int i = 0; i < n; i++){
        answ = (answ + (comb(n-1, i)*v[i]%MOD)) % MOD;
    }

    cout << answ << '\n';

    return 0;
}