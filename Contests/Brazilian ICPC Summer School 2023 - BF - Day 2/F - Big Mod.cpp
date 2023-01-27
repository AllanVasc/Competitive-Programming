#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int fexp(int x, int y, int m){
    int answ = 1;
    x = x % m;
    while(y){
        if(y & 1) answ = answ * x % m;
        x = x * x % m;
        y >>= 1;
    }
    return answ;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int b, p ,m;
    while(cin >> b >> p >> m){
        cout << fexp(b,p,m) << '\n';
    }
    return 0;
}