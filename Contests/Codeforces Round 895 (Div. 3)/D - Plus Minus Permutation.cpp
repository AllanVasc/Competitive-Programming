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
        int n, x, y;
        cin >> n >> x >> y;
        int lcm = x / gcd(x, y) * y;
        int qttx = n / x;
        int qtty = n / y;
        int qttBoth = n / lcm;

        int sumx = (n - qttx + 1 + qttBoth + n) * (qttx - qttBoth) / 2;
        int sumy = (1 + qtty - qttBoth) * (qtty - qttBoth) / 2;
        // cout << sumx << " " << sumy << '\n';
        cout << sumx - sumy << '\n';
    }
    return 0;
}