#include <bits/stdc++.h>
using namespace std;
  
#define int long long

// LCA using Euler Tour technique to reduce in a RMQ problem.

const int ms = 2*1e5 + 100;
vector<vector<int>> g;
vector<int> euler;
int depth[ms], first[ms];
vector<int> seg; // After dfs, initialize with 4 * euler.size()

// We put in the crossing a certain vertex whenever we pass by it
void dfs(int u, int p = -1){
    first[u] = euler.size();
    euler.push_back(u);
    for(auto v : g[u]){
        if(v == p) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
        euler.push_back(u);
    }
}

// Using a segmentation tree to answer the RMQ
// Obs.: We can use a Sparse Table to query in O(1)

// Call using build(1, 0, euler.size() - 1)
void build(int p, int l, int r){
    if(l == r){
        seg[p] = euler[l];
    }
    else{
        int m = (l + r) / 2;
        int lc = 2*p;
        int rc = lc + 1;

        build(lc, l, m);
        build(rc, m + 1, r);
        
        int vl = seg[lc];
        int vr = seg[rc];
        seg[p] = (depth[vl] < depth[vr]) ? vl : vr;
    }
}

int query(int p, int l, int r, int ql, int qr){
    if(l >= ql && r <= qr){
        return seg[p];
    }
    else{
        int m = (l + r) / 2;
        int lc = 2*p;
        int rc = lc + 1;

        if(qr <= m) return query(lc, l, m, ql, qr);
        else if(ql > m) return query(rc, m + 1, r, ql, qr);

        int vl = query(lc, l, m, ql, qr);
        int vr = query(rc, m + 1, r, ql, qr);
        
        return (depth[vl] < depth[vr]) ? vl : vr;
    }
}

int lca(int u, int v){
    int l = first[u];
    int r = first[v];
    if(l > r) swap(l, r);
    return query(1, 0, euler.size() - 1, l, r);
}

/*

Time Complexity:

dfs     -> O(V + E)
build   -> O(n)
query   -> O(logn)

Links:

https://cp-algorithms.com/graph/lca.html

*/