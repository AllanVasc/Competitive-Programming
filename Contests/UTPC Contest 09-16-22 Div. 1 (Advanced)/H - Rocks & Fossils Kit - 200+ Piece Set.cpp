#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int MAXN = 1e5 + 10; 
int dp[MAXN];

void build(int n){
    for(int i = 0; i < n; i++){
        dp[i] = -1;
    }
}

int solve(int idx, int n, vector<pair<int,int>>& window){
    if(idx > n) return 0;

    if(dp[idx] != -1) return dp[idx];

    int answ = 0;
    pair<int,int> curr = {idx, 0};
    auto next_idx = lower_bound(window.begin(), window.end(), curr);

    // cout << "idx atual: " << idx << " lower bound achou window:" << next_idx->first << " : " << next_idx->second << '\n';

    if(next_idx == window.end()){
        return dp[idx] = answ;
    }

    answ = max( solve(idx + 1 , n, window), 1 + solve(next_idx->second + 1, n, window) );

    return dp[idx] = answ;
}

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    vector<int> values;
    values.assign(n, 0);
    for(int i = 0; i < n; i++) cin >> values[i];

    vector<int> start_idx;
    start_idx.assign(m, 0);
    for(int i = 0; i < m; i++) cin >> start_idx[i];

    vector<int> total_necessary;
    total_necessary.assign(m, 0);
    for(int i = 0; i < m; i++) cin >> total_necessary[i];

    vector<int> ps;
    ps.push_back(0);
    for(int i = 1; i <= n; i++){
        ps.push_back(ps[i-1] + values[i-1]);
    }

    vector<pair<int,int>> window;
    for(int i = 0; i < m; i++){
        auto idx = lower_bound(ps.begin(), ps.end(), total_necessary[i] + ps[start_idx[i]-1]);
        if(idx != ps.end())
            window.push_back({start_idx[i], idx - ps.begin()});
    }
    // cout << "janelas:\n";
    // for(int i = 0; i < window.size(); i++){
    //     cout << "start: " << window[i].first << " end: " << window[i].second << '\n';
    // }

    sort(window.begin(), window.end());
    build(n + 1);

    cout << solve(1, n + 1, window) << '\n';
    return 0;
}