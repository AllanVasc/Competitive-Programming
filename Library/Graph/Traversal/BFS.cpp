#include <bits/stdc++.h>
using namespace std;

#define int long long
vector<vector<int>> g;  // Graph (0-based)
vector<int> visited;

// Undirected Graph
void addEdge(int u, int v){
    g[u].push_back(v); 
    g[v].push_back(u); 
}

void bfsUtil(int src){
    queue<int> q;
    q.push(src);
    visited[src] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v: g[u]){
            if(visited[v]) continue;
            visited[v] = true;
            q.push(v);
        }
    }
}

// Traverse all the Graph (Disconnected Graph)
void bfs(){
    int n = g.size();
    visited.assign(n, false);
    for(int i = 0; i < n; i++){
        if(visited[i]) continue;
        bfsUtil(i);
    }
}

// This function return true with a graph is bipartite
bool isBipartite(){
    int n = g.size();
    // -1 = unvisited, 0 = black, 1 = white
    vector<int> color(n, -1);
    queue<pair<int, int>> q;
   
    // loop incase graph is not connected
    for(int i = 0; i < n; i++){
        if(color[i] != -1) continue; // Already visited
        q.push({i, 0}); // {vertex, color}
        color[i] = 0;
        while(!q.empty()){
            auto[u, c] = q.front();
            q.pop();
            for(auto v : g[u]){
                if(color[v] == c) return false;
                if(color[v] == -1){
                    color[v] = 1 - c;
                    q.push({v, color[v]});
                }
            }
        }
    }
    return true;
}

/*

Time Complexity:

addEdge     -> O(1)
bfs         -> O(V+E)
isBipartite -> O(V+E)

Links:

https://www.geeksforgeeks.org/bfs-using-stl-competitive-coding/
https://www.geeksforgeeks.org/bipartite-graph/

*/