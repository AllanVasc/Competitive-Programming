#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 9; // Number of vertex

// Graph inplementation using Adjacency List (0-Based)
vector<int> adj[N];

// Transposed Graph using Adjacency List (0-Based)
vector<int> adjT[N];

// Condensation Graph using Adjacency List (0-Based)
vector<int> adjCond[N];

// Auxiliary Vectors
vector<bool> visited;
vector<int> order;
vector<int> component;

// Nodes of the same component will have the same root
vector<int> roots;

// List of all root nodes (one per component) in the Condensation Graph.
vector<int> root_nodes;

// Directed Graph (Building the graph and its transposition)
void addEdge(int u, int v){
    adj[u].push_back(v); 
    adjT[v].push_back(u);
}

// First DFS traversal to build the processing order
void dfsOrder(int u){

    visited[u] = true;

    for(auto v : adj[u]){
        if(!visited[v])
            dfsOrder(v);
    }

    order.push_back(u);
}

// Second DFS Traversal to build the list of components
void dfsComponent(int u) {
    visited[u] = true;
    component.push_back(u);

    for (auto v : adjT[u])
        if (!visited[v])
            dfsComponent(v);
}

// Kosaraju's Algorithm for finding Strongly Connected Components (SCC)
void kosaraju(){

    // Building the processing order 
    visited.assign(N,false);

    for(int i = 0; i < N; i++)
        if (!visited[i])
            dfsOrder(i);

    // We need to reverse the order
    visited.assign(N, false);
    reverse(order.begin(), order.end());

    roots.assign(N, 0);

    // Finding Strongly Connected Components Through Graph Transpose
    for (auto u : order){
        if (!visited[u]) {
            dfsComponent(u);

            // We put the first one on the list as the component's representative
            int root = component.front();
            for (auto v : component) 
                roots[v] = root;

            // This node exists in the Condensed Graph
            root_nodes.push_back(root);

            component.clear();
        }
    }

    // Building the Condensed Graph
    for (int u = 0; u < N; u++){
        for (auto v : adj[u]) {
            int root_u = roots[u];
            int root_v = roots[v];

            if (root_u != root_v)
                adjCond[root_u].push_back(root_v);
        }
    }
}

// Testing the Algorithm
int main(){

    addEdge(0,1);
    addEdge(1,2);
    addEdge(2,3);
    addEdge(3,0);
    addEdge(2,4);
    addEdge(4,5);
    addEdge(5,6);
    addEdge(6,4);
    addEdge(7,6);
    addEdge(7,8);

    kosaraju();

    cout << "Nos existentes no grafo condensado: " << '\n';
    for(int i = 0; i < root_nodes.size(); i++){
        cout << root_nodes[i] << " ";
    }
    cout << "\n";

    cout << "Grafo Condensado: " << "\n";
    for(int i = 0; i < N; i++){
        cout << i << " -> ";
        for(auto u : adjCond[i]){
            cout << u << " ";
        }
        cout << '\n';
    }
    return 0;
}

/*

Time Complexity

kosaraju    -> O(V+E)

Links:

https://cp-algorithms.com/graph/strongly-connected-components.html
https://www.geeksforgeeks.org/strongly-connected-components/
https://www.youtube.com/watch?v=5wFyZJ8yH9Q

*/