// D - The Door Problem
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1000000;    // Number of variables

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
 
int main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;

    cin >> n >> m;

    vector<bool> doorsOpen;

    vector<vector<int>> doorSwitch(n);

    for(int i = 0; i < n; i++){

        bool aux;
        cin >> aux;
        doorsOpen.push_back(aux);
    }

    for(int i = 0; i < m; i++){
        int qtdSwitch;
        cin >> qtdSwitch;
        
        for(int j = 0; j < qtdSwitch; j++){
            int aux;
            cin >> aux;
            doorSwitch[aux-1].push_back(i+1);
        }
    }

    // tenho tudo no vetor!

    vector<int> a,b;

    for(int i = 0; i < n; i++){

        if(doorsOpen[i] == 1){ // 1 -> (¬A V B) ∧ (A V ¬B)

            a.push_back(-1*doorSwitch[i][0]);
            b.push_back(doorSwitch[i][1]);

            a.push_back(doorSwitch[i][0]);
            b.push_back(-1*doorSwitch[i][1]);

        }
        else{ // 0 -> (A ∨ B) ∧ (¬A ∨ ¬B)

            a.push_back(doorSwitch[i][0]);
            b.push_back(doorSwitch[i][1]);

            a.push_back(-1*doorSwitch[i][0]);
            b.push_back(-1*doorSwitch[i][1]);
        }
    }

    for(int i = 0; i < a.size(); i++){
        addEdge(a[i],b[i]);
    }

    if(solve2SAT()){
        cout << "YES" << '\n';
    }
    else{
        cout << "NO" << '\n';
    }

    return 0;
}
 
/*

Para uma porta já aberta temos duas opções não ligamos o switch OU ligamos os dois switchs.
Para uma porta fechada temos que ligar um dos switchs. Ligamos o primeiro ou o segundo.

Logo temos:

1 -> (!A ^ !B) V (A ^ B)
0 -> (A ^ !B) V (!A ^ B) 
 
Transformando em CNF:

1 -> (¬A V B) ∧ (A V ¬B)
0 -> (A ∨ B) ∧ (¬A ∨ ¬B)

Temos nosso problema reduzido para um 2SAT.

*/