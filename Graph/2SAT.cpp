#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5;    // Number of variables

// Graph inplementation using Adjacency List (1-Based)
vector<int> adj[2*N+1];

// Transposed Graph using Adjacency List (1-Based)
vector<int> adjT[2*N+1];

// Auxiliary Vectors
vector<int> visited;
vector<int> order;
vector<int> comp;

// We set a variable to true or false (if there's an answer)
vector<bool> assignment;

// Directed Graph (Building the graph and its transposition)
void addEdge(int u, int v){

    // Variable x is mapped to x
    // Variable -x is mapped to N+x = N-(-x)

    // For (x v y) we need to add edges (!x -> y) and (!y -> x)
    if(u > 0 && v > 0){

        adj[u+N].push_back(v); // (!x -> y)
        adjT[v].push_back(u+N);

        adj[v+N].push_back(u); // (!y -> x)
        adjT[u].push_back(v+N);
    }

    else if(u > 0 && v < 0){

        adj[u+N].push_back(N-v); // (!x -> y)
        adjT[N-v].push_back(u+N);

        adj[-v].push_back(u);  // (!y -> x)
        adjT[u].push_back(-v);
    }

    else if (u < 0 && v > 0){
        
        adj[-u].push_back(v); // (!x -> y)
        adjT[v].push_back(-u);

        adj[v+N].push_back(N-u);  // (!y -> x)
        adjT[N-u].push_back(v+N);
    }

    else{

        adj[-u].push_back(N-v); // (!x -> y)
        adjT[N-v].push_back(-u);

        adj[-v].push_back(N-u);  // (!y -> x)
        adjT[N-u].push_back(-v);
    }
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
void dfsComponent(int u, int cl){
    comp[u] = cl;

    for (auto v : adjT[u])
        if (comp[v] == -1)
            dfsComponent(v, cl);
}

// 2SAT solution based on Kosaraju's Algorithm for finding Strongly Connected Components (SCC)
bool solve2SAT(){

    // Building the processing order 
    visited.assign(2*N+1,0);

    for(int i = 1; i <= 2*N; i++) // (1-Based)
        if (!visited[i])
            dfsOrder(i);

    // We need to reverse the order
    reverse(order.begin(), order.end());

    comp.assign(2*N+1, -1);
    for (int i = 0, j = 0; i < 2*N; i++) {
        int u = order[i];
        if (comp[u] == -1)
            dfsComponent(u, j++);
    }

    // Building our answer
    assignment.assign(N+1, false);
    
    for (int i = 1; i <= N; i++) { // (1-Based)
        if (comp[i] == comp[i+N])
            return false;
        assignment[i] = comp[i] > comp[i+N];
    }
    return true;
}

// Testing the Algorithm
int main(){

    // (x1 v x2)^(!x2 v x3)^(!x1 v !x2)^(x3 v x4)^(!x3 v x5)^(!x4 v !x5)^(!x3 v x4)
    int a[] = {1, -2, -1, 3, -3, -4, -3};
    int b[] = {2, 3, -2, 4, 5, -5, 4};

    for(int i = 0; i < 7; i++){
        addEdge(a[i],b[i]);
    }

    if(solve2SAT()){
        cout << "YES" << '\n';
        cout << "Possible Answer: ";
        for(int i = 1; i <= N; i++){
            cout << assignment[i] << " ";
        }
        cout << '\n';
    }
    else{
        cout << "NO" << '\n';
    }

    return 0;
}

/*

Time Complexity

solve2SAT   -> O(V+E)

Links:

https://cp-algorithms.com/graph/2SAT.html
https://www.geeksforgeeks.org/2-satisfiability-2-sat-problem/

Obs.:

1º) A entrada das variaveis precisam estar na Conjunctive Normal Form (CNF) para o algoritmo funcionar
2º) Lembre-se que: (A v B) = true, é igual a ===> (!A -> B) AND (!B -> A), Com isso transformamos (A V B) em 2 arestas.

*/