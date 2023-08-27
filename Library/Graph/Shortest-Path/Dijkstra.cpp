#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
const int INF = 0x3f3f3f3f3f3f3f3f;

vector<vector<pii>> g; // Graph (0-based) g[u] -> (v, w)
vector<int> dist; // Shortest distances (0-Based)
vector<int> predecessors; // Need to re-construct path (0-Based)

// Undirected Weighted Graph
void addEdge(int u, int v, int w){
    g[u].emplace_back(v, w); 
    g[v].emplace_back(u, w); 
}

// Dijkstra Algorithm (Single-source shortest paths problem)
void dijkstra(int src){
    int n = g.size();
    dist.assign(n, INF);
    predecessors.assign(n, -1);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, src}); // {Weight, vertex}
    dist[src] = 0;
    while(!pq.empty()){
        auto [d, u] = pq.top();
        pq.pop();
        if(dist[u] < d) continue;
        for(auto [v, w] : g[u]){
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
                predecessors[v] = u;
            }
        }
    }
}

/*

Time Complexity:

dijkstra -> O(E*LogV)

Links:

https://cp-algorithms.com/graph/dijkstra.html
https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/

*/