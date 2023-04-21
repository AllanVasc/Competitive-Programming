#include <bits/stdc++.h>
using namespace std;

#define int long long
#define optimize ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ALL(x) x.begin(), x.end()
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define iii tuple<int,int,int>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int32_t main() {
    optimize;
    
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n;
        vi v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        cin >> m;
        vi b(m);
        for(int i = 0; i < m; i++) cin >> b[i];
        int sum = 0;
        for(int i = 0; i < m; i++){
            sum += b[i];
            sum %= n;
        }
        cout << v[sum] << '\n';
    }
    return 0;
}