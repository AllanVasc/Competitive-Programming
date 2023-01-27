#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int ms = 200000 + 100;
int dp[ms];

static bool f(iii& a, iii& b){
    auto [starta, enda, rewarda] = a;
    auto [startb, endb, rewardb] = b;
    return enda < endb;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;
    vector<iii> v;
    for(int i = 0; i < n; i++){
        int start, end, reward;
        cin >> start >> end >> reward;
        v.emplace_back(start, end, reward);
    }
    sort(v.begin(), v.end(), f);
    map<int, int> mp;
    mp[0] = 0;
    for(int i = 1; i <= n; i++){
        auto [start, end, reward] = v[i - 1];
        dp[i] = dp[i - 1];
        auto itr = mp.lower_bound(start);
        itr = prev(itr);
        dp[i] = max(dp[i], reward + itr->second);
        mp[end] = dp[i];
    }

    cout << dp[n] << '\n';
    return 0;
}