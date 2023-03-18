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
    // ios::sync_with_stdio(false);
    // cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        int l = 0;
        int r = n - 1;
        int mn = 1, mx = n;
        vector<bool> inSeg(n + 5, true);
        while(l < r){
            if(v[l] != mn && v[l] != mx &&
               v[r] != mx && v[r] != mn) break;
            // cout << "l = " << l + 1 << " r = " << r + 1 << '\n';
            // cout << "min = " << mn << " max = " << mx << '\n';
            if(v[l] == mn || v[l] == mx){
                inSeg[v[l]] = false;
                while(!inSeg[mn]) mn++;
                while(!inSeg[mx]) mx--;
                l++;
            }
            if(v[r] == mn || v[r] == mx){
                inSeg[v[r]] = false;
                while(!inSeg[mn]) mn++;
                while(!inSeg[mx]) mx--;
                r--;
            }
        }
        if(l >= r) cout << -1 << '\n';
        else cout << l + 1 << " " << r + 1 << "\n";
    }
    return 0;
}