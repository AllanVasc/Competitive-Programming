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
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> v(m);
        for(int i = 0; i < m; i++) cin >> v[i];
        if(k > m){
            cout << "NO" << '\n';
        }
        else{
            sort(ALL(v));
            int blocks = (n + k - 1) / k;
            int equal = 0;
            for(int i = 0; i < m; i++){
                if(v[i] == blocks) equal++;
            }
            bool possible = true;
            if(v.back() > blocks || equal > (n - 1) % k + 1) possible = false;
            cout << (possible ? "YES" : "NO") << '\n';
        }
    }
    return 0;
}