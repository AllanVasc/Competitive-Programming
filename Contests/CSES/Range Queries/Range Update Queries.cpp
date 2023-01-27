#include <bits/stdc++.h>
using namespace std;
  
#define int long long
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

struct SEG{
    vector<int> seg;
    vector<int> lazy;
    vector<int> v;

    SEG(int n, vector<int> v){
        seg.assign(4*n, 0);
        lazy.assign(4*n, 0);
        this->v = v;
        build(1, 1, n);
    }

    void update(int p, int l, int r, int ql, int qr, int value){
        propagate(p, l, r);
        if(r < ql || l > qr) return;
        if(l >= ql && r <= qr){
            lazy[p] += value;
            propagate(p, l, r);
        }
        else{
            int m = (l + r)/2;
            int lc = 2 * p;
            int rc = lc + 1;

            update(lc, l, m, ql, qr, value);
            update(rc, m + 1, r, ql, qr, value);

            seg[p] = seg[lc] + seg[rc];
        }
    }

    int query(int p, int l, int r, int ql, int qr){
        propagate(p, l, r);
        if(l > qr || r < ql) return 0;
        if(l >= ql && r <= qr){
            return seg[p];
        }
        else{
            int m = (l + r)/2;
            int lc = 2*p;
            int rc = lc + 1;

            return query(lc,l,m,ql,qr) + query(rc, m + 1, r, ql, qr);
        }
    }

private:
    void build(int p, int l, int r){
        if(l == r){
            seg[p] = v[l];
            lazy[p] = 0;
        }
        else{
            int m = (l + r)/2;
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
            lazy[2 * p] += lazy[p];
            lazy[2 * p + 1] += lazy[p];
        }
        lazy[p] = 0;
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n, q;
    cin >> n >> q;

    vector<int> v;
    v.assign(n + 1, -1);
    for(int i = 1; i <= n; i++) cin >> v[i];

    SEG segtree(n, v);

    for(int i = 0; i < q; i++){
        int command;
        cin >> command;
        if(command == 1){
            int a, b, value;
            cin >> a >> b >> value;
            segtree.update(1,1,n,a,b,value);
        }
        else{
            int k;
            cin >> k;
            cout << segtree.query(1,1,n,k,k) << '\n';
        }
    }
    return 0;
}