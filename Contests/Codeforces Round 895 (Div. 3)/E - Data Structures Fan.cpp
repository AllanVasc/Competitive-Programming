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
    int xor0, xor1;
    node(int xor0, int xor1) : xor0(xor0), xor1(xor1){}
    node(node a, node b){
        xor0 = a.xor0 ^ b.xor0;
        xor1 = a.xor1 ^ b.xor1;
    }
};

const int ms = 1e5 + 10;
vector<node> seg;
vector<int> v, state, lazy;

void build(int p, int l, int r){
    if(l == r){
        seg[p] = (state[l] ? node(0, v[l]) : node(v[l], 0));
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
    swap(seg[p].xor0, seg[p].xor1);
    if(l != r){
        lazy[2 * p] ^= lazy[p];
        lazy[2 * p + 1] ^= lazy[p];
    }
    lazy[p] = 0;
}

void update(int p, int l, int r, int ql, int qr){
    propagate(p, l, r);
    if(r < ql || l > qr) return;
    if(ql <= l && r <= qr){
        lazy[p] ^= 1;
        propagate(p,l,r);
    }
    else{
        int m = (l + r)/2;
        int lc = 2*p;
        int rc = lc + 1;
        update(lc, l, m, ql, qr);
        update(rc, m + 1, r, ql, qr);
        seg[p] = node(seg[lc], seg[rc]);
    }
}

node query(int p, int l, int r, int ql, int qr){
    propagate(p, l, r);
    if(r < ql || l > qr) return node(0, 0);
    if(ql <= l && r <= qr) return seg[p];
    int m = (l+r)/2;
    int lc = 2*p;
    int rc = lc + 1;
    return node(query(lc, l, m, ql, qr), query(rc , m + 1, r, ql, qr));
}

signed main() {
    optimize;
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        v.assign(n, 0);
        state.assign(n, 0);
        seg.assign(4 * n, node(0, 0));
        lazy.assign(4 * n, 0);
        for(int i = 0; i < n; i++) cin >> v[i];
        string s; cin >> s;
        for(int i = 0; i < n; i++) state[i] = s[i] - '0';
        build(1, 0, n - 1);
        int q; cin >> q;
        while(q--){
            int cmd; cin >> cmd;
            if(cmd == 1){
                int l, r;
                cin >> l >> r;
                l--, r--;
                update(1, 0, n - 1, l, r);
            }
            else{
                int type; cin >> type;
                node answ = query(1, 0, n - 1, 0, n - 1);
                cout << (type ? answ.xor1 : answ.xor0) << " ";
            }
        }
        cout << '\n';
    }
    return 0;
}