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

int32_t main() {
    optimize;

    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<pii> v(n);
        for(int i = 0; i < n; i++) cin >> v[i].first;
        for(int i = 0; i < n; i++) cin >> v[i].second;

        int answ = LONG_LONG_MAX;
        int cnt = 0;
        int painted = 0;
        for(int i = 0; i < n; i++){
            auto [l, r] = v[i];
            if(r - l + 1 >= 2) painted += r - l + 1;
            else cnt++;

            if(painted + cnt < k) continue;
            if(painted < k && painted + cnt >= k){
                int cost = r + 2*((i + 1 - cnt) + (k - painted));
                answ = min(answ, cost);
            }
            if(painted >= k){
                int cost = r - (painted - k) + 2*(i + 1 - cnt);
                answ = min(answ, cost);
                break;
            }
        }
        cout << (answ == LONG_LONG_MAX ? -1 : answ) << '\n';
    }
    return 0;
}