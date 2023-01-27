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
        for(int i = 0; i < n; i++) cin >> v[i];

        sort(v.begin(), v.end(), greater<int>());

        int ps = v[0];
        bool valid = true;
        for(int i = 1; i < n && valid; i++){
            if(ps == v[i]){
                int idx = i + 1;
                valid = false;
                for(; idx < n; idx++){
                    if(v[i] != v[idx]){
                        swap(v[i], v[idx]);
                        valid = true;
                        break;
                    }
                }
            }
            ps += v[i];
        }

        if(!valid){
            cout << "NO" << '\n';
        }
        else{
            cout << "YES" << '\n';
            for(int i = 0; i < n; i++){
                cout << v[i] << " ";
            }
            cout << '\n';
        }
    }

    return 0;
}