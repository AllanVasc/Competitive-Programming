#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 11; // Number of vertices

// Graph inplementation using Adjacency List (0-Based)
vector<int> adj[N];

// Array to set visited Nodes
bool visited[N];

// Undirected Graph
void addEdge(int u, int v){
    adj[u].push_back(v); 
    adj[v].push_back(u); 
}

// BFS
void bfsUtil(int v){

    queue<int> q;

    q.push(v);
    visited[v] = true;

    while(!q.empty()){

        int u = q.front();
        q.pop();

        for(auto i: adj[u]){

            if(visited[i] == false){
                q.push(i);
                visited[i] = true;
            }

        }
    }
}

// Traverse all the Graph (Disconnected Graph) (If you know that is a connected Graph, just use "bfsUtil(root)")
void bfs(){

    // Set all unvisited
    for(int i = 0; i < N; i++){ 
        visited[i] = false;
    } 

    // Visit all unvisited vertices
    for(int i = 0; i < N; i++){
        if(visited[i] == false){
            bfsUtil(i);
        }
    }

}

/*

Time Complexity

addEdge     -> O(1)
bfs         -> O(V+E)

Links:

https://www.geeksforgeeks.org/bfs-using-stl-competitive-coding/

*/