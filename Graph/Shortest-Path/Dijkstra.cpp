#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 10; // Number of vertices

// Graph inplementation using Adjacency List ( adj[u] -> (v,w) ) (0-Based)
vector<pair<int,ll>> adj[N];

// Vector used to keep the shortest distances (0-Based)
vector<ll> dist;

// Vector used to re-construct path (0-Based)
vector<int> predecessors;

// Undirected Weighted Graph
void addEdge(int u, int v,ll w){
    adj[u].emplace_back(v,w); 
    adj[v].emplace_back(u,w); 
}

// Dijkstra Algorithm (Single-source shortest paths problem)
void dijkstra(int src){

    // Initialize distances from src to all other vertices as INFINITE
    dist.assign(N, LONG_LONG_MAX);

    // Initialize all predecessors to -1
    predecessors.assign(N, -1);

    //Min Heap
    priority_queue< pair<ll,int> , vector <pair<ll,int>> , greater<pair<ll,int>> > pq;

    // Insert source in priority queue (Weight,vertex)
    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty()){

        // The first vertex in pq is the minimum distance vertex
        int u = pq.top().second;
        pq.pop();
  
        // Get all adjacent vertex of "u" 
        for (auto i : adj[u]){

            // Current adjacent vertex of "u"
            int v = i.first;
            ll w = i.second;
  
            // If there is shorted path to v through u.
            if (dist[v] > dist[u] + w){

                // Updating distance of v
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));

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