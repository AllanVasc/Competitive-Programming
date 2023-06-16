#include <bits/stdc++.h>
using namespace std;

#define int long long
#define optimize ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define iii tuple<int,int,int>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

vector<pair<int,int>> factorize(int x){
    vector<pair<int,int>> factor;
    for(int i = 2; i * i <= x; i++){
        int exp = 0;
        while(x % i == 0){
            x /= i;
            exp++;
        }
        if(exp) factor.push_back({i, exp});
    }
    if(x > 1) factor.push_back({x, 1});
    return factor;
}

int lcm(int x, int y){
    return x / gcd(x, y) * y;
}

int fexp(int x, int y){
    int answ = 1;
    while(y){
        if(y & 1) answ *= x;
        x *= x;
        y >>= 1;
    }
    return answ;
}

struct GCD_type { int x, y, d; };
GCD_type ex_GCD(int a, int b){
    if(b == 0) return {1, 0, a};
    auto answ = ex_GCD(b, a % b);
    return {answ.y, answ.x - a / b * answ.y, answ.d};
}

int32_t main() {
    optimize;
    
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    int currLcm = 1;
    for(int i = 0; i < n; i++){
        currLcm = lcm(currLcm, v[i]);
    }
    vector<pii> factor = factorize(2 * currLcm);
    int qttF = factor.size();
    // for(auto [x, exp] : factor){
    //     cout << x << "^" << exp << " ";
    // }
    // cout << '\n';
    int answ = INF;
    for(int mask = 0; mask < (1 << qttF); mask++){
        int a = 1, b = 1;
        for(int i = 0; i < qttF; i++){
            if(mask & (1 << i)){
                a *= fexp(factor[i].first, factor[i].second);
            }
            else{
                b *= fexp(factor[i].first, factor[i].second);
            }
        }
        // check
        // seja t = a*x e t + 1 = b*y
        // b*y = a*x + 1
        // b*y - a*x = 1
        // Queremos o menor t = a*x
        // cout << "a = " << a << " b = " << b << '\n';
        GCD_type extended = ex_GCD(a, -b);
        int val1 = a * extended.x;
        int val2 = b * extended.y;
        // cout << "extended: " << extended.x << " " << extended.y << " " << extended.d << '\n';
        if(extended.d != 1) continue;
        if(extended.y > 0 && extended.x > 0){
            answ = min(answ, val2);
        }
    }
    cout << answ << '\n';
    return 0;
}