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

vector<int> dp, dist;
vector<int> answ;

void precalc(int u, int parent){
    for(auto v : g[u]){
        if(v != parent){
            precalc(v, u);
            dist[u] = max(dist[u], 1 + dist[v]);
            dp[u] = max(dp[u], dist[u]);
        }
    }
}

void dfs(int u, int parent){
    answ[u] = dp[u];
    ii best1 = {-1, -1};
    ii best2 = {-1, -1};
    for(auto v : g[u]){
        if(dp[v] >= best1.second){
            best2 = best1;
            best1 = {v, dp[v]};
        }
        else if(dp[v] > best2.second){
            best2 = {v, dp[v]};
        }
    }
    int backupU = dp[u];
    for(auto v : g[u]){
        int backupV = dp[v];
        if(v != parent){
            if(v != best1.first){
                dp[v] = max(dp[v], 1 + dp[u]);
            }
            else{
                dp[v] = max(dp[v], 2 + best2.second);
                dp[u] = max(0LL, 1 + best2.second);
            }

            dfs(v, u);
            dp[u] = backupU;
            dp[v] = backupV;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;
    g.assign(n + 1, vector<int>());
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }

    dp.assign(n, 0);
    dist.assign(n, 0);
    answ.assign(n, 0);
    precalc(0, 0);
    dfs(0,0);

    for(auto i : answ){
        cout << i << " ";
    }
    cout << '\n';

    return 0;
}