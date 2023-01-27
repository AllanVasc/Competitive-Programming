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
        int l, n;
        cin >> l >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        sort(v.begin(), v.end());

        int menor = 0;
        for(int i = 0; i < n; i++){
            int best = min(v[i] - 0, l - v[i]);
            menor = max(menor, best);
        }

        int maior = 0;
        maior = max( max(v[0], l - v[0]), max(v[n - 1], l - v[n - 1]));

        cout << menor << " " << maior << '\n';
    }
    return 0;
}