#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 10; // Number of vertices

// Graph inplementation using Adjacency List ( adj[u] -> (v,w) ) (0-Based)
vector<pair<int,ll>> adj[N];

// Vector used to keep the shortest distances (0-Based)
vector<ll> dist;

// Undirected Weighted Graph
void addEdge(int u, int v,ll w){
    adj[u].emplace_back(v,w); 
    adj[v].emplace_back(u,w); 
}

// Shortest Path Faster Algorithm (SPFA) (Single source shortest path with negative weight edges)
// SPFA is a improvement of the Bellman-Ford algorithm.
bool spfa(int src){

    // Initialize distances from src to all other vertices as INFINITE
    dist.assign(N, LONG_LONG_MAX);

    // Counts the number of times the distance has changed 
    // (if it is greater than N-1 there is a negative cycle)
    vector<int> count(N, 0);

    // If a vertex is already in the queue, there is no need to put it back
    vector<bool> inqueue(N, false);
    queue<int> q;

    dist[src] = 0;
    q.push(src);
    inqueue[src] = true;

    // Takes advantage of the fact that not all attempts at relaxation will work.
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inqueue[u] = false;

        for (auto i : adj[u]) {

            int v = i.first;
            ll w = i.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                if (!inqueue[v]) {
                    q.push(v);
                    inqueue[v] = true;
                    count[v]++;
                    if (count[v] > N)
                        return false;  // negative cycle
                }
            }
        }
    }

    // There isn't negative cycle and our answer is in dist
    return true;
}

/*

Time Complexity

SPFA -> O(V*E) (In the worst case, on average it is O(E), so it's efficient)

Links:

https://cp-algorithms.com/graph/bellman_ford.html
https://www.geeksforgeeks.org/bellman-ford-algorithm-dp-23/

*/