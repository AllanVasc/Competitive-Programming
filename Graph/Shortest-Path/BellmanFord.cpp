#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 10; // Number of vertices

// Graph inplementation using Edge List (u,v,w) (0-Based)
vector<tuple<int,int,ll>> edgeList;

// Array used to keep the shortest distances (0-Based)
ll dist[N];

// Undirected Weighted Graph
void addEdge(int u, int v,ll w){
    edgeList.emplace_back(u,v,w);
    edgeList.emplace_back(v,u,w);
}

// Bellman-Ford Algorithm (Single source shortest path with negative weight edges)
bool bellmanFord(int src){

    // Initialize distances from src to all other vertices as INFINITE
    for(int i = 0; i < N; i++){
        dist[i] = LONG_LONG_MAX;
    }
    dist[src] = 0;

    // Relax all edges N - 1 times. If we're sure that we don't have
    // negative cycles, we can use a flag to stop when there isn't update
    for(int i = 0; i < N-1; i++){
        for(int j = 0; j < edgeList.size(); j++){
            int u = get<0>(edgeList[j]);
            int v = get<1>(edgeList[j]);
            ll w = get<2>(edgeList[j]);
            if(dist[u] < LONG_LONG_MAX)
                dist[v] = min(dist[v], dist[u] + w);
        }

    }

    // Check for negative-weight cycles.  The above step
    // guarantees shortest distances if graph doesn't contain
    // negative weight cycle. If we have a update, there's a negative cycle.
    for(int j = 0; j < edgeList.size(); j++){
        int u = get<0>(edgeList[j]);
        int v = get<1>(edgeList[j]);
        ll w = get<2>(edgeList[j]);
        if(dist[u] < LONG_LONG_MAX && dist[u] + w < dist[v])
            return false;
    }

    // There isn't negative cycle and our answer is in dist
    return true;
}

/*

Time Complexity

bellmanFord -> O(V*E)

Links:

https://cp-algorithms.com/graph/bellman_ford.html
https://www.geeksforgeeks.org/bellman-ford-algorithm-dp-23/

*/