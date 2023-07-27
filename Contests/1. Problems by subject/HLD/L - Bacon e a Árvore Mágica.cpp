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

const int ms = 1e5 + 100;
const int LOG = 20;
vector<vector<int>> g;
int seg[4 * ms], lazy[4 * ms];
int sz[ms], pos[ms], head[ms], par[ms];
int dp[ms][LOG], depth[ms];
int t;

void build(int p, int l, int r){
    lazy[p] = -1;
    if(l == r){
        seg[p] = 0;
    }
    else{
        int m = (l + r) >> 1;
        int lc = 2 * p;
        int rc = lc + 1;
        build(lc, l, m);
        build(rc, m + 1, r);
        seg[p] = seg[lc] + seg[rc];
    }
}

void propagate(int p, int l, int r){
    if(lazy[p] == -1) return;
    seg[p] = (r - l + 1) * lazy[p];
    if(l != r){
        lazy[2 * p] = lazy[p];
        lazy[2 * p + 1] = lazy[p];
    }
    lazy[p] = -1;
}

void update(int p, int l, int r, int ql, int qr, int val){
    propagate(p, l, r);
    if(r < ql || l > qr) return;
    if(ql <= l && r <= qr){
        lazy[p] = val;
        propagate(p,l,r);
    }
    else{
        int m = (l + r)/2;
        int lc = 2*p;
        int rc = lc + 1;

        update(lc, l, m, ql, qr, val);
        update(rc, m + 1, r, ql, qr, val);

        seg[p] = seg[lc] + seg[rc];
    }
}

int query(int p, int l, int r, int ql, int qr){
    propagate(p, l, r);
    if(r < ql || l > qr) return 0;
    if(ql <= l && r <= qr) return seg[p];

    int m = (l+r)/2;
    int lc = 2*p;
    int rc = lc + 1;

    return query(lc, l, m, ql, qr) + query(rc , m + 1, r, ql, qr);
}

void dfs_sz(int u, int p = -1){
    sz[u] = 1;
    for(auto & v : g[u]){
        if(v == p) continue;
        par[v] = u;
        dp[v][0] = u;
        for(int i = 1; i < LOG; i++){
            dp[v][i] = dp[dp[v][i - 1]][i - 1];
        }
        depth[v] = depth[u] + 1;
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
    par[root] = root;
    head[root] = root;
    depth[root] = 0;
    t = 0;
    dfs_sz(root);
    dfs_hld(root);
    build(1, 0, t - 1);
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

int query_subtree(int a){
    return query(1, 0 , t - 1, pos[a], pos[a] + sz[a] - 1);
}

int anc(int u, int k){
    for(int i = 0; i < LOG; i++){
        if(k & ( 1 << i)) u = dp[u][i];
    }
    return u;
}

void sobe(int u){
    int l = 0;
    int r = depth[u];
    int v = u;
    while(l <= r){
        int mid = (l + r) >> 1;
        int ancestor = anc(u, mid);
        int dist = depth[u] - depth[ancestor];
        if(query_subtree(ancestor) == (sz[ancestor] - dist)){
            v = ancestor;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    update_path(v, u, 1);
}

signed main() {
    optimize;
    int n; cin >> n;
    g.assign(n, vector<int>());
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    build_hld();
    int q; 
    cin >> q;
    while(q--){
        int cmd, u;
        cin >> cmd >> u;
        u --;
        if(cmd == 1 && !query(1, 0, t - 1, pos[u], pos[u])){
            // Turn on
            update_subtree(u, 1);
            sobe(u);
        }
        if(cmd == 2){
            //turn off
            update_subtree(u, 0);
            update_path(0, u, 0);
        }
        if(cmd == 3){
            cout << query_subtree(u) << '\n';
        }
    }
    return 0;
}