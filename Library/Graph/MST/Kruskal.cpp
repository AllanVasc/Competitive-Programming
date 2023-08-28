#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Edge{
    int u, v, w, id;
    Edge() {}
    Edge(int u, int v, int w = 0, int id = 0) : u(u), v(v), w(w), id(id) {}
    bool operator < (Edge & other) const { return w < other.w; }
};
vector<Edge> edges, mst;

// Kruskal's Algorithm for Minimum Spanning Tree using DSU (Returns the cost to build the MST)
int kruskal(int n){
    int answ = 0;
    sort(edges.begin(), edges.end()); // sort by weight
    initDSU(n);
    for(Edge e : edges){
        if(find(e.u) == find(e.v)) continue;
        answ += e.w;
        mst.push_back(e);
        merge(e.u, e.v);
        if(mst.size() == n - 1) break;
    }
    return answ;
}

/*

Time Complexity:

kruskal -> O(E*logN)

Links:

https://cp-algorithms.com/graph/mst_kruskal.html
https://cp-algorithms.com/graph/mst_kruskal_with_dsu.html

*/