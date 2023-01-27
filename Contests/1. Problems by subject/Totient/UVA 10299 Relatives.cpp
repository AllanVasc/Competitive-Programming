#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int phi(int n){
    int answ = n;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            while(n % i == 0) n /= i;
            answ -= answ / i;
        }
    }
    if(n > 1) answ -= answ / n;
    return answ;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n;
    while(cin >> n && n != 0){
        if(n == 1) cout << 0 << '\n';
        else cout << phi(n) << '\n';
    }
    
    return 0;
}