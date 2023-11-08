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

const int ms = 5*1e5 + 100;
const int LOG = 21;
vector<vector<pii>> g; // u -> (v, cost)
int depth[ms], up[ms][LOG], dist[ms];

// HLD
int sz[ms], par[ms], head[ms], pos[ms];
int t;

vector<int> seg, lazy;

void propagate(int p, int l, int r){
    if(!lazy[p]) return;
    seg[p] += (r - l + 1) * lazy[p];
    if(l != r){
        lazy[2*p] += lazy[p];
        lazy[2*p + 1] += lazy[p];
    }
    lazy[p] = 0;
}

void update(int p, int l, int r, int ql, int qr, int x){
    propagate(p, l, r);
    if(r < ql || l > qr) return;
    if(l >= ql && r <= qr){
        lazy[p] += x;
        propagate(p, l, r);
    }
    else{
        int m = (l + r) >> 1;
        int lc = 2*p;
        int rc = lc + 1;
        update(lc, l, m, ql, qr, x);
        update(rc, m + 1, r, ql, qr, x);
        seg[p] = seg[lc] + seg[rc];
    }
}

int query(int p, int l, int r, int ql, int qr){
    propagate(p, l, r);
    if(r < ql || l > qr) return 0;
    if(ql <= l && r <= qr) return seg[p];
    int m = (l+r) >> 1;
    int lc = 2*p;
    int rc = lc + 1;
    return query(lc, l, m, ql, qr) + query(rc , m + 1, r, ql, qr);
}

// Binary lifting + dist
void dfs(int u, int p = -1){
    for(auto [v, cost] : g[u]){
        if(v == p) continue;
        depth[v] = depth[u] + 1;
        dist[v] = dist[u] + cost;
        up[v][0] = u;
        for(int i = 1; i < LOG; i++){
            up[v][i] = up[up[v][i - 1]][i - 1];
        }
        dfs(v, u);
    }
}

int kclimb(int u, int k){
    for(int i = LOG - 1; i >= 0; i--){
        if(k & (1LL << i)) u = up[u][i];
    }
    return u;
}

void dfs_sz(int u, int p = -1){
    sz[u] = 1;
    for(auto & vtx : g[u]){
        auto [v, cost] = vtx;
        if(v == p) continue;
        dfs_sz(v, u);
        sz[u] += sz[v];
        if(g[u][0].first == p || sz[v] > sz[g[u][0].first]) swap(vtx, g[u][0]);
    }
}

void dfs_hld(int u, int p = -1){
    pos[u] = t++;
    // v[pos[u]] = 0;
    for(auto [v, cost] : g[u]){
        if(v == p) continue;
        par[v] = u;
        head[v] = (v == g[u][0].first ? head[u] : v);
        dfs_hld(v, u);
    }
}

// Call this function to initialize
void build_hld(int root = 0){
    dfs_sz(root);
    t = 0;
    head[root] = root;
    dfs_hld(root);
    seg.assign(4 * t, 0);
    lazy.assign(4 * t, 0);
    // build_seg(1, 0, t - 1); // We can use any data structure for range query
}

// Sum query between path from "a" to "b"
int query_path(int a, int b){
    if(pos[a] < pos[b]) swap(a, b);
    if(head[a] == head[b]) return query(1, 0, t - 1, pos[b], pos[a]);
    return query(1, 0, t - 1, pos[head[a]], pos[a]) + query_path(par[head[a]], b);
}

// Updates all vertices of the path from "a" to "b"
void update_path(int a, int b, int x){
    if(pos[a] < pos[b]) swap(a, b);
    if(head[a] == head[b]){
        update(1, 0, t - 1, pos[b], pos[a], x);
        return;
    }
    update(1, 0, t - 1, pos[head[a]], pos[a], x);
    update_path(par[head[a]], b, x);
}

signed main() {
    optimize;
    
    freopen("car.in", "r", stdin); // CHANGE
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> liters(n);
        for(int i = 0; i < n; i++) cin >> liters[i];
        g.assign(n, vector<pii>());
        for(int i = 0; i < n - 1; i++){
            int a, b, cost;
            cin >> a >> b >> cost;
            a--, b--;
            g[a].push_back({b, cost});
            g[b].push_back({a, cost});
        }
        build_hld();
        dfs(0);
        // cout << "dist:" << '\n';
        // for(int i = 0; i < n; i++){
        //     cout << "i = " << i <<" = " << dist[i] << '\n';
        // }
        update_path(0, 0, 1);
        for(int i = 1; i < n; i++){
            int lo = 0;
            int hi = ms;
            int answ = i;
            while(lo <= hi){
                int mid = (lo + hi) >> 1;
                int vtx = kclimb(i, mid);
                int cost = dist[i] - dist[vtx];
                if(cost <= liters[i]){
                    answ = vtx;
                    lo = mid + 1;
                }
                else{
                    hi = mid - 1;
                }
            }
            // cout << "v = " << i + 1 << " limit = " << answ + 1 << '\n';
            update_path(i, answ, 1);
        }
        for(int i = 0; i < n; i++){
            cout << query_path(i, i) - 1 << " ";
        }
        cout << '\n';
    }

    return 0;
}