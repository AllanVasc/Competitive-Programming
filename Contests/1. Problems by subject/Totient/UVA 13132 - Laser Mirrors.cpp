#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

// Euler's totient function from 1 to n
vector<int> sievePhi(int n){
    vector<int> phi(n + 1);
    for(int i = 0; i <= n; i++) phi[i] = i;
    for(int i = 2; i <= n; i++){
        if(phi[i] == i){
            for(int j = i; j <= n; j += i){
                phi[j] -= phi[j] / i;
            }
        }
    }
    return phi;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    const int ms = 1e5 + 100;
    vector<int> phi = sievePhi(ms);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n == 1) cout << 0 << '\n';
        else cout << phi[n] << '\n';
    }
    return 0;
}