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
    
    int p, n;
    cin >> p >> n;

    vector<int> v(n + 1);
    for(int i = 0; i < n + 1; i++) cin >> v[i];
    reverse(v.begin(), v.end());

    for(int i = 0; i <= p * p ; i++){
        int sum = v[0] % (p * p);
        int x_exp = 1;
        for(int j = 1; j <= n; j++){
            x_exp *= i;
            x_exp %= (p * p);
            sum += (v[j] * x_exp);
            sum %= (p * p);
        }
        if(sum % (p * p) == 0){
            cout << i << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
    return 0;
}