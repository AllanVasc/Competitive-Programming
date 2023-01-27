#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 998244353 ;

const int ms = 1e6 + 100;

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
    
    int n, m;
    cin >> n >> m;
    
    vector<bool> is_prime(ms, true);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i < ms; i++){
        if(is_prime[i]){
            for(int j = i * i; j < ms; j += i){
                is_prime[j] = false;
            }
        }
    }

    int total = 0;
    int unambiguous = 1;
    int lcm = 1;
    for(int i = 1; i <= n; i++){
        total += fexp(m, i);
        total %= MOD;

        if(is_prime[i]) lcm *= i;

        unambiguous *= (m/lcm) % MOD;
        unambiguous %= MOD; 

        total = (total - unambiguous + MOD) % MOD;
    }

    cout << (total + MOD) % MOD << '\n';
    return 0;
}