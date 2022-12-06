#include <bits/stdc++.h>
using namespace std;

#define int long long

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

/*

Time Complexity

sieve   ->  O(n*log(log(n)))

Links:

https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html

*/