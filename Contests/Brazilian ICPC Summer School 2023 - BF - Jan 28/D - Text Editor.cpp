#include <bits/stdc++.h>
using namespace std;

// Implementation of Rabin-Karp algorithm
class RabinKarp{
    const uint64_t MOD = (1LL << 61) - 1;
    const int base = 31;
    int n;
    vector<uint64_t> h;
    vector<uint64_t> p;
 
public:
    RabinKarp(string &s){ // Initializing
        this->n = s.size();
        p.assign(n, 0);
        h.assign(n, 0);
 
        p[0] = 1;
        h[0] = getInt(s[0]);
        for(int i = 1; i < n; i++){
            p[i] = modMul(p[i-1], base);
            h[i] = (modMul(h[i-1], base) + getInt(s[i])) % MOD;
        }
    }
 
    uint64_t getKey(int l, int r){   // [l, r]
        uint64_t answ = h[r];
        if(l > 0) answ = (answ + MOD - modMul(p[r - l + 1], h[l - 1])) % MOD;
        return answ;
    }
 
private:
    uint64_t getInt(char c){
        return (uint64_t) c;
    }
 
    uint64_t modMul(uint64_t a, uint64_t b) {
        uint64_t l1 = (uint32_t)a, h1 = a >> 32, l2 = (uint32_t)b, h2 = b >> 32;
        uint64_t l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
        uint64_t ret = (l & MOD) + (l >> 61) + (h << 3) + (m >> 29) + ((m << 35) >> 3) + 1;
        ret = (ret & MOD) + (ret >> 61);
        ret = (ret & MOD) + (ret >> 61);
        return ret - 1;
    }
};

bool check(RabinKarp& hs, RabinKarp& hp, int tamanho, int qtd, int n){
    int answ = 0;
    for(int i = 0; i + tamanho <= n; i++){
        if(hs.getKey(i, i + tamanho - 1) == hp.getKey(0, tamanho - 1)) answ++;
    }

    return answ >= qtd;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s, pattern;
    getline(cin, s);
    getline(cin, pattern);

    int qtd;
    cin >> qtd;

    RabinKarp hs(s), hp(pattern);

    int left = 0, right = pattern.size();
    int answ = 0;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if( check(hs, hp, mid, qtd, s.size()) ){
            answ = mid;
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    if(answ != 0){
        cout << pattern.substr(0, answ) << '\n';
    }
    else cout << "IMPOSSIBLE" << '\n';

    return 0;
}