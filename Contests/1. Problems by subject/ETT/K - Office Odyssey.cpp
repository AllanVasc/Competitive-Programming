#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int ms = 2 * (2*1e5 + 100);
const int LOG = 20;

vector<vector<int>> g;
int timer = 0;
int st[ms], en[ms], depth[ms], up[ms][LOG];

void dfs(int u, int p = -1){
    st[u] = timer++;
    for(auto v : g[u]){
        if(v == p) continue;
        depth[v] = depth[u] + 1;
        up[v][0] = u;
        for(int i = 1; i < LOG; i++){
            up[v][i] = up[ up[v][i - 1] ][i - 1];
        }
        dfs(v, u);
    }
    en[u] = timer++;
}

int lca(int u, int v){
    if(depth[u] < depth[v]) swap(u, v);
    int k = depth[u] - depth[v];
    for(int i = LOG - 1; i >= 0; i--){
        if(k & (1 << i)) u = up[u][i];
    }
    if(u == v) return u;
    for(int i = LOG - 1; i >= 0; i--){
        if(up[u][i] != up[v][i]){
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

vector<int> values;
int seg[4 * ms];

void update(int p, int l, int r, int id, int x){
    if(l == r){
        seg[p] = x;
    }
    else{
        int m = (l + r) / 2;
        int lc = 2*p;
        int rc = lc + 1;
        if(id <= m) update(lc, l, m, id, x);
        else update(rc, m + 1, r, id, x);

        seg[p] = seg[lc] + seg[rc];
    }
}

int query(int p, int l, int r, int ql, int qr){
    if(l >= ql && r <= qr) return seg[p];
    int m = (l + r) / 2;
    int lc = 2*p;
    int rc = lc + 1;
    if(qr <= m) return query(lc, l, m, ql, qr);
    else if(ql > m) return query(rc, m + 1, r, ql, qr);
    return query(lc, l, m, ql, qr) + query(rc, m + 1, r, ql, qr);
}

int32_t main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    g.assign(n, vector<int>());
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0);
    values.assign(n, 0);

    vector<iii> queries;
    while(m--){
        int u, v;
        cin >> u >> v;
        u--, v--;
        queries.push_back({depth[lca(u, v)], u, v});
    }

    sort(queries.begin(), queries.end(), greater<iii>());
    int answ = 0;

    for(auto [dep, u, v] : queries){
        int cur_lca = lca(u, v);
        
        int val_query = query(1, 0, timer, st[0], st[u]) + 
                        query(1, 0, timer, st[0], st[v]) -
                        2 * query(1, 0, timer, st[0], st[cur_lca]) + 
                        values[cur_lca];
        // cout << "u = " << u + 1 << " v = " << v + 1 << " lca = " << cur_lca + 1 << " query = " << val_query << '\n';
        answ += val_query;

        values[cur_lca]++;
        update(1, 0, timer, st[cur_lca], values[cur_lca]);
        update(1, 0, timer, en[cur_lca], - values[cur_lca]);
    }

    cout << answ << '\n';
    return 0;
}