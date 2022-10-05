#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5+10; // Number of vertex

// Graph inplementation using Adjacency List (0-Based)
vector<int> adj[N];

// Directed Graph
void addEdge(int u, int v){
    adj[u].push_back(v); 
}

// Kahn’s algorithm for Topological Sorting (Directed Acyclic Graphs)
void topologicalSort(){

    // Stores the amount of edges reaching the vertex
    vector<int> inDegree(N, 0);

    // Calculating in degree O(V+E)
    for(int u = 0; u < N; u++) {
        for(auto v : adj[u]){
            inDegree[v]++;
        } 
    }

    queue<int> q; 

    // We need to start at a vertex with in degree = 0 
    for(int i = 0; i < N; i++){
        if(inDegree[i] == 0) {
            q.push(i); 
        }
    }

    // Number of vertices visited
    int cnt = 0;

    vector<int> answer;

    // BFS Traversal
    while (!q.empty()) {

        int u = q.front();
        q.pop(); 
        answer.push_back(u); 

        for(auto v : adj[u]){
            if(--inDegree[v] == 0){
                q.push(v);
            }
        }

        // Vertex visited
        cnt++;
    }

    // We couldn't get a correct answer
    if (cnt != N) {
        cout << "There exists a cycle" << '\n'; 
        return; 
    }

    // We have an answer
    for (int i = 0; i < answer.size(); i++){
        cout << answer[i] << " ";
    }
    cout << '\n';

}

/*

Time Complexity

topologicalSort -> O(V+E)

Links:

https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/
https://cp-algorithms.com/graph/topological-sort.html
https://www.geeksforgeeks.org/cpp-program-for-topological-sorting/

*/