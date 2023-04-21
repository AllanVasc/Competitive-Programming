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
        int sum = 0;
        int n, m;
        cin >> n >> m;
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        for(int i = 0; i < n; i++) sum += v[i];
        cout << max(sum - m, 0LL) << '\n';
    }
    return 0;
}