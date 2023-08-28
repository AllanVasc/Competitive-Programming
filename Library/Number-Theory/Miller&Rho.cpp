#include <bits/stdc++.h>
using namespace std;

// This code becomes inefficient for numbers greater to 10^20
// To numbers greater than 2^64 use __int128 and maybe __float128
typedef unsigned long long ull;
typedef long double ld;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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

// Validation by Fermat's little Theorem
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
// For values greater than 2^64 add more bases
vector<ull> test = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
bool prime(ull p){
    if(p < 2) return false;
    if(p % 2 == 0) return (p == 2);
    for(ull a : test){
        if(p == a) return true;
        if(!miller(p, a)) return false;
    }
    return true;
}

// Pollard Rho

// Function used in Pollard Rho f(x) = x^2 + c
ull func(ull x, ull c, ull n){
    return (fmul(x, x, n) + c) % n;
}

ull gcd(ull a, ull b){
    if(!b) return a;
    else return gcd(b, a % b);
}

// Pollard Rho algorithm to discover a factor of n
ull rho(ull n){
    if(n % 2 == 0) return 2;
    if(prime(n)) return n;
    while(1){
        ull c;
        do {
            c = uniform_int_distribution<ull>(0, n - 1)(rng);
        } while(c == 0 || (c + 2) % n == 0);
        ull x = 2, y = 2, d = 1;
        ull pot = 1, lam = 1;
        do {
            if(pot == lam){
                x = y;
                pot <<= 1;
                lam = 0;
            }
            y = func(y, c, n);
            lam++;
            d = gcd(x >= y ? x - y : y - x, n);
        } while(d == 1);
        if(d != n) return d;
    }
}

// Return all the factors of n
vector<ull> factors(ull n){
    vector<ull> answ, rest, times;
    if(n == 1) return answ;
    rest.push_back(n);
    times.push_back(1);
    while(!rest.empty()){
        ull x = rho(rest.back());
        if(x == rest.back()){
            int freq = 0;
            for(int i = 0; i < rest.size(); i++){
                int cur_freq = 0;
                while(rest[i] % x == 0){
                    rest[i] /= x;
                    cur_freq++;
                }
                freq += cur_freq * times[i];
                if(rest[i] == 1){
                    swap(rest[i], rest.back());
                    swap(times[i], times.back());
                    rest.pop_back();
                    times.pop_back();
                    i--;
                }
            }
            while(freq--){
                answ.push_back(x);
            }
            continue;
        }
        ull e = 0;
        while(rest.back() % x == 0){
            rest.back() /= x;
            e++;
        }
        e *= times.back();
        if(rest.back() == 1){
            rest.pop_back();
			times.pop_back();
        }
        rest.push_back(x);
		times.push_back(e);
    }
    return answ;
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