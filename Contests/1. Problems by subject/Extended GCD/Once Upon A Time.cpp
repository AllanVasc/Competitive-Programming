#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

// Extended Euclidean Algorithm
struct GCD_type { int x, y, d; };
GCD_type ex_GCD(int a, int b){
        if(b == 0) return {1, 0, a};
        auto answ = ex_GCD(b, a % b);
        return {answ.y, answ.x - a / b * answ.y, answ.d};
}

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a, k;
    while(cin >> n >> m >> a >> k){
        if(n == m && m == a && a == k && n == 0) return 0;

        auto gcd = ex_GCD(a, -m); 

        int dif = n - k;

        if( dif % gcd.d != 0){
            cout << "Impossible" << '\n';
        }
        else{
            
            if(gcd.d < 0){
                gcd.x *= -1;
                gcd.y *= -1;
                gcd.d *= -1;
            }

            int x0 = gcd.x * (dif/gcd.d);
            int y0 = gcd.y * (dif/gcd.d);

            // All possible solution
            // ax + by = c
            // x = x0 + k*(b/gcd)
            // y = y0 - k*(a/gcd)

            int d = m / gcd.d;

            if(x0 <= 0){
                int coef = (abs(x0) / d) + 1; // first that's positive
                x0 += d * coef;
            }
            else{
                int coef = (x0 - 1) / d; // first occurrence
                x0 -= d * coef;
            }

            cout << k + a * x0 << '\n';
        }

    }
    return 0;
}