#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
const int INF = 0x3f3f3f3f3f3f3f3f;

vector<vector<pii>> g; // Graph (0-based) g[u] -> (v, w)

// Undirected Weighted Graph
void addEdge(int u, int v, int w){
    g[u].emplace_back(v, w); 
    g[v].emplace_back(u, w); 
}

// Prim's Algorithm for Minimum Spanning Tree (Returns the cost to build the MST)
int prim(int src){
    int n = g.size();
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> costs(n, INF);
    costs[src] = 0;
    vector<int> parent(n, -1); // Store MST
    vector<bool> inMST(n, false);
    pq.emplace(0, src); // {w, u}
    int answ = 0;
    while(!pq.empty()){
        auto [wt, u] = pq.top();
        pq.pop();
        if(inMST[u] == true) continue;
        inMST[u] = true;
        answ += wt;
        for(auto [v, w] : g[u]){
            if(inMST[v] == false && costs[v] > w){
                costs[v] = w;
                pq.emplace(w, v);
                parent[v] = u;
            }
        }
    }
    /*
    // Print edges of MST using parent array (We start from 1 because the parent of the source is -1)
    for (int i = 1; i < N; ++i)
        printf("%d - %d\n", parent[i], i);
    */
    return answ;
}