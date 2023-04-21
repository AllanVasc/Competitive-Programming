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
    
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.rbegin(), v.rend());
    vector<int> ps(n + 1, 0);
    ps[0] = 0;
    for(int i = 1; i <= n; i++) ps[i] = ps[i - 1] + v[i - 1];
    while(q--){
        int x, y;
        cin >> x >> y;
        int answ = ps[x] - ps[x - y];
        cout << answ << '\n';
    }
    return 0;
}