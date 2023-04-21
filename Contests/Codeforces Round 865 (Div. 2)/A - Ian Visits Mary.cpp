#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int mod = 1e9;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;

        int x = 2, y = 2;
        while(x == 0 || y == 0 || gcd(x, y) != 1 || gcd(abs(x - a), abs(y -b)) != 1){
            x = rand() % mod;
            y = rand() % mod; 
        }

        cout << 2 << '\n';
        cout << x << " " << y << '\n';
        cout << a << " " << b << '\n';
    }
    return 0;
}