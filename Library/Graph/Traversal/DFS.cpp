#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<vector<int>> g; // Graph (0-based)
vector<int> visited;

// Undirected Graph
void addEdge(int u, int v){
    g[u].push_back(v); 
    g[v].push_back(u); 
}

void dfsUtil(int u){
    visited[u] = true; 
    for(auto v : g[u]){
        if(visited[v]) continue;
        dfsUtil(v);
    }
}

// Traverse all the Graph (Disconnected Graph)
void dfs(){
    int n = g.size();
    visited.assign(n, false);
    for(int i = 0; i < n; i++){
        if(visited[i]) continue;
        dfsUtil(i);
    }
}

/*

Time Complexity:

addEdge -> O(1)
dfs     -> O(V+E)

Links:

https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/
https://www.geeksforgeeks.org/graph-implementation-using-stl-for-competitive-programming-set-1-dfs-of-unweighted-and-undirected/

*/