#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 20000; // Size of v (Array used to construct)

// Implementation of a Recursive Segment Tree (1-Based) (Sum Operation)
ll segTree[4*MAX];

// Array used to construct Segtree (Need to be 1-Based)
vector<ll> v;

// SINGLE-ELEMENT MODIFY, RANGE QUERY [l,r]

// Call using build(1,1,N) (N = v.size() - 1)
void build(int p, int l, int r){

    // Building Leaf
    if(l == r){
        segTree[p] = v[r];
    }
    else{

        int m = (l+r)/2;
        int lc = 2*p;
        int rc = lc + 1;

        // Building Left Children
        build(lc,l,m);

        // Building Rigth Children
        build(rc,m+1,r);
        
        // Building Node (Sum Operation) 
        segTree[p] = segTree[lc] + segTree[rc];

    }
}

// Call using update(1,1,N,idx,value) (idx need to be 1-Based)
void update(int p,int l, int r, int idx, ll value){

    // Updating Leaf
    if(l == r){
        segTree[p] = value;
    }
    else{

        int m = (l+r)/2;
        int lc = 2*p;
        int rc = lc + 1;

        // Modified Leaf is on the left.
        if(idx <= m){

            update(lc,l,m,idx,value);
        }
        // Modified Leaf is on the rigth.
        else{

            update(rc,m+1,r,idx,value);
        }

        // Update Node
        segTree[p] = segTree[lc] + segTree[rc];

    }
}

// Call using query(1,1,N,ql,qr) (ql and qr need to be 1-Based)
ll query(int p, int l, int r, int ql, int qr){

    // This node is inside the range answer
    if(ql <= l && r <= qr){
        return segTree[p];
    }
    else{

        int m = (l+r)/2;
        int lc = 2*p;
        int rc = lc + 1;

        // Our answer is just in the Left Children
        if(qr <= m){

            return query(lc,l,m,ql,qr);
        }
        // Our answer is just in the Rigth Children
        else if(ql > m){

            return query(rc,m+1,r,ql,qr);
        }
        else{

            // Our answer is an intersection of the 2 sides
            return query(lc,l,m,ql,qr) + query(rc,m+1,r,ql,qr);
        }
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

        if(qr <= m){
            updateRange(lc, l, m, ql, qr);
        }
        else if(ql > m){
            updateRange(rc, m+1, r, ql, qr);
        }
        else{
            updateRange(lc,l,m,ql,qr);
            updateRange(rc,m+1,r,ql,qr);
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