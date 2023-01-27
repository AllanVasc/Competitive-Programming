#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int fexpo(int x, int y){
    x = x%MOD;
    int answ = 1;
    while(y){
        if(y & 1) answ = answ*x % MOD;
        x = x*x%MOD;
        y >>= 1;
    }
    return answ;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n, m;
    cin >> n >> m;

    int answ = 0;
    
    // Burnside's lemma
    for(int i = 0; i <= n - 1; i++){
        answ = (answ + fexpo(m, __gcd(i, n)) % MOD)%MOD;
    }
    
    cout << answ * fexpo(n, MOD - 2) % MOD << '\n';

    return 0;
}