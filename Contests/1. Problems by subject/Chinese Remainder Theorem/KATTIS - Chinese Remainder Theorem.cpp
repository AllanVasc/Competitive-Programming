#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

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

        // x = answ (mod lcm)
        return {answ, lcm};
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

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        vector<int> remainders(2), mods(2);
        cin >> remainders[0] >> mods[0] >> remainders[1] >> mods[1];
        CRT chinese(remainders, mods);

        ii answ = chinese.solve();
        if(answ.first == -1) cout << "no solution" << '\n';
        else{
            cout << answ.first << " " << answ.second << '\n';
        }
    }
    
    return 0;
}