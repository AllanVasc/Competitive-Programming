#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];

        int g = v[0];
        for(int i = 1; i < n; i++){
            g = __gcd(g, v[i]);
        }

        if(g == 1){
            cout << 0 << '\n';
        }
        else if(__gcd(g, n) == 1){
            cout << 1 << '\n';
        }
        else if(__gcd(g, n - 1) == 1) {
            cout << 2 << '\n';
        }
        else{
            cout << 3 << '\n';
        }
    }

    return 0;
}