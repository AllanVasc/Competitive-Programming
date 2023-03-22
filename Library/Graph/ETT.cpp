#include <bits/stdc++.h>
using namespace std;
  
#define int long long

// Euler Tour technique for flattening a tree

const int ms = 2*1e5 + 100;
vector<vector<int>> g;
int timer = 0;
int st[ms], en[ms];

// For each vertex we assign a unique id, 
// all vertices of its subtree will have contiguous ids
// We build the Seg Tree using the ids in st[u] and en[u]
void dfs(int u, int p = -1){
    st[u] = timer++;
    for(auto v : g[u]){
        if(v == p) continue;
        dfs(v, u);
    }
    en[u] = timer - 1; // This can change 
}

/*

Time Complexity:

dfs -> O(V + E)

Links:

https://codeforces.com/blog/entry/81527

*/