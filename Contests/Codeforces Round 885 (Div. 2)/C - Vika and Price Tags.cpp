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

int count(int a, int b){
    // cout << "a = " << a << " b = " << b << '\n';
    if(a == 0) return 0;
    if(b < 2*a) return 1 + count(b, abs(a - b));
    int m = (b / (2*a));
    return 3*m + count(a, b - m*2*a);
}

signed main() {
    // optimize;

    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n), b(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];
        bool x = true, y = true, z = true;
        for(int i = 0; i < n; i++){
            if(a[i] == 0 && b[i] == 0) continue;
            int cnt = count(a[i], b[i]);
            x &= (cnt % 3 == 0);
            y &= (cnt % 3 == 1);
            z &= (cnt % 3 == 2);
        }
        if(x || y || z) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}