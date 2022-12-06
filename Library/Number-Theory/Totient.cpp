#include <bits/stdc++.h>
using namespace std;

#define int long long

// Euler's totient function for one number
int phi(int n){
    int answ = n;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            while(n % i == 0) n /= i;
            answ -= answ / i;
        }
    }
    if(n > 1) answ -= answ / n;
    return answ;
}

// Euler's totient function from 1 to n
vector<int> sievePhi(int n){
    vector<int> phi(n + 1);
    for(int i = 0; i <= n; i++) phi[i] = i;
    for(int i = 2; i <= n; i++){
        if(phi[i] == i){
            for(int j = i; j <= n; j += i){
                phi[j] -= phi[j] / i;
            }
        }
    }
    return phi;
}

/*

Time Complexity

phi ->  O(sqrt(n))
sievePhi    -> O(n*log(log(n)))

Links:

https://cp-algorithms.com/algebra/phi-function.html

*/