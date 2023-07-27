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

vector<vector<int>> g;
const int ms = 30000 + 100;
int sz[ms], par[ms], head[ms];
int pos[ms], vec[ms], val[ms];
int t = 0;
int seg[4 * ms];

void build_seg(int p, int l, int r){
    if(l == r){
        seg[p] = vec[l];
    }
    else{
        int m = (l + r) >> 1;
        int lc = 2* p;
        int rc = lc + 1;
        build_seg(lc, l, m);
        build_seg(rc, m + 1, r);
        seg[p] = seg[lc] + seg[rc];
    }
}

void update_seg(int p ,int l, int r, int idx, int x){
    if(l == r){
        seg[p] = x;
    }
    else{
        int m = (l + r) >> 1;
        int lc = 2*p;
        int rc = lc + 1;
        if(idx <= m) update_seg(lc, l, m, idx, x);
        else update_seg(rc, m + 1, r, idx, x);
        seg[p] = seg[lc] + seg[rc];
    }
}

int query(int p, int l, int r, int ql, int qr){
    if(l >= ql && r <= qr){
        return seg[p];
    }
    int m = (l + r) >> 1;
    int lc = 2*p;
    int rc = lc + 1;
    if(qr <= m) return query(lc, l, m, ql, qr);
    else if(ql > m) return query(rc, m + 1, r, ql, qr);
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
    vec[pos[u]] = val[u];
    for(auto v : g[u]){
        if(v == p) continue;
        head[v] = (v == g[u][0] ? head[u] : v);
        dfs_hld(v, u);
    }
}

void build_hld(int root = 0){
    dfs_sz(root);
    t = 0;
    par[root] = root;
    head[root] = root;
    dfs_hld(root);
    build_seg(1, 0, t - 1);
}

int query_path(int a, int b){
    if(pos[a] < pos[b]) swap(a, b);
    if(head[a] == head[b]){
        return query(1, 0, t - 1, pos[b], pos[a]);
    }
    return query(1, 0, t - 1, pos[head[a]], pos[a]) + query_path(par[head[a]], b);
}

signed main() {
    optimize;
    int lim;
    cin >> lim;
    for(int cs = 1; cs <= lim; cs++){
        cout << "Case " << cs << ":\n";
        int n; 
        cin >> n;
        g.assign(n, vector<int>());
        for(int i = 0; i < n; i++) cin >> val[i];
        for(int i = 0; i < n - 1; i++){
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        build_hld();
        int q; cin >> q;
        while(q--){
            int cmd, x, y;
            cin >> cmd >> x >> y;
            if(cmd == 0){
                cout << query_path(x, y) << '\n';
            }
            else{
                update_seg(1, 0, t - 1, pos[x], y);
            }
        }
    }
    return 0;
}