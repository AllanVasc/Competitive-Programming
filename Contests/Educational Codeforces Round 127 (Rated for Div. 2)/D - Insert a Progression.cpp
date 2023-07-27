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
        int n, x;
        cin >> n >> x;
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        int mn = v[0];
        int mx = v[0];
        int answ = 0;
        for(int i = 0; i < n; i++){
            mn = min(mn, v[i]);
            mx = max(mx, v[i]);
            if(i) answ += abs(v[i] - v[i - 1]);
        }
        answ += min(2 * (mn - 1), min(v[0], v[n - 1]) - 1);
        if(x > mx){
            answ += min(2 * (x - mx), x - max(v[0], v[n - 1]));
        }
        cout << answ << '\n';
    }
    return 0;
}