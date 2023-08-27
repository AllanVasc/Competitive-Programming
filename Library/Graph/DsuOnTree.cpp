#include <bits/stdc++.h>
using namespace std;
  
#define int long long

// Smaller to Larger / DSU On Tree
// This code answers: 
// "how many vertices in subtree of vertex v are colored with color c?"

vector<vector<int>> g;
const int ms = 1e5;
int sz[ms], color[ms], cnt[ms];

// Preprocesses the size of the subtrees
void dfsSize(int u, int p = -1){
    sz[u] = 1;
    for(auto v : g[u]){
        if(v == p) continue;
        dfsSize(v, u);
        sz[u] += sz[v];
    }
}

// For each problem we'll have a different add function
void add(int u, int p, int bigChild, int x){
    cnt[color[u]] += x;
    for(auto v : g[u]){
        if(v == p || v == bigChild) continue;
        add(v, u, bigChild, x);
    }
}

void DsuOnTree(int u, int p, bool keep){
    // Look for the largest child inside the subtree
    int maxSize = -1, bigChild = -1;
    for(auto v : g[u]){
        if(v != p && maxSize < sz[v]){
            maxSize = sz[v];
            bigChild = v;
        }
    }
    // Run a dfs on small childs and clear them from cnt
    for(auto v : g[u]){
        if(v == p || v == bigChild) continue;
        DsuOnTree(v, u, false);
    }
    // Calculates the answer of the greatest child and keeps his answer
    if(bigChild != -1) DsuOnTree(bigChild, u, true);
    // Merge the answers with small children
    add(u, p, bigChild, 1);
    // cnt[c] = # vertices in subtree of vertex u that has color c
    if(keep == false) add(u, p, -1, -1);
}

/*

Time Complexity:

DsuOnTree   -> O(nlogn)

Links:

https://codeforces.com/blog/entry/44351
https://codeforces.com/blog/entry/67696

*/