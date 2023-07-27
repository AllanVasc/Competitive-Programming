#include <bits/stdc++.h>
using namespace std;

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

const int ms = 1e5 + 100;
vector<vector<int>> g;
int par[ms], head[ms], sz[ms];
int seg[4 * ms], lazy[4 * ms];
int pos[ms];
int t;

void propagate(int p, int l, int r){
    if(lazy[p] == 0) return;
    seg[p] += (r - l + 1) * lazy[p];
    if(l != r){
        lazy[2 * p] += lazy[p];
        lazy[2 * p + 1] += lazy[p];
    }
    lazy[p] = 0;
}

void update(int p, int l, int r, int ql, int qr, int x){
    propagate(p, l, r);
    if(r < ql || l > qr) return;
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
    seg[p] = seg[lc] + seg[rc];
}

int query(int p, int l, int r, int ql, int qr){
    propagate(p, l, r);
    if(l > qr || r < ql) return 0;
    if(l >= ql && r <= qr) return seg[p];
    int m = (l + r) >> 1;
    int lc = (2 * p);
    int rc = lc + 1;
    return query(lc, l, m, ql, qr) + query(rc, m + 1, r, ql, qr);
}

void dfs_sz(int u, int p = -1){
    sz[u] = 1;
    for(auto & v : g[u]){
        if(v == p) continue;
        dfs_sz(v, u);
        sz[u] += sz[v];
        if(g[u][0] == p || sz[v] > sz[g[u][0]]) swap(v, g[u][0]);
    }
}

void dfs_hld(int u, int p = -1){
    pos[u] = t++;
    for(auto v : g[u]){
        if(v == p) continue;
        par[v] = u;
        head[v] = (v == g[u][0] ? head[u] : v);
        dfs_hld(v, u);
    }
}

void build_hld(int root = 0){
    dfs_sz(root);
    t = 0;
    head[root] = root;
    par[root] = root;
    dfs_hld(root);
}

void update_path(int a, int b, int x){
    if(pos[a] < pos[b]) swap(a, b);
    if(head[a] == head[b]){
        update(1, 0 , t - 1, pos[b], pos[a], x);
        return;
    }
    update(1, 0, t - 1, pos[head[a]], pos[a], x);
    update_path(par[head[a]], b, x);
}

int query_path(int a, int b){
    if(pos[a] < pos[b]) swap(a, b);
    if(head[a] == head[b]){
        return query(1, 0, t - 1, pos[b], pos[a]);
    }
    return query(1, 0 , t - 1, pos[head[a]], pos[a]) + query_path(par[head[a]], b);
}


int32_t main() {
    optimize;

    int n, q;
    cin >> n >> q;
    g.assign(n, vector<int>());
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    build_hld();
    while(q--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--, b--, c--, d--;
        update_path(a, b, 1);
        cout << query_path(c, d) << '\n';
        update_path(a, b, -1);
    }
    return 0;
}