#include <bits/stdc++.h>
using namespace std;

#define int long long
#define optimize ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ALL(x) x.begin(), x.end()
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define iii tuple<int,int,int>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD1 = 1e9 + 7;
const int MOD2 = 1e9 + 9;

const int ms = 5*1e5 + 10;
int hsS1[ms], hsS2[ms];
int hsX1[ms], hsX2[ms];
int pw1[ms], pw2[ms];
string s, sx;

int z[2*ms];

void hashS(int n){
    pw1[0] = 1;
    pw2[0] = 1;
    hsS1[0] = (s[0] - '0') % MOD1;
    hsS2[0] = (s[0] - '0') % MOD2;
    for(int i = 1; i < n; i++){
        pw1[i] = pw1[i - 1] * 10 % MOD1;
        pw2[i] = pw2[i - 1] * 10 % MOD2;
        hsS1[i] = ((hsS1[i - 1] * 10 % MOD1) + s[i] - '0') % MOD1;
        hsS2[i] = ((hsS2[i - 1] * 10 % MOD2) + s[i] - '0') % MOD2;
    }
}

void hashX(int n){
    pw1[0] = 1;
    pw2[0] = 1;
    hsX1[0] = (sx[0] - '0') % MOD1;
    hsX2[0] = (sx[0] - '0') % MOD2;
    for(int i = 1; i < n; i++){
        pw1[i] = pw1[i - 1] * 10 % MOD1;
        pw2[i] = pw2[i - 1] * 10 % MOD2;
        hsX1[i] = ((hsX1[i - 1] * 10 % MOD1) + sx[i] - '0') % MOD1;
        hsX2[i] = ((hsX2[i - 1] * 10 % MOD2) + sx[i] - '0') % MOD2;
    }
}

pii getKeyS(int l, int r){
    pii answ = {hsS1[r], hsS2[r]};
    if(l > 0) answ = {(answ.first - (pw1[r - l + 1] * hsS1[l - 1] % MOD1) + MOD1) % MOD1,
                      (answ.second - (pw2[r - l + 1] * hsS2[l - 1] % MOD2) + MOD2) % MOD2};
    return answ;
}

pii getKeyX(int l, int r){
    pii answ = {hsX1[r], hsX2[r]};
    if(l > 0) answ = {(answ.first - (pw1[r - l + 1] * hsX1[l - 1] % MOD1) + MOD1) % MOD1,
                      (answ.second - (pw2[r - l + 1] * hsX2[l - 1] % MOD2) + MOD2) % MOD2};
    return answ;
}

pii sumPair(pii a, pii b){
    return {(a.first + b.first) % MOD1, (a.second + b.second) % MOD2};
}

void Z(string s){
    int l = 0, r = 0;
    int n = s.size();
    for(int i = 1; i < n; i++){ // Z-function
        if(i <= r){
            z[i] = min(r - i + 1, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if(i + z[i] - 1 > r){
            l = i;
            r = i + z[i] - 1;
        }
    }
}

void printAnsw(int i, int j, int k, int l){
    cout << i << " " << j << '\n';
    cout << k << " " << l << '\n';
}

int32_t main() {
    optimize;
    
    cin >> s >> sx;
    int n = s.size();
    int m = sx.size();
    // cout << "n = " << n << '\n';
    // cout << "m = " << m << '\n';
    hashS(n);
    hashX(m);

    pii valX = getKeyX(0, m - 1);
    
    // 1 opcao
    for(int i = 0; i + 2*(m - 1) - 1 < n; i++){
        pii answ = sumPair(getKeyS(i, i + m - 2), getKeyS(i + m - 1, i + m - 1 + m - 2));
        // cout << "check = " << "[" << i << "," << i + m - 2 << "] + [" << i + m - 1 << "," << i + m - 1 + m - 2 << "]\n";
        if(answ == valX){
            printAnsw(i + 1, i + m - 2 + 1, i + m - 1 + 1, i + m - 1 + m - 2 + 1);
            return 0;
        }
    }

    // 2 opcao
    Z(sx + "#" + s);
    for(int i = 0; i + m - 1 < n; i++){
        int lcp = z[m + i + 1];
        // check: m - lcp
        int sz1 = m - lcp;
        if(sz1 > 0){
            if(i - sz1 >= 0){
                pii answ = sumPair(getKeyS(i - sz1, i - 1), getKeyS(i, i + m - 1));
                if(answ == valX){
                    printAnsw(i - sz1 + 1, i - 1 + 1, i + 1, i + m - 1 + 1);
                    return 0;
                }
            }
            if(i + m + sz1 - 1 < n){
                pii answ = sumPair(getKeyS(i, i + m - 1), getKeyS(i + m, i + m + sz1 - 1 ));
                if(answ == valX){
                    printAnsw(i + 1, i + m - 1 + 1, i + m + 1, i + m + sz1 - 1 + 1);
                    return 0;
                }
            }
        }
        // check2 = m - lcp - 1
        int sz2 = m - lcp - 1;
        if(sz2 > 0){
            if(i - sz2 >= 0){
                pii answ = sumPair(getKeyS(i - sz2, i - 1), getKeyS(i, i + m - 1));
                if(answ == valX){
                    printAnsw(i - sz2 + 1, i - 1 + 1, i + 1, i + m - 1 + 1);
                    return 0;
                }
            }
            if(i + m + sz2 - 1 < n){
                pii answ = sumPair(getKeyS(i, i + m - 1), getKeyS(i + m, i + m + sz2 - 1 ));
                if(answ == valX){
                    printAnsw(i + 1, i + m - 1 + 1, i + m + 1, i + m + sz2 - 1 + 1);
                    return 0;
                }
            }
        }
    }
    assert(false);
    return 0;
}