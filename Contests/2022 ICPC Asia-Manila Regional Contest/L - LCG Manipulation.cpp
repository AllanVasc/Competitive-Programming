#include <bits/stdc++.h>
using namespace std;

#define int long long
#define optimize ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define iii tuple<int,int,int>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int ms = (1LL << 31);
const int BLOCK = sqrt(ms);

// f(x) = (a * x + b) % p

// Procurando a inversa:
// x' = (a * x + b) % p
// x' - b = a * x % p
// (x' - b) * a^-1 = x % p
// f^-1(x) = ((x - b) * a^-1) % p

// Agora temos que achar a composicao
// f(x) = (a * x + b) % p
// f(f(x)) = (a * (a * x + b) % p + b) % p
//         = (a^2 * x + a*b + b) % p
// f(f(f(x))) = (a * (a^2 * x + a*b + b) % p + b) % p
//            = (a^3 * x + a^2 * b + a*b + b) % p
// f^B(x) = a^B * x + b * (a^(B - 1) + a^(B - 2) + ... + a^0) % p
// Usando a formula da PG temos...
// f^B(x) = (a^B * x + b * (a^B - 1) * (a - 1)^-1 )% p

// Porem, quando a = 1:
// f^B(x) = a^B * x + b * B % p

int fexp(int x, int y, int m){
    int answ = 1;
    while(y){
        if(y & 1) answ = answ * x % m;
        x = x * x % m;
        y >>= 1;
    }
    return answ;
}

signed main() {
    optimize;
    int t; cin >> t;
    while(t--){
        int a, b, s, p, v;
        cin >> a >> b >> s >> p >> v;
        unordered_map<int,int> mp;
        int val = s;
        for(int i = 0; i < BLOCK; i++){
            if(mp.count(val)) break;
            mp[val] = i;
            val = (a * val % p + b % p) % p;
            val = (val + p) % p;
        }
        // f^B(x) = a^B * x + b * (a^(B - 1) + a^(B - 2) + ... + a^0) % p
        // f^B(x) = (a^B * x + b * (a^B - 1) * (a - 1)^-1 )% p
        // Porem, quando a = 1:
        // f^B(x) = a^B * x + b * B % p
        const int aPowB = fexp(a, BLOCK, p);
        const int pg = (((aPowB - 1 + p) % p * fexp(a - 1, p - 2, p) % p) + p) % p;
        const int invA = fexp(a, p - 2, p);
        mp.erase(s);
        val = s;
        int cnt = 0;
        while(mp.count(val) == 0){
            mp[val] = cnt * BLOCK;
            cnt++;
            if(a == 1) val = (aPowB * val % p + b * BLOCK % p) % p;
            else val = ((aPowB * val % p) + (b * pg % p)) % p;
            val = (val + p) % p;
        }
        // Using inverse to find closest
        int curr = v;
        int answ = -1;
        for(int i = 0; i <= BLOCK; i++){ 
            // f^-1(x) = ((x - b) * a^-1) % p
            if(mp.count(curr)){
                answ = mp[curr] + i;
                break;
            }
            curr = (curr - b + p) % p * invA % p;
            curr = (curr + p) % p;
        }
        cout << (answ == -1 ? "IMPOSSIBLE" : to_string(answ)) << '\n';
    }
    return 0;
}