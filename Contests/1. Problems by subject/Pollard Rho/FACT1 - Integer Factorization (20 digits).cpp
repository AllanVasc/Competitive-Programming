// 
#include <bits/stdc++.h>
using namespace std;
  
#define int long long
  
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

typedef __int128 ull;
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
            c = rand() % n;
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

// Returns all the factors of n
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

ull read() {
    ull x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
void print(ull x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}
bool cmp(ull x, ull y) { return x > y; }

int32_t main(){
  
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    
    ull n;
    n = read();
    while(n != 0){
        vector<ull> answ = factors(n);
        map<ull, int> freq;
        set<ull> unique;
        for(int i = 0; i < answ.size(); i++){
            freq[answ[i]]++;
            unique.insert(answ[i]);
        }
        for(auto i : unique){
            print(i);
            printf("^%llu ", freq[i]);
        }
        printf("\n");
        n = read();
    }
    return 0;
}