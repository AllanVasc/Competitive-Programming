#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5+10; // Number of vertex

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

    // Create a vector for costs and initialize all costs as infinite and source as 0
    vector<ll> costs(N, LONG_LONG_MAX);
    costs[src] = 0;
 
    // To store parent array which in turn store MST
    vector<int> parent(N, -1);
 
    // To keep track of vertices included in MST
    vector<bool> inMST(N, false);
 
    // Insert source in priority queue (w,u)
    pq.emplace(0, src);

    while (!pq.empty()){

        // Extracting the minimum costs vertex
        int u = pq.top().second;
        ll wt = pq.top().first;
        pq.pop();

        // If the vertex has already been added there is no need to continue
        if(inMST[u] == true) continue;

        // Include vertex in MST (Took the shortest path possible to get to it)
        inMST[u] = true;
        wMST += wt;

        // Get all adjacent vertices of "u"
        for(auto i : adj[u]){
            int v = i.first;
            ll w = i.second;
            
            // "v" isn't in MST and weight of (u,v) is smaller than current costs of "v"
            if(inMST[v] == false && costs[v] > w){
                // Updating weight to "v" (Is a possible edge that i can put in the MST)
                costs[v] = w;
                pq.emplace(w,v);
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