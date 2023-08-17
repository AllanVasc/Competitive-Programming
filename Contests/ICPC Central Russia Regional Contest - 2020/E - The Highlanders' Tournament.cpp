#include<bits/stdc++.h>
using namespace std;

#define int long long

class SegVivos{
    vector<int> seg;

public:
    SegVivos(vector<int> & v){
        int n = v.size();
        seg.assign(4*n, 0);
        build(1, 0, n - 1);
    }

    void build(int p, int l, int r){
        if(l == r){
            seg[p] = 1;
        }
        else{
            int m = (l + r) >> 1;
            int lc = 2*p;
            int rc = lc + 1;
            build(lc, l, m);
            build(rc, m + 1, r);
            seg[p] = seg[lc] + seg[rc];
        }
    }
    
    void update(int p, int l, int r, int ql, int qr){
        if(r < ql || l > qr) return;
        if(seg[p] == 0) return;

        if(l == r){
            seg[p] = 0;
        }
        else{
            int m = (l + r) >> 1;
            int lc = 2*p;
            int rc = lc + 1;
            update(lc, l, m, ql, qr);
            update(rc, m + 1, r, ql, qr);
            seg[p] = seg[lc] + seg[rc];
        }
    }
    int descent(int p, int l, int r, int cnt){
        if(l == r) return l;
        int m = (l + r) >> 1;
        int lc = 2*p;
        int rc = lc + 1;
        if(seg[lc] >= cnt) return descent(lc, l, m, cnt);
        else return descent(rc, m + 1, r, cnt - seg[lc]);
    }
    int query(int p, int l, int r, int ql, int qr){
        if(r < ql || l > qr) return 0;
        if(ql <= l && r <= qr) return seg[p];
        int m = (l + r) >> 1;
        int lc = 2*p;
        int rc = lc + 1;
        return query(lc, l, m, ql, qr) + query(rc, m + 1, r, ql, qr);
    }
};

class SegMax{
    vector<int> seg;
    vector<int> lazy;
    vector<int> v;
public:
    SegMax(vector<int> & aux){
        int n = aux.size();
        v = aux;
        seg.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        build(1, 0, n - 1);
    }
    void update(int p, int l, int r, int ql, int qr, int val){
        propagate(p, l, r);
        if(r < ql || l > qr) return;
        if(ql <= l && r <= qr){
            lazy[p] = max(val, lazy[p]);
            propagate(p, l, r);
        }
        else{
            int m = (l + r) >> 1;
            int lc = 2*p;
            int rc = lc + 1;
            update(lc, l, m, ql, qr, val);
            update(rc, m + 1, r, ql, qr, val);

            seg[p] = max(seg[lc], seg[rc]);
        }
    }
    int query(int p, int l, int r, int ql, int qr){
        propagate(p, l, r);
        if(r < ql || l > qr) return 0;
        if(ql <= l && r <= qr) return seg[p];

        int m = (l + r) >> 1;
        int lc = 2*p;
        int rc = lc + 1;
        return max(query(lc, l, m, ql, qr) , query(rc, m + 1, r, ql, qr));
    }
private:
    void build(int p, int l, int r){
        if(l == r){
            seg[p] = v[l];
            lazy[p] = 0;
        }
        else{
            int m = (l + r) >> 1;
            int lc = 2*p;
            int rc = lc + 1;
            build(lc, l, m);
            build(rc, m + 1, r);
            seg[p] = max(seg[lc], seg[rc]);
        }
    }
    void propagate(int p, int l, int r){
        if(lazy[p] == 0) return;
        seg[p] = max(seg[p], lazy[p]);
        if(l != r){
            lazy[2 * p] = max(lazy[2 * p], lazy[p]);
            lazy[2 * p + 1] = max(lazy[2 * p + 1], lazy[p]);
        }
        lazy[p] = 0;
    }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    SegVivos vivos(v);
    SegMax mxVivos(v);

    while(q--){
        int l, r;
        cin >> l >> r;
        if(l == r) continue;
        int nl = vivos.descent(1, 0, n - 1, l);
        int nr = vivos.descent(1, 0, n - 1, r);
        if(nl == nr) continue;      // talvez??

        // cout << "nl = " << nl << "  nr = " << nr << '\n';
        int val = mxVivos.query(1, 0, n - 1, nl, nr);
        // cout << "max in range = " << val << '\n';
        mxVivos.update(1, 0, n - 1, nl, nr, val);
        vivos.update(1, 0, n - 1, nl + 1, nr);
    }

    vector<int> answ;
    for(int i = 0; i < n; i++){
        if(!vivos.query(1, 0, n - 1, i, i)) continue;
        int curr = mxVivos.query(1, 0, n - 1, i, i);
        answ.push_back(curr);
    }
    for(auto x : answ) cout << x << " ";
    cout << '\n';
    return 0;
}