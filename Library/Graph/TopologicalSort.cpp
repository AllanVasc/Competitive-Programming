#include <bits/stdc++.h>
using namespace std;
 
#define int long long
vector<vector<int>> g;

// Directed Graph
void addEdge(int u, int v){
    g[u].push_back(v); 
}

// Kahn's algorithm for Topological Sorting (Directed Acyclic Graphs)
vector<int> topologicalSort(){
    int n = g.size();

    vector<int> inDegree(n, 0);
    for(int u = 0; u < n; u++) {
        for(auto v : g[u]){
            inDegree[v]++;
        } 
    }

    queue<int> q; 
    for(int i = 0; i < n; i++){
        if(inDegree[i]) continue;
        q.push(i); 
    }
    int cnt = 0; // # of visited
    vector<int> answ;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        answ.push_back(u);
        for(auto v : g[u]){
            if(--inDegree[v] == 0){
                q.push(v);
            }
        }
        cnt++;
    }
    if(cnt == n) return answ;
    else return {}; // There's a cycle, impossible to find topological sort
}

/*

Time Complexity:

topologicalSort -> O(V + E)

Links:

https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/
https://cp-algorithms.com/graph/topological-sort.html
https://www.geeksforgeeks.org/cpp-program-for-topological-sorting/

*/