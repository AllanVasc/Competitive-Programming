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

    int n;
    cin >> n;
    vector<ii> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
    }

    vector<int> sum, diff;
    for(int i = 0; i < n; i++){
        int aux = v[i].first + v[i].second;
        int aux2 = v[i].first - v[i].second;
        sum.push_back(aux);
        diff.push_back(aux2);
    }

    sort(sum.begin(), sum.end());
    sort(diff.begin(), diff.end());
    
    int answ = max(sum[n -1] - sum[0], diff[n - 1] - diff[0]);
    cout << answ << '\n';

    return 0;
}