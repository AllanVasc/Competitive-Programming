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
        vector<int> v(n);
        int total2 = 0;
        for(int i = 0; i < n; i++){
            cin >> v[i];
            if(v[i] == 2) total2++;
        }

        int cnt = 0;
        bool found = false;
        for(int i = 0; i < n - 1 && !found; i++){
            if(v[i] == 2) cnt++;
            if(cnt == total2 - cnt){
                cout << i + 1 << '\n';
                found = true;
            }
        }
        if(!found) cout << -1 << '\n';
    }
    
    return 0;
}