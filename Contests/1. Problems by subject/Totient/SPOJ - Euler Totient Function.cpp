#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

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
    
    vector<int> phi = sievePhi(1e6 + 10);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        cout << phi[n] << '\n';
    }
    
    return 0;
}