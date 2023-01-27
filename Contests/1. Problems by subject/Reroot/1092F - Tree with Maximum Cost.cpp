#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

vector<vector<int>> g;
vector<int> values;

vector<int> dp, subansw;
int answ;

void precalc(int u, int parent){
    subansw[u] = values[u];
    for(auto v : g[u]){
        if(v != parent){
            precalc(v, u);
            subansw[u] += subansw[v];
            dp[u] += subansw[v] + dp[v];
        }
    }
}

void dfs(int u, int parent){ // Reroot
    answ = max(answ, dp[u]);
    for(auto v : g[u]){
        if(v != parent){
            int newcost = dp[u] - dp[v] - subansw[v];
            dp[v] += newcost + subansw[u] - subansw[v];
            subansw[v] = subansw[u];
            dfs(v, u);
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;
    g.assign(n + 1, vector<int>());
    values.assign(n, 0);
    for(int i = 0; i < n; i++) cin >> values[i];
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }

    dp.assign(n, 0);
    subansw.assign(n, 0);

    precalc(0, 0);
    dfs(0,0);
    
    cout << answ << '\n';

    return 0;
}