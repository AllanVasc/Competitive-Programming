#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int ms = 2*1e6 + 10;
vector<int> factorial(ms, 1);
vector<int> inv_factorial(ms, 1);

int fexpo(int x, int y){
    int answ = 1;
    x = x % MOD;
    while(y){
        if(y & 1) answ = answ * x % MOD;
        x = x * x % MOD;
        y = y >> 1;
    }
    return answ;
}

int comb(int n, int k){
    if(k > n) return 0;
    return factorial[n]*inv_factorial[k] % MOD * inv_factorial[n - k] % MOD;
}

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 1; i < ms; i++){
        factorial[i] = factorial[i-1] * i % MOD;
        inv_factorial[i] = fexpo(factorial[i], MOD - 2);
    }

    int n;
    cin >> n;

    if(n % 2 == 0){
        n = n/2;
        cout << comb(2*n, n) * fexpo(n + 1, MOD - 2) % MOD << '\n';
    }
    else{
        cout << 0 << '\n';
    }
    return 0;
}