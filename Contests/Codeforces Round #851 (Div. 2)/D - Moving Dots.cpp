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

    vector<int> pw2(3000 + 10, 1);
    for(int i = 1; i < pw2.size(); i++){
        pw2[i] = pw2[i - 1] * 2 % MOD;
    }
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());

    int answ = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int left = lower_bound(v.begin(), v.end(), v[i] - (v[j] - v[i])) - v.begin();
            int right = v.end() - lower_bound(v.begin(), v.end(), v[j] + v[j] - v[i]);
            answ += pw2[left + right];
            answ %= MOD;
        }
    }
    
    cout << answ << '\n';
    return 0;
}