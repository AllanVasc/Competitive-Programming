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

    int a,b;
    while(cin >> a >> b){
        auto answ = ex_GCD(a, b);
        cout << answ.x << " " << answ.y << " " << answ.d << '\n';
    }

    return 0;
}