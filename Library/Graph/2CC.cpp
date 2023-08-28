#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>

/*
Code for compressing graph into 2-Edge-Connected Component 
and finding Bridges online.
2CC it's a CC that remains connected whenever you remove fewer than 2 edges.
(Can't have Bridges inside)
*/

// 0 -> Connected Component
// 1 -> 2-Edge-Connected Component
vector<int> dsu[2], sz[2];
vector<int> parent, visited;
int bridges = 0;
int iteration;

// Initialize 2 DSU
void build(int n){
    iteration = 0;
    parent.resize(n);
    visited.resize(n);
    for(int i = 0; i < 2; i++){
        dsu[i].resize(n);
        sz[i].resize(n);
    }
    for(int i = 0; i < n; i++){
        dsu[0][i] = dsu[1][i] = i;
        sz[0][i] = sz[1][i] = 1;
        parent[i] = -1;
    }
    bridges = 0;
}

int find(int v, int type){
    if(v == -1) return -1;
    if(dsu[type][v] == v) return v;
    return dsu[type][v] = find(dsu[type][v], type);
}

// Makes "v" the new root of the CC tree that "v" belongs to
void reRoot(int v){
    v = find(v, 1);
    int root = v;
    int child = -1;
    while(v != -1){
        int p = find(parent[v], 1);
        parent[v] = child;
        dsu[0][v] = root;
        child = v;
        v = p;
    }
    sz[0][root] = sz[0][child];
}

void merge(int a, int b){
    iteration++;
    vector<int> path_a, path_b;
    int lca = -1;
    while(lca == -1){
        if(a != -1){
            a = find(a, 1);
            path_a.push_back(a);
            if(visited[a] == iteration){
                lca = a;
                break;
            }
            visited[a] = iteration;
            a = parent[a];
        }
        if(b != -1){
            b = find(b, 1);
            path_b.push_back(b);
            if(visited[b] == iteration){
                lca = b;
                break;
            }
            visited[b] = iteration;
            b = parent[b];
        }
    }

    for(int v : path_a){
        dsu[1][v] = lca;
        if(v == lca) break;
        bridges--;
    }
    for(int v : path_b){
        dsu[1][v] = lca;
        if(v == lca) break;
        bridges--;
    }
}

void addEdge(int a, int b){
    a = find(a, 1);
    b = find(b, 1);
    if(a == b) return;

    int ca = find(a, 0);
    int cb = find(b, 0);
    if(ca != cb){
        bridges++;
        if(sz[0][ca] > sz[0][cb]){
            swap(a, b), swap(ca, cb);
        }
        reRoot(a);
        parent[a] = dsu[0][a] = b;
        sz[0][cb] += sz[0][a];
    }
    else{
        merge(a, b);
    }
}

/*

Time Complexity:

build   -> O(n)
find    -> O(1) amortized
reRoot  -> O(nlogn) n = size of current tree
merge   -> O(|cycle|)

total   -> O(n*logn + m*logn) m = number of edges

Links:

https://cp-algorithms.com/graph/bridge-searching-online.html

*/