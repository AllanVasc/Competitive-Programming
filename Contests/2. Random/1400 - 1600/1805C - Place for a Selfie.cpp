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

int sq(int x){
    return x * x;
}

signed main() {
    optimize;
    int t; cin >> t;
    while(t--){
        int n, m; 
        cin >> n >> m;
        vector<int> line(n);
        for(int i = 0; i < n; i++) cin >> line[i];
        sort(line.begin(), line.end());

        for(int i = 0; i < m; i++){
            int a, b, c;
            cin >> a >> b >> c;
            int ind = lower_bound(line.begin(), line.end(), b) - line.begin();
            if(ind < n && sq(b - line[ind]) < 4 * a * c){
                cout << "YES" << '\n';
                cout << line[ind] << '\n';
                continue;
            }
            if(ind > 0 && sq(b - line[ind - 1]) < 4 * a * c){
                cout << "YES" << '\n';
                cout << line[ind - 1] << '\n';
                continue;
            }
            cout << "NO" << '\n';
        }
    }
    return 0;
}