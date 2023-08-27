// Code based on the Brunomont's github
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>

/*
Block-Cut Tree: It's a tree that each BCC and articulation points 
is a unique vertex. We have a edge (BCCx, arty) if arty is inside BCCx

A 2-Coloring is such that one color will be the blocks and the other the articulation points

2-vertex-connected components = Biconnected components = Blocks
Blocks = maximal subset of E such that the induced subgraph is 2-vertex-connected

art[i] = number of new connected components formed after
removing vertex "i". if art[i] >= 1, "i" It's an articulation.

for all i < blocks.size()
blocks[i] it's a BCC
edgBlocks[i] it's the blocks[i] edges
tree[i] it's a vertex from tree that corresponds to block[i]

pos[i] = The vertex that "i" corresponds in the Block Cut Tree

The Block Cut Tree will have at most 2*n vertices
*/

struct BlockCutTree{
    vector<vector<int>> g, blocks, tree;
    vector<vector<pii>> edgBlocks;
    stack<int> stV; // Store the vertices in DFS order
    stack<pii> stE; // Store the edges in DFS order
    vector<int> disc, low, art, pos;
    int n, timer;

    BlockCutTree(vector<vector<int>> g) : g(g){
        n = g.size();
        disc.assign(n, -1);
        low.assign(n, -1);
        art.assign(n, 0);
        pos.assign(n, -1);
        build();
    }

    void dfs(int u, int p = -1){
        disc[u] = low[u] = timer++;
        stV.push(u);

        if(p != -1) stE.push({u, p});
        for(int v : g[u]){ // Backedges
            if(v != p && disc[v] != -1) stE.push({u, v});
        }
        bool hasFwd = false;
        for(int v : g[u]){
            if(v == p) continue;
            if(disc[v] == -1){ // Unvisited
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if(low[v] >= disc[u]){ // "u" is Articulation
                    art[u]++;
                    blocks.emplace_back(1, u);
                    while(blocks.back().back() != v){
                        blocks.back().push_back(stV.top());
                        stV.pop();
                    }

                    edgBlocks.emplace_back(1, stE.top());
                    stE.pop();
                    while(edgBlocks.back().back() != pair(v, u)){
                        edgBlocks.back().push_back(stE.top());
                        stE.pop();
                    }
                }
                hasFwd = true;
            }
            else low[u] = min(low[u], disc[v]);
        }
        if(p == -1){
            if(art[u]) art[u]--;
            if(!hasFwd){    // BCC = {u}
                blocks.emplace_back(1, u);
                edgBlocks.emplace_back();
            }
        }
    }

    void build(){
        int timer = 0;
        for(int i = 0; i < n; i++){
            if(disc[i] == -1) dfs(i);
        }

        tree.assign(blocks.size(), vector<int>());
        for(int i = 0; i < n; i++){
            if(art[i]){
                pos[i] = tree.size();
                tree.emplace_back();
            }
        }

        for(int i = 0; i < blocks.size(); i++){
            for(int j : blocks[i]){
                if(!art[j]) pos[j] = i;
                else{   // Edge BCC - Articulation
                    tree[i].push_back(pos[j]);
                    tree[pos[j]].push_back(i);
                }
            }
        }
    }
};

/*

Time Complexity:

BlockCutTree    -> O(V + E)

Links:

https://www.youtube.com/watch?v=iYJqgMKYsdI

*/