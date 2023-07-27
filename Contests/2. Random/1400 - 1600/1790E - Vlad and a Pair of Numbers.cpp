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
        int x; 
        cin >> x;
        int a = x, b = 0;
        for(int i = 31; i >= 0; i--){
            if(x & (1LL << i)) continue;
            if(2*x - a - b >= 2 * (1LL << i)){
                a += (1LL << i);
                b += (1LL << i);
            }
        }
        if((a ^ b == x) && (a + b == 2 * x)){
            cout << a << " " << b << '\n';
        }
        else cout << -1 << '\n';
    }
    return 0;
}