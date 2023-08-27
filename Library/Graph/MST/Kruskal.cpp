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
    int cntEdges = 0; // We can stop when we have n-1 edges
    sort(edges.begin(), edges.end()); // sort by weight
    initDSU(n);
    for(Edge e : edges){
        if(Find(e.u) != Find(e.v)){
            answ += e.w;
            mst.push_back(e);
            Union(e.u, e.v);
            cntEdges++;
            if(cntEdges == n - 1) break;
        }
    }
    return answ;
}

/*

Time Complexity:

kruskal -> O(E*logN)

Links:

https://cp-algorithms.com/graph/mst_kruskal.html
https://cp-algorithms.com/graph/mst_kruskal_with_dsu.html

Obs.:

1º) Para criar uma Maximum Spanning Tree podemos simplesmente dar um "reverse(edges.begin(), edges.end());"
ou caminhar pelo for no sentido contrario "for(int i = N-1; i >= 0; i--)"

*/