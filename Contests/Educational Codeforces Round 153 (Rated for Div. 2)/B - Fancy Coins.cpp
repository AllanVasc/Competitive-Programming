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
        int m, k, a, b;
        cin >> m >> k >> a >> b;
        int answ = 0;
        if(m % k){
            int missing = m - (k * (m / k));
            m -= missing;
            // cout << "missing = " << missing << '\n';
            // cout << "m = " << m << '\n';
            if(a >= missing){
                a -= missing;
                missing = 0;
            }
            else{
                // a < missing
                missing -= a;
                a = 0;
            }
            answ += missing;
        }
        // m eh multiplo de "b"
        m = max(0LL, m - (b * k));
        b = 0;
        int block = a / k;

        m = max(0LL, m - k * block);
        cout << answ + m / k << '\n';
    }
    return 0;
}