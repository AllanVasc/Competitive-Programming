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
        bool answ = true;
        int xv, yv;
        cin >> xv >> yv;
        for(int i = 0; i < k; i++){
            int x, y;
            cin >> x >> y;
            int dist = abs(xv - x) + abs(yv - y);
            if(dist % 2 == 0){
                answ = false;
            }
        }
        cout << (answ ? "YES" : "NO") << '\n';
    }
    return 0;
}