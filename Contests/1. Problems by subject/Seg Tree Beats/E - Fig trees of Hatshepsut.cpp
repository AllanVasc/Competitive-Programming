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

const int ms = 2*1e5 + 100;
node seg[4 * ms];
int lazy[4 * ms];
vector<int> v, phi;

void build(int p, int l, int r){
    if(l == r){
        seg[p] = node(v[l]);
        lazy[p] = 0;
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
    if(!lazy[p]) return;
    seg[p].mx = seg[p].mn = lazy[p];
    seg[p].sum = (r - l + 1) * lazy[p];
    if(l != r){
        lazy[2*p] = lazy[p];
        lazy[2*p + 1] = lazy[p];
    }
    lazy[p] = 0;
}

void update1(int p, int l, int r, int ql, int qr){
    propagate(p, l, r);
    if(l > qr || r < ql || seg[p].mx == 1) return;
    if(l >= ql && r <= qr && (seg[p].mn == seg[p].mx)){
        lazy[p] = phi[seg[p].mx];
        propagate(p, l, r);
        return;
    }
    int m = (l + r) >> 1;
    int lc = 2*p;
    int rc = lc + 1;
    update1(lc, l, m, ql, qr);
    update1(rc, m + 1, r, ql, qr);
    seg[p] = node(seg[lc], seg[rc]);
}

void update2(int p, int l, int r, int ql, int qr, int x){
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
    update2(lc, l, m, ql, qr, x);
    update2(rc, m + 1, r, ql, qr, x);
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

void sievePhi(int n){
    phi.assign(n + 1, 0);
    for(int i = 0; i <= n; i++) phi[i] = i;
    for(int i = 2; i <= n; i++){
        if(phi[i] == i){
            for(int j = i; j <= n; j += i){
                phi[j] -= phi[j] / i;
            }
        }
    }
}

signed main() {
    optimize;
    int n, q;
    cin >> n >> q;
    v.assign(n, 0);
    for(int i = 0; i < n; i++) cin >> v[i];
    sievePhi(1e6 + 10);
    build(1, 0, n - 1);
    while(q--){
        int cmd, l, r;
        cin >> cmd >> l >> r;
        l--, r--;
        if(cmd == 1){
            update1(1, 0, n - 1, l, r);
        }
        else if(cmd == 2){
            int x; cin >> x;
            update2(1, 0, n - 1, l, r, x);
        }
        else{
            cout << query(1, 0, n - 1, l, r) << '\n';
        }
    }
    return 0;
}