#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 0x3f3f3f3f3f3f3f3f;

// Returns minimum "x" for which a^x % m = b % m , (gcd(a, m) = 1)
// Returns "INF" if there is no solution
// 0^0 = 1 is assumed here
int discreteLog(int a, int b, int m){
    a %= m, b %= m;
    int block = sqrt(m) + 1, an = 1;
    for(int i = 0; i < block; i++) an = an * a % m;
    map<int,int> vals;
    for(int q = 0, cur = b; q <= block; q++){ // b*a^q % m
        vals[cur] = q;
        cur = cur * a % m;
    }
    int answ = INF;
    for(int p = 1, cur = 1; p <= block; p++){
        cur = cur * an % m; // a^(block*p)
        if(vals.count(cur)){ // a^(block*p) % m = b*a^q % m
            answ = min(answ, block*p - vals[cur]);
            // return answ; // This value is already the minimum
        }
    }
    return answ;
}

// gcd(a, m) != 1
int discreteLog(int a, int b, int m){
    a %= m, b %= m;
    int k = 1, add = 0, g;
    while((g = gcd(a, m)) > 1){ // log^2(m) preprocess
        if(b == k) return add;
        if(b % g) return INF;
        b /= g, m /= g, add++;
        k = (k * a / g) % m;
    }
    int block = sqrt(m) + 1, an = 1;
    for(int i = 0; i < block; i++) an = an * a % m;
    map<int,int> vals;
    for(int q = 0, cur = b; q <= block; q++){
        vals[cur] = q;
        cur = cur * a % m;
    }
    int answ = INF;
    for(int p = 1, cur = k; p <= block; p++){
        cur = cur * an % m;
        if(vals.count(cur)){
            answ = min(answ, block*p - vals[cur] + add);
            // return answ; // This value is already the minimum
        }
    }
    return answ;
}

/*

Time Complexity:

discreteLog -> O(sqrt(m) * log(m))
discreteLog -> O(log^2(m) + sqrt(m) * log(m))

Links:

https://cp-algorithms.com/algebra/discrete-log.html
https://en.wikipedia.org/wiki/Baby-step_giant-step

*/