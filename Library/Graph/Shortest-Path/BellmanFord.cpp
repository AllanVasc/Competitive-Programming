#include <bits/stdc++.h>
using namespace std;

#define int long long

// Graph inplementation using Edge List (u,v,w) (0-Based)
vector<tuple<int,int,int>> edgeList;
vector<int> dist;

// Bellman-Ford Algorithm (Single source shortest path with negative weight edges)
// Returns true if valid answer exists.
bool bellmanFord(int src, int n){
    const int INF = 0x3f3f3f3f3f3f3f3f;
    const int NINF = -INF; 
    dist.assign(n, INF);
    dist[src] = 0;

    // Relax all edges n - 1 times. If we're sure that we don't have
    // negative cycles, we can use a flag to stop when there isn't update
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < edgeList.size(); j++){
            auto [u, v, w] = edgeList[j];
            if(dist[u] == INF) continue;
            dist[v] = min(dist[v], dist[u] + w);
            dist[v] = max(dist[v], NINF);
        }
    }

    // Check the existence of a negative cycle. If you have only one update we can return true.
    // We perform n - 1 steps to check if the cycle affects a specific node.
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < edgeList.size(); j++){
            auto [u, v, w] = edgeList[j];
            if(dist[u] == INF) continue;
            if(dist[u] + w < dist[v]) dist[v] = NINF; // We can only return false here
        }
    }

    // There isn't negative cycle and our answer is in dist
    // change to "return dist[node] != NINF" to verify a specific node.
    return true;
}

/*

Time Complexity:

bellmanFord -> O(V*E)

Links:

https://cp-algorithms.com/graph/bellman_ford.html
https://www.geeksforgeeks.org/bellman-ford-algorithm-dp-23/

*/