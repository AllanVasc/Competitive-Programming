#include <bits/stdc++.h>
using namespace std;

#define int long long

const int ms = 1e6;
int par[ms], sz[ms];

void build(){
    for(int i = 0; i < ms; i++){
        par[i] = i;
        sz[i] = 1;
    }
}

// Path Compression Optimization
int find(int u){ return u == par[u] ? u : par[u] = find(par[u]); }

// Union by Size Optimization
void merge(int a, int b){
    a = find(a), b = find(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
}

/*

Time Complexity:

build   -> O(N)
find    -> O(logN) (Average case is O(1))
merge   -> O(logN) (Average case is O(1))

Links:

https://cp-algorithms.com/data_structures/disjoint_set_union.html
https://www.geeksforgeeks.org/union-find-algorithm-set-2-union-by-rank/

*/