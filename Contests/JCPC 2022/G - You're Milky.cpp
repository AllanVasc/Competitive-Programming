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

    freopen("milk.in", "r", stdin);
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        vector<int> v(n + 1, 0);
        for(int i = 1; i <= n; i++) cin >> v[i];
        vector<int> prefixMax(n + 1, 0);
        for(int i = 1; i < n + 1; i++){
            prefixMax[i] = max(prefixMax[i - 1], v[i]);
        }
        vector<int> suffixMin(n + 1, INF);
        suffixMin[n] = v[n];
        for(int i = n - 1; i >= 0; i--){
            suffixMin[i] = min(suffixMin[i + 1], v[i]);
        }

        // for(auto x : prefixMax) cout << x << " ";
        // cout << '\n';
        // for(auto x : suffixMin) cout << x << " ";
        // cout << '\n';

        while(q--){
            int u, v;
            cin >> u >> v;
            if(u <= v){
                if(prefixMax.back() >= v) cout << "Yes" << '\n';
                else cout << "No" << '\n';
            }
            else{
                int l = 0, r = n;
                int answ = -1;
                while(l <= r){
                    int mid = (l + r) >> 1;
                    if(prefixMax[mid] >= u){
                        answ = mid;
                        r = mid - 1;
                    }
                    else{
                        l = mid + 1;
                    }
                }
                if(answ != -1 && suffixMin[answ] <= v){
                    cout << "Yes" << '\n';
                }
                else{
                    cout << "No" << '\n';
                }
            }
        }
    }
    return 0;
}