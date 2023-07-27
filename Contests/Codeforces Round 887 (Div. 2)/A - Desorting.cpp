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
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        int dif = INF;
        for(int i = 1; i < n; i++){
            dif = min(dif, v[i] - v[i - 1]);
        }
        if(dif < 0){
            cout << 0 << '\n';
        }
        else{
            // cout << "dif = " << dif << '\n';
            cout << dif/2 + 1 << '\n';
        }
    }
    return 0;
}