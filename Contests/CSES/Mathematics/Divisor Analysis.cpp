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
    x = x % MOD;
    int answ = 1;
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

    vector<int> primes(n);
    vector<int> exp(n);

    for(int i = 0; i < n; i++){
        cin >> primes[i] >> exp[i];
    }

    // Quantity of divisors
    int divisors = 1;
    for(int i = 0; i < n; i++){
        divisors = divisors * (exp[i] + 1) % MOD;
    }

    // Sum of divisors
    int sum = 1;
    for(int i = 0; i < n; i++){
        sum = sum * ((fexp(primes[i], exp[i] + 1) - 1 + MOD) % MOD) % MOD * fexp(primes[i] - 1, MOD - 2) % MOD;
    }

    // Product of divisors
    vector<int> prefix(n + 1, 1);
    vector<int> suffix(n + 1, 1);
    for(int i = 1; i <= n; i++){
        prefix[i] = (prefix[i - 1] * (exp[i - 1] + 1)) % (MOD - 1);
        suffix[n - i] = (suffix[n - i + 1] * (exp[n - i] + 1)) % (MOD - 1);
    }

    int prod = 1;
    for(int i = 1; i <= n; i++){
        int elev = ((exp[i - 1] * (exp[i - 1] + 1) )/2) % (MOD - 1) * prefix[i - 1] % (MOD - 1) * suffix[i] % (MOD - 1);
        prod = (prod * fexp(primes[i - 1], elev) % MOD);
    }
    
    cout << divisors << " " << sum << " " << prod << '\n';
    return 0;
}