#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 0x3f3f3f3f3f3f3f3f;
const int ms = 500;

int g[ms][ms];
int dist[ms][ms];

// Undirected Weighted Graph
void addEdge(int u, int v, int w){
    g[u][v] = w;
    g[v][u] = w;
}

// Initialize the distance matrix
void build(){
    for(int i = 0; i < ms; i++){
        for(int j = 0; j < ms; j++){
            if(i == j) dist[i][j] = 0;
            else if(g[i][j]) dist[i][j] = g[i][j];
            else dist[i][j] = INF;
        }
    }
}

// Floyd-Warshall Algorithm
// Find the length of the shortest path d[i][j] between each pair of vertices i and j.
void floydWarshall(){
    // We test all K vertices as intermediaries between (i -> j),
    // the shortest path between (i -> j) will be (i -> k -> j)
    for(int k = 0; k < ms; k++){
        for(int i = 0; i < ms; i++){
            for(int j = 0; j < ms; j++){
                // If our graph has negative weight edges it is necessary to do this check
                if(dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); 
            }
        }
    }
}

/*

Time Complexity:

build           -> O(N^2)
floydWarshall   -> O(N^3)

Links:

https://cp-algorithms.com/graph/all-pair-shortest-path-floyd-warshall.html
https://www.geeksforgeeks.org/floyd-warshall-algorithm-dp-16/

Obs.: 

1º) Erros de precisao sao acumulados muito rapido utilizando pontos flutuantes, precisamos corrigir
utilizando EPS (Ver o primeiro site)
2º) Podemos guardar os predecessores utilizando uma matriz.
3º) O grafo pode ter pesos negativos, mas não ciclos negativos

*/