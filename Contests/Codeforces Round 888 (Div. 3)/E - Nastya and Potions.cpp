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
vector<int> cost;
vector<vector<int>> rules;
set<int> unlimited;
int solve(int idx){
    int & answ = dp[idx];
    if(answ != INF) return answ;
    answ = cost[idx];
    if(rules[idx].size()){
        int sum = 0;
        for(int i = 0; i < rules[idx].size(); i++){
            sum += solve(rules[idx][i]);
        }
        answ = min(answ, sum);
    }
    return answ;
}

signed main() {
    optimize;
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        cost.assign(n + 1, 0);
        for(int i = 1; i <= n; i++){
            cin >> cost[i];
        }
        dp.assign(n + 5, INF);
        vector<int> inStock(m);
        for(int i = 0; i < m; i++){
            cin >> inStock[i];
            dp[inStock[i]] = 0;
        }
        rules.assign(n + 1, vector<int>());
        for(int i = 1; i <= n; i++){
            int qtt;
            cin >> qtt;
            for(int j = 0; j < qtt; j++){
                int curr;
                cin >> curr;
                rules[i].push_back(curr);
            }
        }
        
        for(int i = 1; i <= n; i++){
            cout << solve(i) << " ";
        }
        cout << '\n';
    }
    return 0;
}