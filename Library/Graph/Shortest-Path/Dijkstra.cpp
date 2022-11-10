#include <bits/stdc++.h>
using namespace std;

#define int long long
using ii = pair<int,int>;
const int INF = 0x3f3f3f3f3f3f3f3f;
int n = 10; // Number of vertices

// Graph inplementation using Adjacency List ( adj[u] -> (v,w) ) (0-Based)
vector<vector<ii>> adj;

// Vector used to keep the shortest distances (0-Based)
vector<int> dist;

// Vector used to re-construct path (0-Based)
vector<int> predecessors;

// Undirected Weighted Graph
void addEdge(int u, int v, int w){
    adj[u].emplace_back(v,w); 
    adj[v].emplace_back(u,w); 
}

// Dijkstra Algorithm (Single-source shortest paths problem)
void dijkstra(int src){

    // Initialize distances from src to all other vertices as INFINITE
    dist.assign(n, INF);

    // Initialize all predecessors to -1
    predecessors.assign(n, -1);

    //Min Heap
    priority_queue<ii, vector<ii>, greater<ii>> pq;

    // Insert source in priority queue (Weight,vertex)
    pq.push({0, src});
    dist[src] = 0;

    while(!pq.empty()){

        // The first vertex in pq is the minimum distance vertex
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if(dist[u] < d) continue;

        // Get all adjacent vertex of "u" 
        for(auto i : adj[u]){

            // Current adjacent vertex of "u"
            int v = i.first;
            int w = i.second;
  
            // If there is shorted path to v through u.
            if(dist[v] > dist[u] + w){

                // Updating distance of v
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});

                // Updating predecessors of v
                predecessors[v] = u;
            }
        }
    }
}

/*

Time Complexity

dijkstra -> O(E*LogV)

Links:

https://cp-algorithms.com/graph/dijkstra.html
https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/

*/