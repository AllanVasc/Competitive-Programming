#include <bits/stdc++.h>
using namespace std;

#define int long long
#define optimize ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define iii tuple<int,int,int>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

struct node{
    int sum, lazy, sz; // Lazy just for sum
    int mx1, mx2, cntMx1;
    int mn1, mn2, cntMn1;
    node(int x = 0){
        sum = mx1 = mn1 = x;
        mx2 = -INF;
        mn2 = INF;
        cntMx1 = cntMn1 = sz = 1;
        lazy = 0;
    }
    node(const node & l, const node & r) {
        sum = l.sum + r.sum, sz = l.sz + r.sz;
        lazy = 0;
        if(l.mn1 > r.mn1){ // Min
            mn1 = r.mn1;
            cntMn1 = r.cntMn1;
            mn2 = min(l.mn1, r.mn2);
        } else if(l.mn1 < r.mn1){
            mn1 = l.mn1;
            cntMn1 = l.cntMn1;
            mn2 = min(r.mn1, l.mn2);
        } else{
            mn1 = l.mn1;
            cntMn1 = l.cntMn1 + r.cntMn1;
            mn2 = min(l.mn2, r.mn2);
        }
        if(l.mx1 < r.mx1){ // Max
            mx1 = r.mx1;
            cntMx1 = r.cntMx1;
            mx2 = max(l.mx1, r.mx2);
        } else if(l.mx1 > r.mx1){
            mx1 = l.mx1;
            cntMx1 = l.cntMx1;
            mx2 = max(r.mx1, l.mx2);
        } else{
            mx1 = l.mx1;
            cntMx1 = l.cntMx1 + r.cntMx1;
            mx2 = max(l.mx2, r.mx2);
        }
    }
    void setMin(int x){
        if(x >= mx1) return;
        sum += (x - mx1) * cntMx1;
        if(mn1 == mx1) mn1 = x;
        if(mn2 == mx1) mn2 = x;
        mx1 = x;
    }
    void setMax(int x){
        if(x <= mn1) return;
        sum += (x - mn1) * cntMn1;
        if(mx1 == mn1) mx1 = x;
        if(mx2 == mn1) mx2 = x;
        mn1 = x;
    }
    void setSum(int x){
        mx1 += x, mx2 += x;
        mn1 += x, mn2 += x;
        sum += x * sz;
        lazy += x;
    }
};

const int ms = 1e6;
node seg[4 * ms];
vector<int> v;

void build(int p, int l, int r){
    if(l == r) seg[p] = node(v[l]);
    else{
        int m = (l + r) >> 1;
        int lc = 2*p;
        int rc = lc + 1;
        build(lc, l, m);
        build(rc, m + 1, r);
        seg[p] = node(seg[lc], seg[rc]);
    }
}

void propagate(int p, int l, int r){
    if(l == r) return;
    for(int k = 0; k < 2; k++){
        if(seg[p].lazy) seg[2*p + k].setSum(seg[p].lazy);
        seg[2*p + k].setMin(seg[p].mx1);
        seg[2*p + k].setMax(seg[p].mn1);
    }
    seg[p].lazy = 0;
}

void updateMin(int p, int l, int r, int ql, int qr, int x){
    if(l > qr || r < ql || seg[p].mx1 <= x) return;
    if(l >= ql && r <= qr && seg[p].mx2 < x){
        seg[p].setMin(x); return;
    }
    propagate(p, l, r);
    int m = (l + r) >> 1;
    int lc = 2*p;
    int rc = lc + 1;
    updateMin(lc, l, m, ql, qr, x);
    updateMin(rc, m + 1, r, ql, qr, x);
    seg[p] = node(seg[lc], seg[rc]);
}

void updateMax(int p, int l, int r, int ql, int qr, int x){
    if(l > qr || r < ql || seg[p].mn1 >= x) return;
    if(l >= ql && r <= qr && seg[p].mn2 > x){
        seg[p].setMax(x); return;
    }
    propagate(p, l, r);
    int m = (l + r) >> 1;
    int lc = 2*p;
    int rc = lc + 1;
    updateMax(lc, l, m, ql, qr, x);
    updateMax(rc, m + 1, r, ql, qr, x);
    seg[p] = node(seg[lc], seg[rc]);
}

void updateSum(int p, int l, int r, int ql, int qr, int x){
    if(l > qr || r < ql) return;
    if(l >= ql && r <= qr){
        seg[p].setSum(x); return;
    }
    propagate(p, l, r);
    int m = (l + r) >> 1;
    int lc = 2*p;
    int rc = lc + 1;
    updateSum(lc, l, m, ql, qr, x);
    updateSum(rc, m + 1, r, ql, qr, x);
    seg[p] = node(seg[lc], seg[rc]);
}

pair<pair<int,int>, int> query(int p, int l, int r, int ql, int qr){
    if(l > qr || r < ql) return {{INF, -INF}, 0};
    if(l >= ql && r <= qr) return {{seg[p].mn1, seg[p].mx1}, seg[p].sum};
    propagate(p, l, r);
    int m = (l + r) >> 1;
    int lc = 2*p;
    int rc = lc + 1;
    auto L = query(lc, l, m, ql, qr), R = query(rc, m + 1, r, ql, qr);
    return { {min(L.first.first, R.first.first),
              max(L.first.second, R.first.second)},
              L.second + R.second };
}

signed main() {
    optimize;
    int n, q;
    cin >> n >> q;
    v.assign(n, 0);
    for(int i = 0; i < n; i++) cin >> v[i];
    build(1, 0, n - 1);
    while(q--){
        int cmd; cin >> cmd;
        if(cmd == 0){
            int l, r, x; cin >> l >> r >> x;
            r--;
            updateMin(1, 0, n - 1, l, r, x);
        }
        else if(cmd == 1){
            int l, r, x; cin >> l >> r >> x;
            r--;
            updateMax(1, 0, n - 1, l, r, x);
        }
        else if(cmd == 2){
            int l, r, x; cin >> l >> r >> x;
            r--;
            updateSum(1, 0, n - 1, l, r, x);
        }
        else{
            int l, r; cin >> l >> r;
            r--;
            auto answ = query(1, 0, n - 1, l, r);
            cout << answ.second << '\n';
        }
    }
    return 0;
}