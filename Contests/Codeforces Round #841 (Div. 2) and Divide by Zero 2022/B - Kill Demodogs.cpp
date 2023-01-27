#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int fexp(int x, int y){
    x = x % MOD;
    int answ = 1;
    while(y){
        if( y & 1) answ = answ * x % MOD;
        x = x * x % MOD;
        y >>= 1;
    }
    return answ;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        int answ = ((((337 * n % MOD * (n + 1) % MOD * (2 * n + 1) % MOD) + ((337 * n % MOD * (n - 1) % MOD * (2 * n - 1) % MOD + MOD) % MOD)) % MOD) + (1011 * n % MOD * (n - 1) % MOD)) % MOD;
        cout << answ << '\n';
    }
    return 0;
}