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
        int n, x1, y1, x2, y2;
        cin >> n >> x1 >> y1 >> x2 >> y2;
        if(x1 > n/2) x1 = n - x1 + 1;
        if(y1 > n/2) y1 = n - y1 + 1;
        if(x2 > n/2) x2 = n - x2 + 1;
        if(y2 > n/2) y2 = n - y2 + 1;

        // cout << x1 << " " << y1 << '\n';
        // cout << x2 << " " << y2 << '\n';
        int first = min(x1, y1);
        int second = min(x2, y2);

        cout << abs(first - second) << '\n';
    }
    return 0;
}