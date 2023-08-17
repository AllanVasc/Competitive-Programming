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
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        vector<pii> aux;
        for(int i = 0; i < n; i++){
            if(v[i] > k){
                int x = (v[i] - k) / k + 1;
                if(v[i] % k == 0) x--;
                v[i] -= x*k;
            }
            // cout << v[i] << " ";
            aux.push_back({v[i], -(i + 1)});
        }
        // cout << '\n';
        sort(aux.rbegin(), aux.rend());
        // cout << "answ = " << '\n';
        for(auto [x, y] : aux){
            cout << abs(y) << " ";
        }
        cout << '\n';

    }
    return 0;
}