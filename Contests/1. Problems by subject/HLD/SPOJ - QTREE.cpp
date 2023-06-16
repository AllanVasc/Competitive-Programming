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

const int ms = 1e4 + 10;
vector<pair<int,int>> g[ms];
pair<int,int> edges[ms];
int sobe[ms];
int sz[ms], par[ms], head[ms], pos[ms];
int seg[4 * ms], v[ms];
int t;

void build_seg(int p, int l, int r){
    if(l == r){
        seg[p] = v[l];
    }
    else{
        int m = (l + r) >> 1;
        int lc = 2*p;
        int rc = lc + 1;
        build_seg(lc, l, m);
        build_seg(rc, m + 1, r);
        int x = seg[lc];
        int y = seg[rc];
        seg[p] = (x > y ? x : y);
    }
}

void update_seg(int p, int l, int r, int idx, int x){
    if(l == r){
        seg[p] = x;
    }
    else{
        int m = (l + r) >> 1;
        int lc = 2 * p;
        int rc = lc + 1;
        if(idx <= m) update_seg(lc, l, m, idx, x);
        else update_seg(rc, m + 1, r, idx, x);
        int x = seg[lc];
        int y = seg[rc];
        seg[p] = (x > y ? x : y);
    }
}

int query_seg(int p, int l, int r, int ql, int qr){
    if(l >= ql && r <= qr) return seg[p];
    int m = (l + r) >> 1;
    int lc = 2 * p;
    int rc = lc + 1;
    if(qr <= m) return query_seg(lc, l, m, ql, qr);
    else if(ql > m) return query_seg(rc, m + 1, r, ql, qr);
    int x = query_seg(lc, l, m, ql, qr);
    int y = query_seg(rc, m + 1, r, ql, qr);
    return x > y ? x : y;
}

void dfs_sz(int u, int p = -1){
    sz[u] = 1;
    for(auto & i : g[u]){
        auto [v, w] = i;
        if(v == p) continue;
        sobe[v] = w;
        dfs_sz(v, u);
        sz[u] += sz[v];
        if(g[u][0].first == p || sz[v] > sz[g[u][0].first]) swap(i, g[u][0]);
    }
}

void dfs_hld(int u, int p = -1){
    pos[u] = t++;
    v[pos[u]] = sobe[u];
    for(auto i : g[u]){
        auto [v, w] = i;
        if(v == p) continue;
        par[v] = u;
        head[v] = (i == g[u][0] ? head[u] : v);
        dfs_hld(v, u);
    }
}

// Call this function to initialize
void build_hld(int root = 0){
    dfs_sz(root);
    t = 0;
    head[root] = root;
    dfs_hld(root);
    build_seg(1, 0, t - 1); // We can use any data structure for range query
}

void update_path(int a, int b, int x){
    if(pos[a] < pos[b]) swap(a, b);
    update_seg(1, 0, t - 1, pos[a], x);
}

int query_path(int a, int b){
    if(a == b) return 0;
    if(pos[a] < pos[b]) swap(a, b);
    if(head[a] == head[b]) return query_seg(1, 0, t - 1, pos[b] + 1, pos[a]);
    int x = query_seg(1, 0, t - 1, pos[head[a]], pos[a]);
    int y = query_path(par[head[a]], b);
    return x > y ? x : y;
}

int32_t main() {
    //optimize;
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) g[i].clear();
        for(int i = 0; i < n - 1 ; i++){
            int u, v, c;
            cin >> u >> v >> c;
            u--, v--;
            g[u].push_back({v, c});
            g[v].push_back({u, c});
            edges[i] = make_pair(u, v);
        }
        build_hld();
        while(1){
            char s[15];
            scanf("%s", s);
            if(s[0] == 'D') break;
            if(s[0] == 'Q'){
                int u, v;
                scanf("%d %d", &u, &v);
                u--, v--;
                printf("%d\n", query_path(u, v));
            }
            else{
                int e, x;
                scanf("%d %d", &e, &x);
                e--;
                update_path(edges[e].first, edges[e].second, x);
            }
        }
    }
    return 0;
}