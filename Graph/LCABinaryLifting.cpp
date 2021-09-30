#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX_N = 10000;    // Number of vertices
const int LOG = 20;         // Log2(N)

vector<int> children[MAX_N];    // Graph inplementation using Adjacency List (0-Based)
int up[MAX_N][LOG];             // up[v][j] is 2^j-th ancestor of v
int depth[MAX_N];

// Preprocessing
void dfs(int a) {
	for(int b : children[a]) {
		depth[b] = depth[a] + 1;
		up[b][0] = a; // a is parent of b
		for(int j = 1; j < LOG; j++) {
			up[b][j] = up[ up[b][j-1] ][j-1];
		}
		dfs(b);
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
	// 2) if b was ancestor of a then now a==b
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