#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>

vector<vector<int>> g;
vector<bool> visited, cutpoint;
vector<int> discovered, low;
int timer;

void dfs(int v, int p = -1){
    visited[v] = true;
    discovered[v] = low[v] = timer;
    timer++;
    int children = 0;
    for(auto to : g[v]){
        if(to == p) continue;
        if(visited[to]) low[v] = min(low[v], discovered[to]);
        else{
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if(p != -1 && low[to] >= discovered[v]){ // Caution: Can be called multiple times for "v"
                cutpoint[v] = true;
            }
            children++;
        }
    }
    if(p == -1 && children > 1) cutpoint[v] = true;
}

void find_cutpoints(int n){
    timer = 0;
    visited.assign(n, false);
    cutpoint.assign(n, false);
    discovered.assign(n, -1);
    low.assign(n, -1);
    for(int i = 0; i < n; i++){
        if(!visited[i]) dfs(i);
    }
}

/*

Time Complexity

find_cutpoints  -> O(V + E)

Links:

https://cp-algorithms.com/graph/cutpoints.html
https://www.youtube.com/watch?v=iYJqgMKYsdI

*/