#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n == 3){
            cout << "NO" << '\n';
        }
        else if(n % 2 != 0){
            cout << "YES" << '\n';
            int offset = (n - 5)/2;

            for(int i = 0; i < n; i++){
                if(i % 2 == 0) cout << 1 + offset << " ";
                else cout << -1*(1 + offset + 1) << " ";
            }
            cout << '\n';
        }
        else{
            cout << "YES" << '\n';
            for(int i = 0; i < n; i++){
                if(i % 2 == 0) cout << 1 << " ";
                else cout << -1 << " ";
            }
            cout << '\n';
        }
    }
    return 0;
}