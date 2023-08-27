#include <bits/stdc++.h>
using namespace std;

#define int long long
const int ms = 1e6; // Max size of v

// Implementation of a Recursive Segment Tree (0-Based) (Sum Operation)
int seg[4*ms];
vector<int> v;

// SINGLE-ELEMENT MODIFY, RANGE QUERY [l,r]

// Call using build(1, 0, N - 1) (N = v.size())
void build(int p, int l, int r){
    if(l == r) seg[p] = v[l];
    else{
        int m = (l+r)/2;
        int lc = 2*p;
        int rc = lc + 1;
        build(lc, l, m);
        build(rc, m + 1, r);
        seg[p] = seg[lc] + seg[rc];
    }
}

// Call using update(1, 0, N - 1, idx, value)
void update(int p, int l, int r, int idx, int x){
    if(l == r) seg[p] = x;
    else{
        int m = (l+r)/2;
        int lc = 2*p;
        int rc = lc + 1;
        if(idx <= m) update(lc, l, m, idx, x);
        else update(rc, m + 1, r, idx, x);
        seg[p] = seg[lc] + seg[rc];
    }
}

// Call using query(1, 0, N - 1, ql, qr)
int query(int p, int l, int r, int ql, int qr){
    if(ql <= l && r <= qr) return seg[p];
    int m = (l+r)/2;
    int lc = 2*p;
    int rc = lc + 1;
    if(qr <= m) return query(lc, l, m, ql, qr);
    else if(ql > m) return query(rc, m + 1, r, ql, qr);
    else return query(lc, l, m, ql, qr) + query(rc, m + 1, r, ql, qr);
}

// Range update [L,R]. It only works if the result converges.
// If there is a common value for the whole range [L,R] use Lazy Propagation.
void updateRange(int p, int l, int r, int ql, int qr){
    if(l == r){
        seg[p] = value; // This value will vary according to each position of the "v" array
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
        seg[p] = seg[lc] + seg[rc];
    }
}

/*

Time Complexity:

build       -> O(n)
update      -> O(logn)
query       -> O(logn)
updateRange -> O(n)

Links:

https://cp-algorithms.com/data_structures/segment_tree.html

*/