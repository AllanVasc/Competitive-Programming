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

const int ms = 500000 + 1;
vector<vector<int>> g;
int seg[4 * ms], lazy[4 * ms];
int sz[ms], par[ms], head[ms], pos[ms];
int t;
void build(int p, int l, int r){
    lazy[p] = -1;
    if(l == r){
        seg[p] = 0;
    }
    else{
        int m= (l + r) >> 1;
        int lc = 2*p;
        int rc = 2*p + 1;
        build(lc, l, m);
        build(rc, m + 1, r);
        seg[p] = seg[lc] + seg[rc];
    }
}

void propagate(int p, int l, int r){
    if(lazy[p] == -1) return;
    seg[p] = (r - l + 1) * lazy[p];
    if(l != r){
        lazy[2*p] = lazy[p];
        lazy[2*p + 1] = lazy[p];
    }
    lazy[p] = -1;
}

void update(int p, int l, int r, int ql, int qr, int x){
    propagate(p, l, r);
    if(l >= ql && r <= qr){
        lazy[p] = x;
        propagate(p, l, r);
        return;
    }
    if(l > qr || r < ql) return;
    int m = (l + r) >> 1;
    int lc = 2*p;
    int rc = lc + 1;
    update(lc, l, m, ql, qr, x);
    update(rc, m + 1, r, ql, qr, x);
    seg[p] = seg[lc] + seg[rc];
}

int query(int p, int l, int r, int ql, int qr){
    propagate(p, l, r);
    if(l >= ql && r <= qr) return seg[p];
    int m = (l + r) >> 1;
    int lc = 2*p;
    int rc = lc + 1;
    if(qr <= m) return query(lc, l, m, ql, qr);
    if(ql > m) return query(rc, m + 1, r, ql, qr);
    return query(lc, l, m, ql, qr) + query(rc, m + 1, r, ql, qr);
}

void dfs_sz(int u, int p = -1){
    sz[u] = 1;
    for(auto & v : g[u]){
        if(v == p) continue;
        par[v] = u;
        dfs_sz(v, u);
        sz[u] += sz[v];
        if(g[u][0] == p || sz[v] > sz[g[u][0]]) swap(v, g[u][0]);
    }
}

void dfs_hld(int u, int p = -1){
    pos[u] = t++;
    for(auto v : g[u]){
        if(v == p) continue;
        head[v] = (v == g[u][0] ? head[u] : v);
        dfs_hld(v, u);
    }
}

void build_hld(int root = 0){
    t = 0;
    head[root] = root;
    par[root] = root;
    dfs_sz(root);
    dfs_hld(root);
    build(1, 0 ,t - 1);
}

void update_path(int a, int b, int x){
    if(pos[a] < pos[b]) swap(a, b);
    if(head[a] == head[b]){
        update(1, 0, t - 1, pos[b], pos[a], x);
        return;
    }
    update(1, 0, t - 1, pos[head[a]], pos[a], x);
    update_path(par[head[a]], b, x);
}

void update_subtree(int a, int x){
    update(1, 0, t - 1, pos[a], pos[a] + sz[a] - 1, x);
}

signed main() {
    optimize;
    int n;
    cin >> n;
    g.assign(n, vector<int>());
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    build_hld();
    int q; cin >> q;
    while(q--){
        int cmd, u;
        cin >> cmd >> u;
        u--;
        if(cmd == 1){
            update_subtree(u, 1);
        }
        else if(cmd == 2){
            update_path(0, u, 0);
        }
        else{
            cout << query(1, 0 ,t - 1, pos[u], pos[u]) << '\n';
        }
    }
    return 0;
}