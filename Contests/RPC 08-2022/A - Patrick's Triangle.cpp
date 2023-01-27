// 
#include <bits/stdc++.h>
using namespace std;
  
#define int long long
  
const int inf = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18;
const int MOD = 1e9 + 7;

const int MAXN = 1e6 + 10;
vector<int> fat;
vector<int> inv_fat;

int fExp(int x, int y, int p){
    int answ = 1;
    x = x % p;
    if(x == 0) return 0;
    while(y){
        if(y & 1) answ = answ * x % p;
        y = y >> 1;
        x = x * x % p;
    }
    return answ;
}

int ModMultInv(int n){
    return fExp(n, MOD - 2, MOD);
}

int comb(int n, int k){
    if(k < 0 || n < k) return 0;
    return fat[n] * inv_fat[k] % MOD * inv_fat[n-k] % MOD; 
}

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    fat.assign(MAXN, 1);
    inv_fat.assign(MAXN, 1);

    for(int i = 1; i < MAXN; i++){
        fat[i] = fat[i-1] * i % MOD;
        inv_fat[i] = ModMultInv(fat[i]);
    }

    int q;
    cin >> q;

    while(q--){
        int r, c, x;
        cin >> r >> c >> x;

        int answ = ((((1*comb(r-1,c+1) + 2*comb(r-1,c)%MOD)%MOD + 1*comb(r-1,c-1))%MOD + 2*comb(r-1,c-2)%MOD)%MOD + 1*comb(r-1,c-3))%MOD;

        if(answ == x) cout << "Correct" << '\n';
        else cout << "Incorrect" << '\n';
    }
 
    return 0;
}