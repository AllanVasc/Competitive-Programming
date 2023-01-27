#include <bits/stdc++.h>
using namespace std;
  
#define int long long
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int ms = 1e6 + 10;
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

    int t;
    cin >> t;

    for(int i = 1; i < ms; i++){
        factorial[i] = factorial[i-1] * i % MOD;
        inv_factorial[i] = fexpo(factorial[i], MOD - 2);
    }

    while(t--){
        int a, b;
        cin >> a >> b;
        
        cout << comb(a, b) << '\n';
    }
    return 0;
}