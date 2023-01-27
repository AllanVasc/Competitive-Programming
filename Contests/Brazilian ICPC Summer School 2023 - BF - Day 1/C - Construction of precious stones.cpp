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

    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    
    vector<int> answ(k + 1, INF);
    answ[0] = v[0];
    int prefix_sum = v[0];
    int curr_sum = v[0];
    for(int i = 1; i < k; i++){
        if(i < n) answ[i] = min(v[i], curr_sum);
        else{
            answ[i] = curr_sum;
        }
        prefix_sum += answ[i];
        curr_sum += prefix_sum;
    }

    cout << answ[k - 1] % MOD << '\n';
    return 0;
}