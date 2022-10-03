#include <bits/stdc++.h>
using namespace std;

// This code becomes inefficient for numbers greater to 10^20
// To numbers greater than 2^64 use __int128
typedef unsigned long long ull;

// Miller Rabin

ull mul(ull a, ull b, ull mod){
    ull answ = 0;
    for(a %= mod, b %= mod; b != 0;
        b >>= 1, a <<= 1, a = a >= mod ? a - mod : a){
        if(b & 1){
            answ += a;
            if(answ >= mod) answ -= mod;
        }
    }
    return answ;
}

ull mpow(ull a, ull b, ull mod){
    ull answ = 1;
    for(; b; b >>= 1, a = mul(a, a, mod))
        if(b & 1) answ = mul(answ, a, mod);
    return answ;
}

bool witness(ull a, ull k, ull q, ull n){
    ull t = mpow(a, q, n);
    if(t == 1 || t == n-1) return false;
    for(int i = 0; i < k - 1; i++){
        t = mul(t, t, n);
        if(t == 1) return true;
        if(t == n - 1) return false;
    }
    return true;
}

vector<ull> test = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
bool isPrime(ull n){
    if(n == 2) return true;
    if(n < 2 || !(n & 1)) return false;
    ull q = n - 1, k = 0;
    while(!(q & 1)) q >>= 1, k++;
    for(ull a : test){ // Maybe larger numbers than 1e9 is enough to generate 2 numbers rand()%(n-4) + 2;
        if(n == a) return true;
        if(witness(a, k, q, n)) return false;
    }
    return true;
}

// Pollard Rho

ull pollard_rho(ull n, ull c){
    ull x = 2, y = 2, i = 1, k = 2, d;
    while(1){
        x = (mul(x, x, n) + c);
        if(x >= n) x -= n;
        d = __gcd(x - y, n);
        if(d > 1) return d;
        if(++i == k) y = x, k <<= 1;
    }
    return n;
}

void factorize(vector<ull>& answ, ull n){
    if(n == 1) return;
    if(isPrime(n)){
        answ.push_back(n);
        return;
    }
    ull d = n;
    for(int i = 2; d == n; i++) d = pollard_rho(n, i);
    factorize(answ, d);
    factorize(answ, n/d);
}

// cin/cout to deal with __int128

istream& operator>>(istream& in, ull &x){
    static char s[40];
    in >> s;
    x = 0;
    for(char* p = s; *p; ++p) x = 10 * x + *p - '0';
    return in;
}

ostream& operator<<(ostream& out, ull x){
    static char s[40] = {};
    char* p = s + (sizeof(s) - 1);
    while (*--p = (char)(x % 10 + '0'), x /= 10, x);
    return out << p;
}

/*

Time Complexity

Miller_Rabin    -> O(K*log^3(N)) Where N is the number to be checked for primality, and K is the number of checks to get accuracy
Pollard_Rho     -> O(n^1/4)

Links:

Miller Rabin

https://cp-algorithms.com/algebra/primality_tests.html#deterministic-version
https://www.geeksforgeeks.org/multiply-large-integers-under-large-modulo/
https://www.youtube.com/watch?v=qdylJqXCDGs
https://www.youtube.com/watch?v=zmhUlVck3J0

Pollard Rho

https://cp-algorithms.com/algebra/factorization.html
https://www.youtube.com/watch?v=6khEMeU8Fck

*/