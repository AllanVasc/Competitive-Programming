#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 10; // Number of vertex

// Graph inplementation using Adjacency List ( adj[u] -> (v,w) ) (0-Based)
vector<pair<int,ll>> adj[N];

// Undirected Weighted Graph
void addEdge(int u, int v,ll w){
    adj[u].emplace_back(v,w); 
    adj[v].emplace_back(u,w); 
}

// Prim's Algorithm for Minimum Spanning Tree (Returns the cost to build the MST)
ll prim(){

    //Min Heap
    priority_queue< pair<ll,int> , vector <pair<ll,int>> , greater<pair<ll,int>> > pq;

    // Taking vertex 0 as source
    int src = 0;

    // Cost to build the MST
    ll wMST = 0;

    // Create a vector for costs and initialize all costs as infinite
    vector<ll> costs(N, LONG_LONG_MAX);
 
    // To store parent array which in turn store MST
    vector<int> parent(N, -1);
 
    // To keep track of vertices included in MST
    vector<bool> inMST(N, false);
 
    // Insert source in priority queue and initialize its costs as 0 (w,u)
    pq.emplace(0, src);
    costs[src] = 0;

    while (!pq.empty()){

        // Extracting the minimum costs vertex
        int u = pq.top().second;
        pq.pop();

        // If the vertex hasn't been added, it is necessary to add the cost to reach it
        if(inMST[u] == false){
            wMST += costs[u];
        }

        // Include vertex in MST (Took the shortest path possible to get to it)
        inMST[u] = true;

        // Get all adjacent vertices of "u"
        for(auto i : adj[u]){
            int v = i.first;
            ll w = i.second;

            // "v" isn't in MST and weight of (u,v) is smaller than current costs of "v"
            if(inMST[v] == false && costs[v] > w){
                // Updating weight to "v" (Is a possible edge that i can put in the MST)
                costs[v] = w;
                pq.emplace(costs[v],v);
                parent[v] = u;
            }
        }
    }
    
    /*

    // Print edges of MST using parent array (We start from 1 because the parent of the source is -1)

    for (int i = 1; i < N; ++i)
        printf("%d - %d\n", parent[i], i);

    */ 
   
    return wMST;
}

/*

Time Complexity

prim    -> O(E*logN)

Links:

https://www.geeksforgeeks.org/prims-algorithm-using-priority_queue-stl/
https://cp-algorithms.com/graph/mst_prim.html

Obs.: 

1º) Para criar uma Maximum Spanning Tree utilizamos uma Max Heap (priority queue), 
definimos o infinito como "LONG_LONG_MIN" e trocamos a linha 61 para "if(inMST[v] == false && costs[v] < w)"

*/