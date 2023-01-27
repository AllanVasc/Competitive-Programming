// 
#include <bits/stdc++.h>
using namespace std;
  
#define int long long
  
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

typedef unsigned long long ull;
typedef long double ld;

// Miller Rabin Primality Test

// Just a multiplication to avoid overflow
ull fmul(ull a, ull b, ull m){
    ull q = (ld) a * (ld) b / (ld) m;
    ull r = a * b - q * m;
    return (r + m) % m;
}

// Fast Modular Exponentiation
ull fexp(ull x, ull y, ull m){
    ull answ = 1;
    x = x % m;
    while(y){
        if(y & 1) answ = fmul(answ, x, m);
        x = fmul(x, x, m);
        y = y >> 1;
    }
    return answ;
}

// Validation by Fermat’s Small Theorem
// a^(p-1) - 1 = 0 mod p
// (a^((p-1)/2) - 1)*(a^((p-1)/2) + 1) = 0 mod p
bool miller(ull p, ull a){
    ull s = p - 1;
    while(s % 2 == 0) s >>= 1;
    while(a >= p) a >>= 1;
    ull mod = fexp(a, s, p);
    while(s != p - 1 && mod != 1 && mod != p-1){
        mod = fmul(mod, mod, p);
        s <<= 1;
    }
    if(mod != p - 1 && s % 2 == 0) return false;
    else return true;
}

// Deterministic Miller Rabin algorithm
// We need to check for different bases "a" to increase the probability of hit
bool prime(ull p){
    if(p < 2) return false;
    if(p == 2) return true;
    if(p % 2 == 0) return false;
    for(ull a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}){
        if(p == a) return true;
        if(!miller(p, a)) return false;
    }
    return true;
}

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;

    while(t--){
        ull n;
        cin >> n;

        if(prime(n)) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}