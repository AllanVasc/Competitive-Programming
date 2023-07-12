#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
const int INF = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>> g;
vector<int> lvl, dp; // dp[u] = min lvl that "u" can reach using backedge
vector<bool> cutpoint;

void dfs(int u, int p = -1){
    int children = 0;
    for(auto v : g[u]){
        if(lvl[v] == 0){ // Edge to child
            lvl[v] = lvl[u] + 1;
            dfs(v, u);
            if(dp[v] < lvl[u]){
                dp[u] = min(dp[u], dp[v]);
            }
            else if(p != -1){ // this subtree has no backedge to some "u" ancestor
                cutpoint[u] = true;
            }
            children++;
        }
        else if(lvl[v] < lvl[u]){ // Edge upwards
            dp[u] = min(dp[u], lvl[v]);
        }
    }
    if(p == -1 && children > 1) cutpoint[u] = true;
}

void find_cutpoints(int n){
    lvl.assign(n, 0);
    dp.assign(n, INF);
    cutpoint.assign(n, false);
    for(int i = 0; i < n; i++){
        if(!lvl[i]){
            lvl[i] = 1;
            dfs(i);
        }
    }
}

/*

Time Complexity

find_cutpoints  -> O(V + E)

Links:

https://codeforces.com/blog/entry/68138
https://cp-algorithms.com/graph/cutpoints.html
https://www.youtube.com/watch?v=iYJqgMKYsdI

*/