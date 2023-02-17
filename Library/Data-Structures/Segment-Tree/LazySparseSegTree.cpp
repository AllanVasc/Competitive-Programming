#include <bits/stdc++.h>
using namespace std;

#define int long long

// In main we need to call create 2 times
// p == 0 -> NULL
// p == 1 -> Root

vector<int> answSeg, lazySeg, lNodes, rNodes;

// Returns the node index
int create(){
    answSeg.push_back(0);   // Must be a default value 
    lazySeg.push_back(0);   // Must be a default value
    lNodes.push_back(0);    // The index "0" will always represent the null node 
    rNodes.push_back(0);    // The index "0" will always represent the null node
    return answSeg.size() - 1;
}

void propagate(int p, int l, int r){
    if(p == 0 || lazySeg[p] == 0) return;
    answSeg[p] += (r - l + 1) * lazySeg[p];
    if(l != r){
        if(lNodes[p] == 0){
            int aux = create();
            lNodes[p] = aux;
        }
        if(rNodes[p] == 0){
            int aux = create();
            rNodes[p] = aux;
        }
        lazySeg[lNodes[p]] += lazySeg[p];
        lazySeg[rNodes[p]] += lazySeg[p];
    }
    lazySeg[p] = 0;
}

void update(int p, int l, int r, int ql, int qr, int val){
    propagate(p, l, r);
    if(l > qr || r < ql) return;
    if(ql <= l && r <= qr){
        lazySeg[p] = val;
        propagate(p, l, r);
    }
    else{
        int m = (l + r) >> 1;
        if(lNodes[p] == 0){
            int aux = create();
            lNodes[p] = aux;
        }
        if(rNodes[p] == 0){
            int aux = create();
            rNodes[p] = aux;
        }
        update(lNodes[p], l, m, ql, qr, val);
        update(rNodes[p], m + 1, r, ql, qr, val);
        answSeg[p] = answSeg[lNodes[p]] + answSeg[rNodes[p]];
    }
}

int query(int p, int l, int r, int ql, int qr){
    propagate(p, l, r);
    if(l > qr || r < ql) return 0;
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

https://www.youtube.com/watch?v=omV7bTYdLHs&list=PLdyIeAAaboLsj9RpB4GJjAxIBXXnIrbGN&index=6

*/