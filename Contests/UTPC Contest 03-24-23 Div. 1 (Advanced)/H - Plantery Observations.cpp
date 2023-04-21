#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

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
    uint64_t getInt(char c){ // Attention: leave the subtraction if there are only letters
        return c + 1;
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


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    string s = "";
    while(n--){
        int cmd;
        cin >> cmd;
        if(cmd == 0){
            string plus;
            cin >> plus;
            for(int i = 0; i < plus.size(); i++){
                s.push_back(plus[i]);
            }
        }
        else{
            RabinKarp h1(s);
            for(int i = 0; i < s.size(); i++){
                bool ok = true;

                for(int j = 0; j < s.size(); j += (i + 1)){
                    if(j + (i + 1) - 1 < s.size()){
                        if(h1.getKey(j, j + (i + 1) - 1) != h1.getKey(0, i)) ok = false;
                    }
                    else{
                        if(h1.getKey(j, s.size() - 1) != h1.getKey(0, s.size() - j - 1)) ok = false;
                    }
                }

                if(ok){
                    cout << (i + 1) << '\n';
                    break;
                }
            }
        }
    }
    return 0;
}