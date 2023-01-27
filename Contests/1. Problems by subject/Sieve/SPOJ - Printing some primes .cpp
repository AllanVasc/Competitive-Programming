#include <bits/stdc++.h>
using namespace std;
  
#define int long long
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

// Sieve of Eratosthenes
vector<bool> sieve(int n){
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;
    for(int i = 2; i * i <= n; i++){
        if(prime[i]){
            for(int j = i * i; j <= n; j += i){
                prime[j] = false;
            }
        }
    }
    return prime;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    vector<bool> crivo = sieve(1e8);
    vector<int> primes;
    for(int i = 0; i < crivo.size(); i++) if(crivo[i]) primes.push_back(i);
    for(int i = 1; i < primes.size(); i+=100){
        cout << primes[i - 1] << '\n';
    }

    return 0;
}