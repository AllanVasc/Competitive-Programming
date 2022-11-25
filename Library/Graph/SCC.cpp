#include <bits/stdc++.h>
using namespace std;

#define int long long

// Kosaraju's Algorithm for finding Strongly Connected Components (SCC)
struct SCC {
    int n;
    vector<vector<int>> g, gt, condensation_g;
    vector<bool> visited;
    stack<int> order;
    vector<int> parent, root_nodes;

    SCC(vector<vector<int>> &graph){
        n = graph.size();
        this->g = graph;

        gt.assign(n, vector<int>());
        for(int i = 0; i < n; i++){
            for(auto v : g[i]){
                gt[v].push_back(i);
            }
        }
        build();
    }

private:
    void build(){
        visited.assign(n, false);
        for(int i = 0; i < n; i++){
            if(!visited[i]) dfs(i);
        }

        parent.assign(n, -1);
        
        while(!order.empty()){
            int u = order.top();
            order.pop();
            if(parent[u] == -1){
                findComponent(u, u);
                root_nodes.push_back(u);
            }
        }

        // Building the Condensation Graph
        condensation_g.assign(n, vector<int>());
        for(int u = 0; u < n; u++){
            for(auto v : g[u]){
                int root_u = parent[u];
                int root_v = parent[v];
                if(root_u != root_v)
                    condensation_g[root_u].push_back(root_v);
            }
        }
    }

    void dfs(int u){
        visited[u] = true;
        for(auto v : g[u]){
            if(!visited[v]) dfs(v);
        }
        order.push(u);
    }

    void findComponent(int u, int root){
        parent[u] = root;
        for(auto v : gt[u]){
            if(parent[v] == -1) findComponent(v, root);
        }
    }
};

/*

Time Complexity

SCC ->  O(E + V)

Links:

https://cp-algorithms.com/graph/strongly-connected-components.html
https://www.youtube.com/watch?v=RpgcYiky7uw

*/