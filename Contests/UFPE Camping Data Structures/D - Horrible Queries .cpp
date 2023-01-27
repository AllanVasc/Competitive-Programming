// D - Horrible Queries 
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int inf = 0x3f3f3f3f;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;

const int MAX = 100000 + 5;
int v[MAX];

// 
class segTree{
    vector<int> seg;
    vector<int> lazy;

public:

    segTree(int n){
        seg.resize(4*n);
        lazy.resize(4*n);
        build(1,1,n);
    }

    void update(int p, int l, int r, int ql, int qr, int value){
        propagate(p,l,r);
        if(r < ql || l > qr) return;
        if(ql <= l && r <= qr){
            lazy[p] = value;
            propagate(p,l,r);
        }
        else{
            int m = (l+r)/2;
            int lc = 2*p;
            int rc = lc + 1;

            update(lc,l,m,ql,qr,value);
            update(rc,m+1,r,ql,qr,value);

            seg[p] = seg[lc] + seg[rc];
        }
    }

    int query(int p, int l, int r, int ql, int qr){
        propagate(p,l,r);
        if(r < ql || l > qr) return 0;
        if(ql <= l && r <= qr) return seg[p];

        int m = (l+r)/2;
        int lc = 2*p;
        int rc = lc + 1;

        return query(lc,l,m,ql,qr) + query(rc,m+1,r,ql,qr);
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

            build(lc,l,m);
            build(rc,m+1,r);

            seg[p] = seg[lc] + seg[rc];
        }
    }

    void propagate(int p, int l, int r){
        if(lazy[p] == 0) return;

        seg[p] += (r-l+1)*lazy[p];
        if(l != r){
            lazy[2*p] += lazy[p];
            lazy[2*p + 1] += lazy[p];
        }
        lazy[p] = 0;
    }
};

int32_t main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n, c;
        cin >> n >> c;

        segTree seg(n);

        for(int i = 0; i < c; i++){
            int op;
            cin >> op;
            if(op == 0){
                int ql,qr, value;
                cin >> ql >> qr >> value;
                seg.update(1,1,n,ql,qr,value);
            }
            else{
                int ql,qr;
                cin >> ql >> qr;
                cout << seg.query(1,1,n,ql,qr) << '\n';
            }
        }
    }

    return 0;
}
