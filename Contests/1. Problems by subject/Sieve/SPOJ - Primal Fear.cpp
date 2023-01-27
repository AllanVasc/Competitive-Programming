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

int fexpo(int x,int y){
    int answ = 1;
    while(y){
        if(y & 1) answ = answ * x;
        x = x * x;
        y >>= 1;
    }
    return answ;
}

bool afraid(int n, vector<bool> &prime){
    int backup = n;
    int digit = 0;
    while(n){
        if(n % 10 == 0) return false;
        digit++;
        n /= 10;
    }
    n = backup;
    int pot = fexpo(10, digit);
    while(n){
        if(!prime[n]) return false;
        pot /= 10;
        n %= pot;
    }
    return true;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    const int ms = 1e6 + 10;
    vector<bool> prime = sieve(ms);

    vector<int> ps_fear(ms + 10, 0);
    for(int i = 1; i <= ms; i++){
        ps_fear[i] = ps_fear[i - 1];
        if(prime[i] && afraid(i, prime)) ps_fear[i]++;
    }
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << ps_fear[n] << '\n';
    }

    return 0;
}