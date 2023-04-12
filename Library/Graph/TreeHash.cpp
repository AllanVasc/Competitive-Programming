#include <bits/stdc++.h>
using namespace std;
  
#define int long long

using ii = pair<int,int>;
const int MOD = 1e9 + 7;
const int ms = 1e5 + 100;
int h[ms], sz[ms];

int fexp(int x, int y){
    int answ = 1;
    x = x % MOD;
    while(y){
        if(y & 1) answ = answ * x % MOD;
        x = x * x % MOD;
        y >>= 1;
    }
    return answ;
}

// If the tree is not rooted you need to root the centroids
void getHash(int u, int p, vector<vector<int>>& g){
    sz[u] = 1;
    vector<ii> children;
    for(auto v : g[u]){
        if(v == p) continue;
        getHash(v, u, g);
        sz[u] += sz[v];
        children.push_back({h[v], sz[v]});
    }
    sort(children.begin(), children.end());

    h[u] = 1;
    for(auto [val, size] : children){
        int pw2 = fexp(2, 2 * size);
        h[u] = h[u] * pw2 % MOD;
        h[u] = (h[u] + val) % MOD;
    }
    h[u] = 2 * h[u] % MOD;
}

//------------Perfect Hash-------------//
// No collisions
map<vector<int>, int> hasher;

int hashify(vector<int> x){
    sort(x.begin(), x.end());
    if(!hasher[x]){
        hasher[x] = hasher.size();
    }
    return hasher[x];
}

int hashTree(int u, int p, vector<vector<int>>& g){
    vector<int> children;
    for(int v : g[u]){
        if(v == p) continue;
        children.push_back(hashTree(v, u, g));
    }
    return hashify(children);
}

/*

Time Complexity:

getHash     -> O(n*logn)
hashTree    -> O(n*logn)

Links:

https://codeforces.com/blog/entry/101010
https://codeforces.com/blog/entry/113465

*/