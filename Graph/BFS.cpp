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

// This function return true with a graph is bipartite
bool isBipartite(){

    // Store color of the vertex (-1 = unvisited, 0 = black, 1 = whites)
    vector<int> color(N, -1);
 
    // queue for BFS storing {vertex , colour}
    queue<pair<int, int> > q;
   
    //loop incase graph is not connected
    for (int i = 0; i < N; i++) {
       
        //if not coloured (not visited)
        if (color[i] == -1) {
           
            // Assign any color
            q.push({ i, 0 });
            color[i] = 0;

            //BFS
            while (!q.empty()) {

                pair<int, int> p = q.front();
                q.pop();
               
                //current vertex
                int v = p.first;
                //colour of current vertex
                int c = p.second;
                 
                //traversing vertexes connected to current vertex
                for (int j : adj[v]) {
                   
                    // Can't be bipartite
                    if (color[j] == c)
                        return false;
                   
                    //if uncooloured (unvisited)
                    if (color[j] == -1) {
                        //colouring with opposite color to that of parent
                        color[j] = 1-c;
                        q.push({ j, color[j] });
                    }
                }
            }
        }
    }

    // Graph is Bipartite
    return true;
}

/*

Time Complexity

addEdge     -> O(1)
bfs         -> O(V+E)
isBipartite -> O(V+E)

Links:

https://www.geeksforgeeks.org/bfs-using-stl-competitive-coding/
https://www.geeksforgeeks.org/bipartite-graph/

*/