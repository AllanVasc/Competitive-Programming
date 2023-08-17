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
    int mx, mn, sum;
    node(){}
    node(int val){
        mx = mn = sum = val;
    }
    node(node a, node b){
        mx = max(a.mx, b.mx);
        mn = min(a.mn, b.mn);
        sum = a.sum + b.sum;
    }
};

const int ms = 1e5 + 10;
node seg[4 * ms];
int lazy[4 * ms];
vector<int> v;

void build(int p, int l, int r){
    if(l == r){
        seg[p] = node(v[l]);
        lazy[p] = -1;
    }
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
    if(lazy[p] == -1) return;
    seg[p].mx = seg[p].mn = lazy[p];
    seg[p].sum = (r - l + 1) * lazy[p];
    if(l != r){
        lazy[2*p] = lazy[p];
        lazy[2*p + 1] = lazy[p];
    }
    lazy[p] = -1;
}

void updateMod(int p, int l, int r, int ql, int qr, int x){
    propagate(p, l, r);
    if(l > qr || r < ql || seg[p].mx < x) return;
    if(l >= ql && r <= qr && (seg[p].mn == seg[p].mx)){
        lazy[p] = seg[p].mn % x;
        propagate(p, l, r);
        return;
    }
    int m = (l + r) >> 1;
    int lc = 2*p;
    int rc = lc + 1;
    updateMod(lc, l, m, ql, qr, x);
    updateMod(rc, m + 1, r, ql, qr, x);
    seg[p] = node(seg[lc], seg[rc]);
}

void update(int p, int l, int r, int ql, int qr, int x){
    propagate(p, l, r);
    if(l > qr || r < ql) return;
    if(l >= ql && r <= qr){
        lazy[p] = x;
        propagate(p, l, r);
        return;
    }
    int m = (l + r) >> 1;
    int lc = 2*p;
    int rc = lc + 1;
    update(lc, l, m, ql, qr, x);
    update(rc, m + 1, r, ql, qr, x);
    seg[p] = node(seg[lc], seg[rc]);
}
int query(int p, int l, int r, int ql, int qr){
    propagate(p, l, r);
    if(l > qr || r < ql) return 0;
    if(l >= ql && r <= qr) return seg[p].sum;
    int m = (l + r) >> 1;
    int lc = 2*p;
    int rc = lc + 1;
    return query(lc, l, m, ql, qr) + query(rc, m + 1, r, ql, qr);
}

signed main() {
    optimize;
    int n, q;
    cin >> n >> q;
    v.assign(n, 0);
    for(int i = 0; i < n; i++) cin >> v[i];
    memset(lazy, -1, sizeof lazy);
    build(1, 0, n - 1);
    while(q--){
        int cmd; cin >> cmd;
        if(cmd == 1){
            int l, r; cin >> l >> r;
            l--, r--;
            cout << query(1, 0, n - 1, l, r) << '\n';
        }
        else if(cmd == 2){
            int l, r, x;
            cin >> l >> r >> x;
            l--, r--;
            updateMod(1, 0, n - 1, l, r, x);
        }
        else{
            int k, x;
            cin >> k >> x;
            k--;
            update(1, 0, n - 1, k, k, x);
        }
    }
    return 0;
}