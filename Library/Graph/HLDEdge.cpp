#include <bits/stdc++.h>
using namespace std;

#define int long long

const int ms = 1e5;
vector<vector<pair<int,int>>> g;
vector<int> sobe;
int sz[ms], par[ms], head[ms], pos[ms];
int v[ms], seg[4 * ms];
int t;

void dfs_sz(int u, int p = -1){
    sz[u] = 1;
    for(auto & i : g[u]){
        auto [v, w] = i;
        if(v == p) continue;
        sobe[v] = w;
        dfs_sz(v, u);
        sz[u] += sz[v];
        if(g[u][0].first == p || sz[v] > sz[g[u][0].first]) swap(i, g[u][0]);
    }
}

void dfs_hld(int u, int p = -1){
    pos[u] = t++;
    v[pos[u]] = sobe[u];
    for(auto i : g[u]){
        auto [v, w] = i;
        if(v == p) continue;
        par[v] = u;
        head[v] = (i == g[u][0] ? head[u] : v);
        dfs_hld(v, u);
    }
}

// Call this function to initialize
void build_hld(int root = 0){
    dfs_sz(root);
    t = 0;
    head[root] = root;
    dfs_hld(root);
    build_seg(1, 0, t - 1); // We can use any data structure for range query
}

// Sum query between path from "a" to "b"
int query_path(int a, int b){
    if(a == b) return 0;
    if(pos[a] < pos[b]) swap(a, b);
    if(head[a] == head[b]) return query_seg(pos[b] + 1, pos[a]);
    return query_seg(pos[head[a]], pos[a]) + query_path(par[head[a]], b);
}

// Updates all vertices of the path from "a" to "b"
void update_path(int a, int b, int x){
    if(a == b) return;
    if(pos[a] < pos[b]) swap(a, b);
    if(head[a] == head[b]){
        update_seg(pos[b] + 1, pos[a], x);
        return;
    }
    update_seg(pos[head[a]], pos[a], x);
    update_path(par[head[a]], b, x);
}

// Queries all nodes in the subtree of "a"
int query_subtree(int a){
    if(sz[a] == 1) return 0;
    return query_seg(pos[a] + 1, pos[a] + sz[a] - 1);
}

// Updates all nodes in the subtree of "a"
void update_subtree(int a, int x){
    if(sz[a] == 1) return;
    update_seg(pos[a] + 1, pos[a] + sz[a] - 1, x);
}

int lca(int a, int b){
    if(pos[a] < pos[b]) swap(a, b);
    return head[a] == head[b] ? b : lca(par[head[a]], b);
}

/*

Time Complexity:

build           -> O(n)
update_path     -> O(log^2(n))
query_path      -> O(log^2(n))
query_subtree   -> O(log(n))
update_subtree  -> O(log(n))
lca             -> O(log(n))

Links:

https://www.youtube.com/watch?v=L8mxYASOU2E
https://usaco.guide/plat/hld?lang=cpp

*/