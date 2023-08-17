// CSES - Range Updates and Sums
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = 0x3f3f3f3f;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const ll INF = 1e9 + 7;

vector<int> v;

class segTree{
    vector<int> seg;
    vector<ii> lazy;

public:
    // n = number of elements or v.size() - 1
    segTree(int n){
        seg.resize(4*n);
        lazy.resize(4*n);
        build(1,1,n);
    }
    // Call using update(1,1,n,ql,qr,value) (ql and qr need to be 1-Based)
    void update(int p, int l, int r, int ql, int qr, int value,int op){
        propagate(p,l,r);
        if(r < ql || l > qr) return;
        if(ql <= l && r <= qr){
            lazy[p] = {value,op};
            propagate(p,l,r);
        }
        else{
            int m = (l+r)/2;
            int lc = 2*p;
            int rc = lc + 1;

            update(lc,l,m,ql,qr,value,op);
            update(rc,m+1,r,ql,qr,value,op);

            seg[p] = seg[lc] + seg[rc];
        }
    }
    // Call using query(1,1,n,ql,qr) (ql and qr need to be 1-Based)
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
            lazy[p] = {0,0};
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
        if(lazy[p].second == 0) return;

        if(lazy[p].second == 1){
            seg[p] += (r-l+1)*lazy[p].first;
            if(l != r){
                if(lazy[2*p].second == 2){
                    lazy[2*p] = {lazy[2*p].first + lazy[p].first, 2};
                    lazy[2*p + 1] = {lazy[2*p + 1].first + lazy[p].first, 2};;
                }
                else{
                    lazy[2*p] = {lazy[2*p].first + lazy[p].first, 1};
                    lazy[2*p + 1] = {lazy[2*p + 1].first + lazy[p].first, 1};
                }
            }
        }
        else{
            seg[p] = (r-l+1)*lazy[p].first;
            if(l != r){
                lazy[2*p] = {lazy[p].first, lazy[p].second};
                lazy[2*p + 1] = {lazy[p].first, lazy[p].second};;
            }
        }
        
        lazy[p] = {0,0};
    }
};

int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q;

    cin >> n >> q;
    v.resize(n+1);

    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }

    segTree seg(n);
    for(int i = 0; i < q; i++){
        int op,a,b;
        cin >> op >> a >> b;
        if(op == 3){
            cout << seg.query(1,1,n,a,b) << '\n';
        }
        else{
            int x;
            cin >> x;
            seg.update(1,1,n,a,b,x,op);
        }
    }
    return 0;
}
