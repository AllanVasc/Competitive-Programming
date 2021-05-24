#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2000; // Number of vertices

// Graph inplementation using Adjacency List (0-Based)
vector<int> adj[N];

// Array to set visited Nodes
bool visited[N];

// Undirected Graph
void addEdge(int u, int v){
    adj[u].push_back(v); 
    adj[v].push_back(u); 
}

// DFS
void dfsUtil(int v){

    // Mark current vertex as visited
    visited[v] = true; 

    // Recur for all the vertices adjacent to this vertex
    for(auto u: adj[v]){
        if(visited[u] == false){
            dfsUtil(u);
        }
    }

}

// Traverse all the Graph (Disconnected Graph) (If you know that is a connected Graph, just use "dfsUtil(root)")
void dfs(){

    // Set all unvisited
    for(int i = 0; i < N; i++){ 
        visited[i] = false;
    } 

    // Visit all unvisited vertices
    for(int i = 0; i < N; i++){
        if(visited[i] == false){
            dfsUtil(i);
        }
    }

}

/*

Time Complexity

addEdge     -> O(1)
dfs         -> O(V+E)

Links:

https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/
https://www.geeksforgeeks.org/graph-implementation-using-stl-for-competitive-programming-set-1-dfs-of-unweighted-and-undirected/


*/