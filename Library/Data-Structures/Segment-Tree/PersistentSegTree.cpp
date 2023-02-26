#include <bits/stdc++.h>
using namespace std;
  
#define int long long

// In main we need to call create 2 times
// p == 0 -> NULL
// p == 1 -> First version root

vector<int> roots, answSeg, lNodes, rNodes;

// On every update we need to save the root of the new version of the Seg
// roots[i] = update(roots[i - 1], -MAXN, MAXN, id, val)

// Returns the node index
int create(){
    answSeg.push_back(0);   // Must be a default value 
    lNodes.push_back(0);    // The index "0" will always represent the null node 
    rNodes.push_back(0);    // The index "0" will always represent the null node
    return answSeg.size() - 1;
}

// The update function needs to return the id of the newly created node.
int update(int p, int l, int r, int id, int val){
    int novo = create();
    answSeg[novo] = answSeg[p];
    lNodes[novo] = lNodes[p];
    rNodes[novo] = rNodes[p];

    if(l == r){
        answSeg[novo] = val;
        return novo;
    }
    int m = (l + r) >> 1;
    if(id <= m){
        int aux = update(lNodes[novo], l, m, id, val);
        lNodes[novo] = aux;
    }
    else{
        int aux = update(rNodes[novo], m + 1, r, id, val);
        rNodes[novo] = aux;
    }
    answSeg[novo] = answSeg[lNodes[novo]] + answSeg[rNodes[novo]];
    return novo;
}

int query(int p, int l, int r, int ql, int qr){
    if(qr < l || ql > r) return 0;
    if(p == 0) return 0;
    if(l >= ql && r <= qr) return answSeg[p];
    int m = (l + r) >> 1;
    return query(lNodes[p], l, m, ql, qr) + query(rNodes[p], m + 1, r, ql, qr);
}

/*

Time Complexity

** n is the size of the range

query   -> O(logn)
update  -> O(logn)

Memory Complexity: O(Q * logn)

Links:

https://www.youtube.com/watch?v=7_xncNind2w&list=PLdyIeAAaboLsj9RpB4GJjAxIBXXnIrbGN&index=8

*/