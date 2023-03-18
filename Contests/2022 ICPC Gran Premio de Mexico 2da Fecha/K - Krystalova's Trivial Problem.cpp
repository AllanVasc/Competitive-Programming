#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int MAXN = 1e5 + 100;
vector<int> v;

struct Node{
    int sqSum = 0;
    int sum = 0;
};

Node seg[4 * MAXN];
int lazy[4 * MAXN];

void build(int p, int l, int r){
    if(l == r){
        seg[p].sqSum = v[l] * v[l] % MOD;
        seg[p].sum = v[l] % MOD;
        lazy[p] = 0;
    }
    else{
        int m = (l + r) >> 1;
        int lc = 2 * p;
        int rc = lc + 1;
        build(lc, l, m);
        build(rc, m + 1, r);

        seg[p].sqSum = (seg[lc].sqSum + seg[rc].sqSum) % MOD;
        seg[p].sum = (seg[lc].sum + seg[rc].sum) % MOD;
        lazy[p] = 0;
    }
}

void propagate(int p, int l, int r){
    if(lazy[p] == 0) return;

    int p1 = seg[p].sqSum % MOD;
    int p2 = 2 * lazy[p] % MOD * seg[p].sum % MOD;
    int p3 = (r - l + 1) % MOD * lazy[p] % MOD * lazy[p] % MOD;
    
    seg[p].sqSum = (((p1 + p2) % MOD) + p3) % MOD;
    seg[p].sum = ( seg[p].sum + (r - l + 1) % MOD * lazy[p] % MOD) % MOD;

    if(l != r){
        lazy[2*p] = (lazy[2*p] + lazy[p]) % MOD;
        lazy[2*p + 1] = (lazy[2*p + 1] + lazy[p]) % MOD;
    }
    lazy[p] = 0;
}

void update(int p, int l, int r, int ql, int qr, int x){
    propagate(p, l, r);
    if(l > qr || r < ql) return;
    if(l >= ql && r <= qr){
        lazy[p] = (lazy[p] + x) % MOD;
        propagate(p, l, r);
    }
    else{
        int m = (l + r) >> 1;
        int lc = 2*p;
        int rc = lc + 1;
        update(lc, l, m, ql, qr, x);
        update(rc, m + 1, r, ql, qr, x);

        seg[p].sqSum = (seg[lc].sqSum + seg[rc].sqSum) % MOD;
        seg[p].sum = (seg[lc].sum + seg[rc].sum) % MOD;
    }
}

int query(int p, int l, int r, int ql, int qr){
    propagate(p, l, r);
    if(l > qr || r < ql) return 0;
    if(l >= ql && r <= qr) return seg[p].sqSum % MOD;

    int m = (l + r) >> 1;
    int lc = 2*p;
    int rc = lc + 1;

    return ((query(lc, l, m, ql, qr) + query(rc, m + 1, r, ql ,qr)) % MOD);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, q;
    cin >> n >> q;
    v.assign(n, 0);
    for(int i = 0; i < n; i++) cin >> v[i];
    build(1, 0, n - 1);

    while(q--){
        char cmd;
        cin >> cmd;
        if(cmd == 'u'){
            int l, r, x;
            cin >> l >> r >> x;
            l--, r--;
            update(1, 0, n - 1, l, r, x);
        }
        else{
            int l, r;
            cin >> l >> r;
            l--, r--;
            int answ = (query(1, 0, n - 1, l, r) + MOD) % MOD;
            cout << answ << '\n';
        }
    }
    return 0;
}