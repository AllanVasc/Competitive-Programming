#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Edge{
    int u, v, w, id;
    Edge() {}
    Edge(int u, int v, int w = 0, int id = 0) : u(u), v(v), w(w), id(id) {}
    bool operator < (Edge & other) const { return w < other.w; }
};

// Algorithm to find the Minimum Spanning Tree of a graph
vector<Edge> boruvka(vector<Edge> & edges, int n){
    vector<Edge> mst;
    vector<Edge> best(n);
    initDSU(n); // Use Path Compression & Union-by-size/rank
    bool f = true;
    while(f){
        f = false;
        for(int i = 0; i < n; i++) best[i] = Edge(i, i, INF);
        for(auto e : edges){
            int pu = find(e.u), pv = find(e.v);
            if(pu == pv) continue;
            if(e < best[pu]) best[pu] = e;
            if(e < best[pv]) best[pv] = e;
        }
        for(int i = 0; i < n; i++){
            Edge e = best[find(i)];
            if(find(e.u) == find(e.v)) continue;
            merge(e.u, e.v);
            mst.push_back(e);
            f = true;
        }
    }
    return mst;
}

/*

Time Complexity:

boruvka -> O(logV * (V + E))

Links:

https://codeforces.com/blog/entry/77760
https://en.wikipedia.org/wiki/Bor%C5%AFvka%27s_algorithm

*/