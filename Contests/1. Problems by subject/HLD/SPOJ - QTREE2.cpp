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

vector<vector<pair<int,int>>> g;
const int ms = 1e4 + 100;
const int LOG = 20;
int sz[ms], depth[ms], head[ms];
int dp[ms][LOG];
int pos[ms], v[ms], sobe[ms];
int seg[4 * ms];
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
        seg[p] = seg[lc] + seg[rc];
    }
}

int query(int p, int l, int r, int ql, int qr){
    if(l >= ql && r <= qr) return seg[p];
    int m = (l + r) >> 1;
    int lc = 2*p;
    int rc = lc + 1;
    if(qr <= m) return query(lc, l, m, ql, qr);
    else if(ql > m) return query(rc, m + 1, r, ql, qr);
    else return query(lc, l, m, ql, qr) + query(rc, m + 1, r, ql, qr);
}

void dfs_sz(int u, int p = -1){
    sz[u] = 1;
    for(auto & i : g[u]){
        auto [v, w] = i;
        if(v == p) continue;
        sobe[v] = w;
        depth[v] = depth[u] + 1;
        dp[v][0] = u;
        for(int i = 1; i < LOG; i++){
            dp[v][i] = dp[dp[v][i - 1]][i - 1];
        }
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
        head[v] = (i == g[u][0] ? head[u] : v);
        dfs_hld(v, u);
    }
}

void build(int root = 0){
    dfs_sz(root);
    head[root] = root;
    depth[root] = 0;
    t = 0;
    dfs_hld(root);
    build_seg(1, 0, t - 1);
}

int query1(int a, int b){
    if(a == b) return 0;
    if(pos[a] < pos[b]) swap(a, b);
    if(head[a] == head[b]){
        return query(1, 0, t - 1, pos[b] + 1, pos[a]);
    }
    return query(1, 0, t - 1, pos[head[a]], pos[a]) +
            query1(dp[head[a]][0], b);
}

int lca(int a, int b){
    if(pos[a] < pos[b]) swap(a, b);
    return head[a] == head[b] ? b : lca(dp[head[a]][0], b);
}

int bl(int u, int k){
    for(int i = 0; i < LOG; i++){
        if(k & (1 << i)) u = dp[u][i];
    }
    return u + 1;
}

int query2(int a, int b, int k){
    k--;
    int curlca = lca(a, b);
    // cout << "lca = " << curlca + 1 << '\n';
    int len = depth[a] - depth[curlca];
    // cout << "len = " << len << '\n';
    if(k <= len){
        return bl(a, k);
    }
    else{
        k -= len;
        return bl(b, (depth[b] - depth[curlca]) - k);
    }
}

int32_t main() {
    optimize;
    int cs;
    cin >> cs;
    while(cs--){
        int n;
        cin >> n;
        g.assign(n, vector<pair<int,int>>());
        for(int i = 0; i < n - 1; i++){
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }
        build();
        string s;
        while(cin >> s){
            if(s[1] == 'O') break;
            if(s[1] == 'I'){
                int u, v;
                cin >> u >> v;
                u--, v--;
                cout << query1(u, v) << '\n';
            }
            else{
                int u, v, k;
                cin >> u >> v >> k;
                u--, v--;
                cout << query2(u, v, k) << '\n';
            }
        }
        cout << '\n';
    }
    return 0;
}