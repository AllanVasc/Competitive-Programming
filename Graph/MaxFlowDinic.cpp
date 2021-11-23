#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Struct to represent the Residual Network
struct FlowEdge {
    int u,v;
    ll cap, flow = 0;
    FlowEdge (int u, int v, ll cap) : u(u), v(v), cap(cap) {}
};

// Dinic's Algorithm to find the Max Flow of a graph
struct Dinic {
    const ll flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;    // Graph inplementation using Adjacency List, here will be saved the index for mapping in "edges"
    int n, m = 0;               // n = number of vertices and m = number of edges
    int s, t;                   // s = source and t = sink
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int u, int v, ll cap){
        edges.emplace_back(u, v, cap);
        edges.emplace_back(v, u, 0);
        adj[u].push_back(m);
        adj[v].push_back(m + 1);
        m += 2;
    }

    // Construct the Augmenting Level Path
    bool bfs(){
        while (!q.empty()){
            int u = q.front();
            q.pop();
            for (int id : adj[u]){
                if (edges[id].cap - edges[id].flow < 1)  // This edge is already using maximum flow
                    continue;
                if (level[edges[id].v] != -1)            // I've already visited this vertex
                    continue;
                level[edges[id].v] = level[u] + 1;
                q.push(edges[id].v);
            }
        }
        return level[t] != -1;
    }

    // Find path Source -> Sink
    ll dfs(int u, ll pushed){
        if (pushed == 0)
            return 0;
        if (u == t)
            return pushed;
        for (int& cid = ptr[u]; cid < (int)adj[u].size(); cid++){
            int id = adj[u][cid];
            int v = edges[id].v;
            if (level[u] + 1 != level[v] || edges[id].cap - edges[id].flow < 1)
                continue;
            ll tr = dfs(v, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    ll flow(){
        ll maxFlow = 0;
        while (true){
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (ll pushed = dfs(s, flow_inf)){
                maxFlow += pushed;
            }
        }
        return maxFlow;
    }
};

/*

Time Complexity

Dinic   -> O(V²E)

Links:

https://www.geeksforgeeks.org/ford-fulkerson-algorithm-for-maximum-flow-problem/
https://www.youtube.com/watch?v=oHy3ddI9X3o
https://cp-algorithms.com/graph/edmonds_karp.html
https://cp-algorithms.com/graph/dinic.html
https://www.youtube.com/watch?v=M6cm8UeeziI
https://www.youtube.com/watch?v=duKIzgJQ1w8

*/