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
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        sort(ALL(v));
        int mx = 1;
        for(int i = 0; i < n; i++){
            int bcp = i + 1;
            for(int j = i + 1; j < n; j++){
                bcp = j - 1;
                if(v[j] - v[j - 1] > k){
                    break;
                }
                mx = max(mx, j - i + 1);
            }
            i = bcp;
        }
        cout << n - mx << '\n';
    }
    return 0;
}