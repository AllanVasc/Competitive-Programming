#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
const int INF = 0x3f3f3f3f3f3f3f3f;

vector<vector<pii>> g; // Graph (0-based) g[u] -> (v, w)
vector<int> dist; // Shortest distances (0-Based)

// Undirected Weighted Graph
void addEdge(int u, int v, int w){
    g[u].emplace_back(v, w); 
    g[v].emplace_back(u, w); 
}

// Shortest Path Faster Algorithm (SPFA) (Single source shortest path with negative weight edges)
// SPFA is a improvement of the Bellman-Ford algorithm.
bool spfa(int src){
    int n = g.size();
    dist.assign(n, INF);

    // count[i] = # of times the distance of "i" has changed 
    // if it is greater than N-1 there's a negative cycle
    vector<int> count(n, 0);
    vector<bool> inqueue(n, false);
    queue<int> q;
    dist[src] = 0;
    q.push(src);
    inqueue[src] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        inqueue[u] = false;
        for(auto [v, w] : g[u]){
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                if(!inqueue[v]){
                    q.push(v);
                    inqueue[v] = true;
                    count[v]++;
                    if(count[v] > n) return false; // negative cycle
                }
            }
        }
    }
    return true; // There isn't negative cycle
}

/*

Time Complexity:

SPFA -> O(V*E) (In the worst case, on average it is O(E), so it's efficient)

Links:

https://cp-algorithms.com/graph/bellman_ford.html
https://www.geeksforgeeks.org/bellman-ford-algorithm-dp-23/

*/