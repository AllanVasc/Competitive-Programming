#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

vector<int> v;

int solve(int idx, int sum_a, int sum_b){
    int n = v.size();
    if(idx == n){
        return abs(sum_a - sum_b);
    }
    return min(solve(idx + 1, sum_a + v[idx], sum_b),
                solve(idx + 1, sum_a, sum_b + v[idx]));
}

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    v.assign(n, 0 );
    for(int i = 0; i < n; i++) cin >> v[i];

    cout << solve(0,0,0) << '\n';

    return 0;
}