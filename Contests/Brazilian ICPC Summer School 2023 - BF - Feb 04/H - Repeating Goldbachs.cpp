#include <bits/stdc++.h>
using namespace std;

#define int long long 

vector<bool> is_prime;

vector<int> sieve(int n){
    is_prime.assign(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i * i <= n; i++){
        if(is_prime[i]){
            for(int j = i * i; j <= n; j += i){
                is_prime[j] = false;
            }
        }
    }
    vector<int> primes;
    for(int i = 0; i <= n; i++){
        if(is_prime[i]) primes.push_back(i);
    }
    return primes;
}

const int MAXN = 1e6 + 100;
int32_t main(){
    
    int x;
    cin >> x;

    vector<int> primes = sieve(MAXN);
    int steps = 0;
    while(x >= 4){
        steps++;
        // cout << x << '\n';
        for(int i = 0; i < primes.size(); i++){
            if(is_prime[x - primes[i]]){
                x = (x - primes[i]) - primes[i];
                break;
            }
        }
    }
    
    cout << steps << '\n';
    return 0;
}