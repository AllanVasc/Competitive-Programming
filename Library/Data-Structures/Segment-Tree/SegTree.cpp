#include <bits/stdc++.h>
using namespace std;

#define int long long
const int ms = 20000; // Max size of v (Array used to construct)

// Implementation of a Recursive Segment Tree (1-Based) (Sum Operation)
int segTree[4*ms];

// Array used to construct Segtree (Need to be 1-Based)
vector<int> v;

// SINGLE-ELEMENT MODIFY, RANGE QUERY [l,r]

// Call using build(1,1,N) (N = v.size() - 1)
void build(int p, int l, int r){
    if(l == r){ // Building Leaf
        segTree[p] = v[r];
    }
    else{
        int m = (l+r)/2;
        int lc = 2*p;
        int rc = lc + 1;

        build(lc, l, m);        // Building Left Children
        build(rc, m + 1, r);    // Building Rigth Children
        
        // Building Node (Sum Operation) 
        segTree[p] = segTree[lc] + segTree[rc];
    }
}

// Call using update(1, 1, N, id, value) (id need to be 1-Based)
void update(int p,int l, int r, int id, int value){
    if(l == r){ // Updating Leaf
        segTree[p] = value;
    }
    else{
        int m = (l+r)/2;
        int lc = 2*p;
        int rc = lc + 1;

        // Modified Leaf is on the left.
        if(id <= m) update(lc, l, m, id, value);

        // Modified Leaf is on the rigth.
        else update(rc, m + 1, r, id, value);

        // Update Node
        segTree[p] = segTree[lc] + segTree[rc];
    }
}

// Call using query(1, 1, N, ql, qr) (ql and qr need to be 1-Based)
int query(int p, int l, int r, int ql, int qr){
    if(ql <= l && r <= qr){ // This node is inside the range answer
        return segTree[p];
    }
    else{
        int m = (l+r)/2;
        int lc = 2*p;
        int rc = lc + 1;

        // Our answer is just in the Left Children
        if(qr <= m) return query(lc, l, m, ql, qr);

        // Our answer is just in the Rigth Children
        else if(ql > m) return query(rc, m + 1, r, ql, qr);

        // Our answer is an intersection of the 2 sides
        else return query(lc, l, m, ql, qr) + query(rc, m + 1, r, ql, qr);
    }
}

// Range update [L,R]. It only works if the result converges. If there is a common value for the whole range [L,R] use Lazy Propagation.
void updateRange(int p, int l, int r, int ql, int qr){
    if(l == r){
        segTree[p] = value; // This value will vary according to each position of the "v" array
    }
    else{
        int m = (l+r)/2;
        int lc = 2*p;
        int rc = lc + 1;

        if(qr <= m) updateRange(lc, l, m, ql, qr);
        else if(ql > m) updateRange(rc, m + 1, r, ql, qr);
        else{
            updateRange(lc, l, m, ql, qr);
            updateRange(rc, m + 1, r, ql, qr);
        }
        segTree[p] = segTree[lc] + segTree[rc];
    }
}

/*

Time Complexity

build       -> O(n)
update      -> O(logn)
query       -> O(logn)
updateRange -> O(n)

Links:

https://cp-algorithms.com/data_structures/segment_tree.html

*/