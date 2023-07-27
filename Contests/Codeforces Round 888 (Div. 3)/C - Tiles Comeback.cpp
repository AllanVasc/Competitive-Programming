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
        vector<int> start;
        vector<int> en;
        for(int i = 0; i < n; i++){
            if(v[i] == v[0]){
                start.push_back(i);
            }
            if(v[i] == v[n - 1]){
                en.push_back(i);
            }
        }
        bool possible = false;
        if(v[0] == v[n - 1]){
            if(start.size() >= k) possible = true;
        }
        else{
            for(int i = 0; i < start.size(); i++){
                auto pos = lower_bound(en.begin(), en.end(), start[i]) - en.begin();
                if(i + 1 >= k && (en.size() - pos) >= k){
                    possible = true;
                }
            }
        }
        cout << (possible ? "YES" : "NO") << '\n';
    }
    return 0;
}