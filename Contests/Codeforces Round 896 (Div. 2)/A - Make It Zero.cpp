#include <bits/stdc++.h>
using namespace std;

#define int long long
#define optimize ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define iii tuple<int,int,int>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

signed main() {
    optimize;
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        vector<pii> ops;
        ops.push_back({1, n});
        int val = 0;
        for(int i = 0; i < n; i++){
            val ^= v[i];
        }
        v.assign(n, val);
        if(n % 2){
            ops.push_back({2, n});
            ops.push_back({1, 2});
            ops.push_back({1, 2});
        }
        else{
            ops.push_back({1, n});
        }
        cout << ops.size() << '\n';
        for(auto [x, y] : ops) cout << x << " " << y << '\n';
    }
    return 0;
}