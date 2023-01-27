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

        vector<int> v;
        v.assign(n, 0);
        for(int i = 0; i < n; i++) cin >> v[i];

        int minn = 1e10;
        for(int i = 1; i < n; i++){
            if(v[i] < minn) minn = v[i];
        }

        if(v[0] > minn) cout << "Alice" << '\n';
        else cout << "Bob" << '\n';
    }
    return 0;
}