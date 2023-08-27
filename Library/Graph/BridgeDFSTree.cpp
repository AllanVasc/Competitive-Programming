#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>

vector<vector<int>> g;
vector<int> lvl, dp; // dp[u] = number of edges that traverses (parent[u], u)
vector<pii> bridges;

void dfs(int u, int p = -1){
    dp[u] = 0;
    for(auto v : g[u]){
        if(lvl[v] == 0){ // Edge to child
            lvl[v] = lvl[u] + 1;
            dfs(v, u);
            dp[u] += dp[v];
        }
        else if(lvl[v] < lvl[u]){ // Edge upwards
            dp[u]++;
        }
        else if(lvl[v] > lvl[u]){ // Edge downwards
            dp[u]--;
        }
    }
    if(p != -1) dp[u]--;    // Parent edge isn't a back-edge
    if(p != -1 && dp[u] == 0){  // (p, u) It's a bridge
        bridges.push_back({p, u});
    }
}

void find_bridges(int n){
    lvl.assign(n, 0);
    dp.assign(n, 0);
    for(int i = 0; i < n; i++){
        if(!lvl[i]){
            lvl[i] = 1;
            dfs(i);
        }
    }
}

/*

Time Complexity:

find_bridges    -> O(V + E)

Links:

https://codeforces.com/blog/entry/68138

*/