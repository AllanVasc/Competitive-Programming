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
        int n, m;
        cin >> n >> m;
        vector<int> close(n + 1, n + 1);
        for(int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;
            if(a < b) swap(a, b);
            //a > b
            close[b] = min(close[b], a);
        }
        vector<int> mn(n + 1, n);
        for(int i = n - 1; i >= 1; i--){
            mn[i] = min(close[i] - 1, mn[i + 1]);
        }
        int answ = 0;
        for(int i = 1; i <= n; i++){
            answ += mn[i] - i + 1;
        }
        cout << answ << '\n';
    }
    return 0;
}