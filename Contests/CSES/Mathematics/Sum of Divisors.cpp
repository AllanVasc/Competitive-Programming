#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int fexp(int x, int y){
    int answ = 1;
    x = x % MOD;
    while(y){
        if(y & 1) answ = answ * x % MOD;
        x = x * x % MOD;
        y >>= 1;
    }
    return answ;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;

    int answ = 0;
    // Daria TLE
    // for(int i = 1; i * i <= n; i++){
    //     for(int j = i*i; j <= n; j+= i){
    //         answ = (answ + i) % MOD;
    //         if(j > i * i) answ = (answ + (j/i)) % MOD;
    //     }
    // }

    for(int i = 1; i * i <= n; i++){
        int qtd_i = (n / i - (i - 1) + MOD) % MOD;
        
        int a1 = (i + 1);
        int an = (n / i) % MOD;
        int qtd_term = (an - a1 + 1 + MOD) % MOD;
        int sumPA = (a1 + an) % MOD * qtd_term % MOD * fexp(2, MOD - 2) % MOD;

        answ = (answ + i * qtd_i % MOD) % MOD;
        answ = ((answ + sumPA) % MOD + MOD) % MOD;
    }

    cout << answ << '\n';
    
    return 0;
}