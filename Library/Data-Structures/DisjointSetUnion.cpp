#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 10; // Number of vertex

// Disjoint Set Union implementation using array (0-Based)
int parent[N];

// Array to Union by Size (0-Based)
int size[N];

// Function used to initialize Disjoint Set
void Build(){
    for(int i = 0; i < N; i++){
        parent[i] = i;
        size[i] = 1;
    }
}

// Returns the representative of the set that contains the element "v" (Path Compression Optimization)
int Find(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = Find(parent[v]);
}

// Joins two different sets (Union by Size Optimization)
void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a != b) {
        // We put the smallest set in the largest
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

/*

Time Complexity

Build   -> O(N)
Find    -> O(logN) ( In the worst case, the average case is O(1) )
Union   -> O(logN) ( In the worst case, the average case is O(1) )

Links:

https://cp-algorithms.com/data_structures/disjoint_set_union.html
https://www.geeksforgeeks.org/union-find-algorithm-set-2-union-by-rank/

*/