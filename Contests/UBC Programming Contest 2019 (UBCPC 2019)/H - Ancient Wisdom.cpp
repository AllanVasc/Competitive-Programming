#include <bits/stdc++.h>
using namespace std;
 
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
    for(; b; b >>= 1, a = mul(a,a, mod))
        if(b & 1) answ = mul(answ, a, mod);
    return answ;
}
 
bool witness(ull a, ull k, ull q, ull n){
    ull t = mpow(a, q, n);
    if(t == 1 || t == n - 1) return false;
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
    for(ull a : test){
        if(n == a) return true;
        if(witness(a, k, q, n)) return false;
    }
    return true;
}
 
ull pollard_rho(ull n, ull c){
    ull x = 2, y = 2, i = 1, k = 2, d;
    while(1){
        x = (mul(x,x,n) + c);
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
 
int32_t main(){
 
    ull n;
    cin >> n;
 
    vector<ull> answ;
    factorize(answ, n);
 
    // cout << "factor: ";
    // for(auto i : answ){
    //     cout << i << " ";
    // }
    // cout << '\n';
 
    map<ull, ull> freq;
    for(auto i : answ){
        freq[i]++;
    }
 
    ull resp = 1;
    for(auto i : freq){
        if(i.second % 2 == 1){
            resp *= i.first;
        }
    }
 
    cout << resp << '\n';
 
    return 0;
}