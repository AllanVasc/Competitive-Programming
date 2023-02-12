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

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string s;
    while(cin >> s){
        if(s == "*") break;

        int n = s.size();
        vector<int> divisores;
        for(int i = 1; i * i <= n; i++){
            if(n % i == 0){
                divisores.push_back(i);
                if(n / i != i) divisores.push_back(n / i);
            }
        }
        // cout << "divisores = ";
        // for(auto i : divisores) cout << i << " ";
        // cout << '\n';

        RabinKarp hash(s);
        int answ = 1;
        for(int i = 0; i < divisores.size(); i++){
            int curr_div = divisores[i];
            int curr_hash = hash.getKey(0, curr_div - 1);
            int curr_match = 1;
            for(int j = curr_div; j + curr_div <= n; j += curr_div){
                if(curr_hash == hash.getKey(j, j + curr_div - 1)) curr_match++;
            }

            if(curr_match == n / curr_div){
                answ = max(answ, curr_match);
            }
        }
        cout << answ << '\n';
    
    }

    return 0;
}