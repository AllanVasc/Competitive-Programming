#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 10000;  	// Number of vertices
const int LOG = 20;     	// Log2(N)

vector<vector<int>> children;	// Graph inplementation using Adjacency List (0-Based)
int up[MAXN][LOG];            	// up[v][j] is 2^j-th ancestor of v
int depth[MAXN];

// Preprocessing
void dfs(int a, int p) {
	for(int b : children[a]) {
		if(b == p) continue;    // don't go back to the father
		depth[b] = depth[a] + 1;
		up[b][0] = a; 			// a is parent of b
		for(int j = 1; j < LOG; j++) {
			up[b][j] = up[ up[b][j-1] ][j-1];
		}
		dfs(b, a);
	}
}

// Algorithm to find the Lowest Common Ancestor using Binary Lifting
int lca(int a, int b) {
	if(depth[a] < depth[b]) {
		swap(a, b);
	}
	// 1) Get same depth.
	int k = depth[a] - depth[b];
	for(int j = LOG - 1; j >= 0; j--) {
		if(k & (1 << j)) {
			a = up[a][j]; // parent of a
		}
	}
	// 2) if b was ancestor of a then now a == b
	if(a == b) {
		return a;
	}
	// 3) move both a and b with powers of two
	for(int j = LOG - 1; j >= 0; j--) {
		if(up[a][j] != up[b][j]) {
			a = up[a][j];
			b = up[b][j];
		}
	}
	return up[a][0];
}

/*

Time Complexity

lca     -> O(logN) 
dfs     -> O(N*logN)

Links:

https://cp-algorithms.com/graph/lca_binary_lifting.html
https://www.youtube.com/watch?v=dOAxrhAUIhA
https://github.com/Errichto/youtube/blob/master/lca.cpp

*/