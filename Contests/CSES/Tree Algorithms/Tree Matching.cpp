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
vector<bool> visited;
vector<bool> used;
vector<ii> answ;

void dfs(int u, int parent){
    visited[u] = true;
    for(auto v : g[u]){
        if(!visited[v]){
            dfs(v, u);
        }
    }
    if(!used[u] && !used[parent] && u != parent){
        answ.push_back({u,parent});
        used[u] = true;
        used[parent] = true;
    }
}

void greedily(int n){
    visited.assign(n + 1, false);
    used.assign(n + 1, false);
    dfs(0, 0);

    cout << answ.size() << '\n';
}

vector<vector<int>> dp;

int solve(int vertice, int included, int parent){
    if(dp[vertice][included] != -1) return dp[vertice][included];
    if(included == 0){
        // all my neighbors might be in the answer
        int answ = 0;
        for(auto v : g[vertice]){
            if(v != parent){
                answ += solve(v, 1, vertice);
            }
        }
        return dp[vertice][included] = answ;
    }
    else{
        // My vertex has been chosen, I need to choose a neighbor to match and include all remains
        int sum = 0;
        for(auto v : g[vertice]){
            if(v != parent){
                sum += solve(v, 1, vertice);
            }
        }
        int answ = 0;
        for(auto v : g[vertice]){
            if(v != parent){
                answ = max(answ, sum - dp[v][1] + 1 + solve(v, 0, vertice));
            }
        }
        return dp[vertice][included] = answ;
    }
}

void DP(int n){
    dp.assign(n + 1, vector<int>(2, -1));
    cout << max( solve(0, 0, 0), solve(0, 1, 0)) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;
    g.assign(n + 1, vector<int>());

    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }
    // greedily(n);
    DP(n);
    
    return 0;
}