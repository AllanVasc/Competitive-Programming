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
    
    int n, k;
    cin >> n >> k;

    vector<int> primes(k);
    for(int i = 0; i < k; i++) cin >> primes[i];

    int answ = 0;
    // Inclusion/Exclusion trick
    for(int i = 1; i < (1 << k); i++){
        int qtdBit = __builtin_popcount(i);
        int number = 1;

        int aux = i;
        int idx = 0;
        long double check = 1;
        while(aux){
            if(aux & 1){
                number *= primes[idx];
                check *= primes[idx];
            }
            if(check > n) break;
            idx++;
            aux >>= 1;
        }

        if(check > n) continue;

        if(qtdBit % 2 == 1){
            answ += (n / number);
        }
        else{
            answ -= (n / number);
        }
    }
    
    cout << answ << '\n';

    return 0;
}