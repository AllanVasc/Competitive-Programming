#include <bits/stdc++.h>
using namespace std;

#define int long long
#define optimize ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define iii tuple<int,int,int>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

vector<int> dp;
vector<vector<int>> v;
// dp[idx]
int solve(int idx){
    int n = v.size();
    if(idx >= n) return 0;
    int & answ = dp[idx];
    if(answ != INF) return answ;
    for(int i = 1; i < v[idx].size(); i++){
        answ = min(answ, v[idx][0] - v[idx][i] + solve(idx + i));
    }
    return answ;
}

int32_t main() {
    optimize;
    
    int n, m; 
    cin >> n >> m;
    v.assign(n, vector<int>());
    for(int i = 0; i < n; i++){
        int mn = min(m, n - (i + 1) + 1) + 1;
        v[i].assign(mn, 0);
        for(int j = 0; j < mn; j++){
            cin >> v[i][j];
            // cout << v[i][j] << " ";
        }
        // cout << '\n';
    }

    dp.assign(n + 10, INF);
    int answ = solve(0);
    cout << answ << '\n';
    return 0;
}