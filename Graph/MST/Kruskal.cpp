// Kruskal's algorithm uses Disjoint Set, it's necessary to include to use the functions "Find" and "Union"
// See in "/Data-Structures/DisjointSetUnion.cpp"

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 10; // Number of vertex

// Structure to symbolize a weighted edge
struct Edge {
    int u, v, w;
    bool operator<(Edge const& other) {
        return w < other.w;
    }
};

// Graph inplementation using Edge List (u,v,w) (0-Based)
vector<Edge> edges;

// Vector responsible for keeping the edges used to build the MST
vector<Edge> mst;

// Kruskal's Algorithm for Minimum Spanning Tree using Disjoint Set (Returns the cost to build the MST)
ll kruskal(){

    ll cost = 0;

    // We can stop the algorithm when we have N-1 edges
    int cntEdges = 0;

    // Will sort edges by weight
    sort(edges.begin(), edges.end());

    for (Edge e : edges) {
        if (Find(e.u) != Find(e.v)) {
            cost += e.w;
            mst.push_back(e);
            Union(e.u, e.v);
            cntEdges++;
            if(cntEdges == N-1)
                break;
        }
    }

    return cost;
}

/*

Time Complexity

kruskal -> O(E*logN)

Disjoint Set Union Functions

Build   -> O(N)
Find    -> O(logN) ( In the worst case, the average case is O(1) )
Union   -> O(logN) ( In the worst case, the average case is O(1) )

Links:

https://cp-algorithms.com/graph/mst_kruskal.html
https://cp-algorithms.com/graph/mst_kruskal_with_dsu.html

Obs.: 

1º) Para criar uma Maximum Spanning Tree podemos simplesmente dar um "reverse(edges.begin(), edges.end());"
ou caminhar pelo for no sentido contrário "for(int i = N-1; i >= 0; i--)"

*/