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

const int ms = 2e5;
vector<vector<int>> g;
int sz[ms], par[ms], head[ms];
int pos[ms], nodeInPos[ms];
bool isBlack[ms];
int seg[4 * ms]; 
int t;

void build_seg(int p, int l, int r){
    if(l == r){
        seg[p] = INF;
    }
    else{
        int m = (l + r) >> 1;
        int lc = 2*p;
        int rc = lc + 1;
        build_seg(lc, l, m);
        build_seg(rc, m + 1, r);
        seg[p] = min(seg[lc], seg[rc]);
    }
}

void update(int p, int l, int r, int idx, int val){
    if(l == r){
        seg[p] = val;
    }
    else{
        int m = (l + r) >> 1;
        int lc = 2*p;
        int rc = lc + 1;
        if(idx <= m) update(lc, l, m, idx, val);
        else update(rc, m + 1, r, idx, val);
        seg[p] = min(seg[lc], seg[rc]);
    }
}

int query(int p, int l, int r, int ql, int qr){
    if(l >= ql && r <= qr){
        return seg[p];
    }
    int m = (l + r) >> 1;
    int lc = 2*p;
    int rc = lc + 1;
    if(qr <= m) return query(lc, l, m , ql, qr);
    else if(ql > m) return query(rc, m + 1, r, ql, qr);
    return min(query(lc, l, m, ql, qr), query(rc, m + 1, r, ql, qr));
}

void dfs_sz(int u, int p = -1){
    sz[u] = 1;
    for(auto & v : g[u]){
        if(v == p) continue;
        dfs_sz(v, u);
        sz[u] += sz[v];
        if(g[u][0] == p || sz[v] > g[u][0]) swap(v, g[u][0]);
    }
}

void dfs_hld(int u, int p = -1){
    pos[u] = t;
    nodeInPos[t] = u;
    t++;
    for(auto v : g[u]){
        if(v == p) continue;
        par[v] = u;
        head[v] = (v == g[u][0] ? head[u] : v);
        dfs_hld(v, u);
    }
}

void build(int root = 0){
    dfs_sz(root);
    head[root] = root;
    par[root] = root;
    dfs_hld(root);
    build_seg(1, 0, t - 1);
}

void update_node(int u){
    if(isBlack[u]) update(1, 0, t - 1, pos[u], INF);
    else update(1, 0, t - 1, pos[u], pos[u]);
    isBlack[u] = !isBlack[u];
}

int query_path(int a, int b = 0){
    if(pos[a] < pos[b]) swap(a, b);
    if(head[a] == head[b]){
        return query(1, 0, t - 1, pos[b], pos[a]);
    }
    return min(query(1, 0, t - 1, pos[head[a]], pos[a]),
                query_path(par[head[a]], b));
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
    build();
    while(q--){
        int cmd, u;
        cin >> cmd >> u;
        u--;
        if(cmd == 0){
            update_node(u);
        }
        else{
            int val = query_path(u);
            if(val == INF){
                cout << -1 << '\n';
            }
            else{
                cout << nodeInPos[val] + 1 << '\n';
            }
        }
    }
    return 0;
}