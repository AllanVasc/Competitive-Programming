#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 998244353;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    bool has_answ = true;
    for(int i = 0; i < n; i++){
        if(i == 0 && v[i] > 1) v[i] = v[i] - 1;
        if(i != 0 && v[i] > v[i - 1]) v[i] = v[i] - 1;
        if(i != 0 && v[i] < v[i - 1]) has_answ = false;
    }

    if(has_answ) cout << "Yes" << '\n';
    else cout << "No" << '\n';

    return 0;
}