#include <bits/stdc++.h>
using namespace std;

#define int long long
vector<int> v;

// Implementation of a Recursive Segment Tree with Lazy Propagation (Sum Operation)
// RANGE UPDATE [l,r], RANGE QUERY [l,r]
class segTree{
    vector<int> seg, lazy;

public:
    segTree(int n){ // n = v.size()
        seg.assign(4*n, 0);
        lazy.assign(4*n, 0);
        build(1, 0, n - 1);
    }

    // Call using update(1, 0, n - 1, ql, qr, x)
    void update(int p, int l, int r, int ql, int qr, int x){
        propagate(p, l, r);
        if(r < ql || l > qr) return;
        if(ql <= l && r <= qr){
            lazy[p] = x;
            propagate(p,l,r);
        }
        else{
            int m = (l + r)/2;
            int lc = 2*p;
            int rc = lc + 1;
            update(lc, l, m, ql, qr, x);
            update(rc, m + 1, r, ql, qr, x);
            seg[p] = seg[lc] + seg[rc];
        }
    }
    // Call using query(1, 0, n - 1, ql, qr)
    int query(int p, int l, int r, int ql, int qr){
        propagate(p, l, r);
        if(r < ql || l > qr) return 0;
        if(ql <= l && r <= qr) return seg[p];
        int m = (l+r)/2;
        int lc = 2*p;
        int rc = lc + 1;
        return query(lc, l, m, ql, qr) + query(rc , m + 1, r, ql, qr);
    }

private:
    void build(int p, int l, int r){
        if(l == r){
            seg[p] = v[l];
            lazy[p] = 0;
        }
        else{
            int m = (l+r)/2;
            int lc = 2*p;
            int rc = lc + 1;
            build(lc, l, m);
            build(rc, m + 1, r);
            seg[p] = seg[lc] + seg[rc];
        }
    }
    void propagate(int p, int l, int r){
        if(lazy[p] == 0) return;
        seg[p] += (r - l + 1) * lazy[p];
        if(l != r){
            lazy[2*p] += lazy[p];
            lazy[2*p + 1] += lazy[p];
        }
        lazy[p] = 0;
    }
};

/*

Time Complexity:

build       -> O(n)
update      -> O(logn)
query       -> O(logn)

Links:

https://cp-algorithms.com/data_structures/segment_tree.html
https://www.youtube.com/watch?v=xuoQdt5pHj0
https://www.youtube.com/watch?v=UKH4Zgfa4kI
https://www.youtube.com/watch?v=3gPcs6PZPdk

*/