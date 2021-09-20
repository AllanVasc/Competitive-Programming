#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2000; // Number of vertices

// Graph inplementation using Adjacency List (0-Based)
vector<int> adj[N];

// Implementation of a Recursive Segment Tree (1-Based) {Node,Height} (Min Operation)
vector<pair<ll,ll>> segTree;

// Vector to save the Euler tour (1-Based)
vector<ll> euler;

// Auxiliary vectors
vector<ll> height, first;
vector<bool> visited;

// Call using build(1,1,N) (N = v.size() - 1)
void build_SegTree(int p, int l, int r){

    // Building Leaf
    if(l == r){
        segTree[p] = {euler[r], height[euler[r]]};
    }
    else{

        int m = (l+r)/2;
        int lc = 2*p;
        int rc = lc + 1;

        // Building Left Children
        build_SegTree(lc, l, m);

        // Building Rigth Children
        build_SegTree(rc, m+1, r);
        
        // Building Node (Min Operation) 
        segTree[p] = (segTree[lc].second < segTree[rc].second) ? segTree[lc] : segTree[rc];
    }
}

// Call using query(1,1,N,ql,qr) (ql and qr need to be 1-Based)
pair<ll,ll> query_SegTree(int p, int l, int r, int ql, int qr){

    // This node is inside the range answer
    if(ql <= l && r <= qr){
        return segTree[p];
    }
    else{

        int m = (l+r)/2;
        int lc = 2*p;
        int rc = lc + 1;

        // Our answer is just in the Left Children
        if(qr <= m){

            return query_SegTree(lc,l,m,ql,qr);
        }
        // Our answer is just in the Rigth Children
        else if(ql > m){

            return query_SegTree(rc,m+1,r,ql,qr);
        }
        else{

            // Our answer is an intersection of the 2 sides
            return (query_SegTree(lc,l,m,ql,qr).second < query_SegTree(rc,m+1,r,ql,qr).second) ? query_SegTree(lc,l,m,ql,qr) : query_SegTree(rc,m+1,r,ql,qr);
        }
    }
}

// Make the Euler Tour of the tree
void dfs(ll node, ll h){

    visited[node] = true;
    height[node] = h;
    first[node] = euler.size();

    euler.push_back(node);

    for(auto u : adj[node]){
        if(!visited[u]){
            dfs(u, h+1);
            euler.push_back(node);  // We need to put it on when we come back
        }
    }
}

// Function to build the SegTree to be used in the LCA
void build_LCA(ll root){

    height.resize(N);   // Setting up
    height.push_back(-1);
    first.resize(N);

    euler.reserve(N * 2);
    euler.push_back(-1);    // 1-Based

    visited.assign(N, false);

    dfs(root, 0);   // Making Euler Tour of the Tree

    ll m = euler.size();   // Making Segment Tree
    segTree.resize(m * 4);
    build_SegTree(1, 1, m - 1);
}

// Algorithm to find the Lowest Common Ancestor using a Segmentation Tree
ll lca(int u,int v){

    int l = first[u];
    int r = first[v];

    if(l > r){
        swap(l,r);
    }

    return query_SegTree(1, 1, euler.size()-1, l, r).first;
}

/*

Time Complexity

lca         -> O(logN) 
build_LCA   -> O(N)

Links:

https://cp-algorithms.com/graph/lca.html

*/