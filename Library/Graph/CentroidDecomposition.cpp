#include <bits/stdc++.h>
using namespace std;
  
#define int long long

const int MAXN = 1e5;

vector<int> g[MAXN];
int dist[MAXN][30]; // Distance from the nodes to the centroid (represented by the level)
int parent[MAXN], sz[MAXN], removed[MAXN], height[MAXN];

// Preprocessing subtree sizes
void dfsSubtree(int u, int p){
    sz[u] = 1;
    for(auto v : g[u]){
        if(v != p && !removed[v]){
            dfsSubtree(v, u);
            sz[u] += sz[v];
        }
    }
}

// For each subtree we find its centroid
int getCentroid(int u, int p, int curr_size){
    for(auto v : g[u]){
        if(v != p && !removed[v] && sz[v] * 2 >= curr_size){
            return getCentroid(v, u, curr_size);
        }
    }
    return u;
}

// For each node, we calculate its distance
// to the centroid (represented by the level)
void setDist(int u, int p, int lvl){
    for(auto v : g[u]){
        if(v == p || removed[v]) continue;
        dist[v][lvl] = dist[u][lvl] + 1;
        setDist(v, u, lvl);
    }
}

// Algorithm to perform Centroid Decomposition
void decompose(int u, int p = -1, int lvl = 0){
    dfsSubtree(u, -1);
    int ctr = getCentroid(u, -1, sz[u]);
    parent[ctr] = p;
    height[ctr] = lvl;  // Assigning a level to the centroid
    removed[ctr] = 1;
    setDist(ctr, p, lvl);
    for(auto v : g[ctr]){
        if(v != p && !removed[v]){
            decompose(v, ctr, lvl + 1);
        }
    }
}

/*

Time Complexity

decompose   -> O(nlogn)

Links:

https://www.quora.com/profile/Abbas-Rangwala-13/Centroid-Decomposition-of-a-Tree
https://medium.com/carpanese/an-illustrated-introduction-to-centroid-decomposition-8c1989d53308
https://www.youtube.com/watch?v=-DmMLQCmz94
https://usaco.guide/plat/centroid?lang=cpp

*/