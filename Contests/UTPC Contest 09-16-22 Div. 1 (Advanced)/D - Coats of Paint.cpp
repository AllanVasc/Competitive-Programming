// 
#include <bits/stdc++.h>
using namespace std;
  
#define int long long
  
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

vector<int> v;

class segTree{
    vector<int> seg;
    vector<int> lazy;

public:
    // n = number of elements or v.size() - 1
    segTree(int n){
        seg.assign(4*n, 0);
        lazy.assign(4*n, 0);
        build(1,1,n);
    }
    // Call using update(1,1,n,ql,qr,value) (ql and qr need to be 1-Based)
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

    int n;
    cin >> n;
    v.assign(n+2, 0);
    segTree seg(n);

    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        int l,r;
        cin >> l >> r;
        seg.update(1,1,n,l,r,1);
    }
    
    int max_value = 0;
    int answ = 1;
    for(int i = 1; i <= n; i++){
        int aux = seg.query(1,1,n,i,i);
        if(max_value < aux){
            max_value = aux;
            answ = i;
        }
    }

    cout << answ << '\n';
    return 0;
}