#include <bits/stdc++.h>
using namespace std;

#define int long long

using ii = pair<int,int>;

vector<vector<int>> g;
vector<bool> visited;
vector<int> discovered, low;
int timer = 0;

vector<ii> bridges;

// Tarjan's Algorithm for finding bridges in a graph
// Bridges = It's an edge which, when removed, increases the number of connected components in the graph.

/*
Note that this implementation malfunctions if the graph has multiple edges, 
since it ignores them. Of course, multiple edges will never be a part of the answer, 
so you can check additionally that the reported bridge is not a multiple edge. 
Alternatively it's possible to pass to dfs the index of the edge used to enter the vertex 
instead of the parent vertex (and store the indices of all vertices).
*/

void dfs(int v, int p = -1){
    visited[v] = true;
    discovered[v] = low[v] = timer;
    timer++;
    for(int to : g[v]){
        if(to == p) continue;
        if(visited[to]) low[v] = min(low[v], discovered[to]);
        else{
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if(low[to] > discovered[v]){    // It's a bridge
                bridges.push_back({v, to});
            }
        }
    }
}

void find_bridges(int n){
    timer = 0;
    visited.assign(n, false);
    discovered.assign(n, -1);
    low.assign(n, -1);
    for(int i = 0; i < n; i++){
        if(!visited[i]) dfs(i);
    }
}

/*

Time Complexity:

find_bridges    -> O(V + E)

Links:

https://cp-algorithms.com/graph/bridge-searching.html
https://www.youtube.com/watch?v=qrAub5z8FeA

*/