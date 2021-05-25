#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 10; // Number of vertices

// Graph inplementation using Adjacency matrix (0-Based)
ll graph[N][N];

// Matrix used to keep the shortest distances (0-Based)
ll dist[N][N];

// Undirected Weighted Graph
void addEdge(int u, int v,ll w){
    graph[u][v] = w;
    graph[v][u] = w;
}

// Function used to initialize the distance matrix
void build(){

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == j) dist[i][j] = 0;
            else if(graph[i][j]) dist[i][j] = graph[i][j];
            else dist[i][j] = LONG_LONG_MAX;
        }
    }

}

// Floyd-Warshall Algorithm
// Find the length of the shortest path d[i][j] between each pair of vertices i and j.
void floydWarshall(){

    // We test all K vertices as intermediaries between (i -> j),
    // the shortest path between (i -> j) will be (i -> k -> j)
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                // If our graph has negative weight edges it is necessary to do this check
                if (graph[i][k] < __LONG_LONG_MAX__ && graph[k][j] < __LONG_LONG_MAX__)
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]); 
            }
        }
    }

}

/*

Time Complexity

build           -> O(N^2)
floydWarshall   -> O(N^3)

Links:

https://cp-algorithms.com/graph/all-pair-shortest-path-floyd-warshall.html
https://www.geeksforgeeks.org/floyd-warshall-algorithm-dp-16/

Obs.: 

1º) Erros de precisão são acumulados muito rápido utilizando pontos flutuantes, precisamos corrigir
utilizando EPS (Ver o primeiro site)
2º) Podemos guardar os predecessores utilizando uma matriz.
3º) O grafo pode ter pesos negativos, mas não ciclos negativos

*/