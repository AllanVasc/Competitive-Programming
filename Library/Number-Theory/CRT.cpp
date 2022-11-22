#include <bits/stdc++.h>
using namespace std;

#define int long long
using ii = pair<int,int>;

// Chinese Remainder Theorem
struct CRT{
    vector<int> a, m;
    struct GCD_type { int x, y, d; };

public:
    CRT(vector<int> remainders, vector<int> mods){
        int n = remainders.size();
        a.assign(n, 0);
        m.assign(n, 0);
        for(int i = 0; i < n; i++){
            a[i] = normalize(remainders[i], mods[i]);
            m[i] = mods[i];
        }
    }

    ii solve(){
        int n = a.size();
        int answ = a[0];
        int lcm = m[0];

        for(int i = 1; i < n; i++){
            auto gcd = ex_GCD(lcm, m[i]);
            int xi = gcd.x;
            int d = gcd.d;
            if((a[i] - answ) % d != 0) return {-1, -1}; // No solution
            answ = normalize(answ + xi * (a[i] - answ) / d % (m[i] / d) * lcm,
                             lcm * m[i] / d);
            lcm = LCM(lcm, m[i]);
        }

        return {answ, lcm}; // x = answ (mod lcm)
    }

private:
    int GCD(int a, int b){
        return (b == 0) ? a : GCD(b, a % b);
    }

    int LCM(int a, int b){
        return a / GCD(a, b) * b;
    }

    int normalize(int x, int mod){
        x %= mod;
        if(x < 0) x += mod;
        return x;
    }

    GCD_type ex_GCD(int a, int b){
        if(b == 0) return {1, 0, a};
        auto answ = ex_GCD(b, a % b);
        return {answ.y, answ.x - a / b * answ.y, answ.d};
    }
};

/*

Time Complexity

CRT ->  O(nlog(LCM(n1,n2,...,nn)))

Links:

https://cp-algorithms.com/algebra/chinese-remainder-theorem.html
https://codeforces.com/blog/entry/61290

*/