#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

typedef unsigned long long ull;

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

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        int g = gcd(a, b);
        if(g != 1){
            vector<ull> answ;
            factorize(answ, g);
            map<int,int> freq;
            for(auto x : answ){
                freq[x]++;
            }
            for(auto x : freq){
                cout << x.first << " " << x.second << '\n';
            }
        }
        cout << 0 << '\n';
    }
    return 0;
}