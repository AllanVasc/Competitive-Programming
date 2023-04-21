#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int ms = 2*1e5 + 100;
int seg[4 * ms];

void update(int p, int l, int r, int id, int x){
    if(l == r){
        seg[p] = x;
        return;
    }
    int m = (l + r) >> 1;
    int lc = 2*p;
    int rc = lc + 1;
    if(id <= m) update(lc, l, m, id, x);
    else update(rc, m + 1, r, id, x);
    
    seg[p] = seg[lc] + seg[rc];
}

int query(int p, int l, int r, int ql, int qr){
    if(l > qr || r < ql) return 0;
    if(l >= ql && r <= qr) return seg[p];
    int m = (l + r) >> 1;
    int lc = 2*p;
    int rc = lc + 1;
    return query(lc, l, m, ql, qr) + query(rc, m + 1, r, ql, qr);
}

vector<vector<int>> g;
int timer = 0;
int values[ms], st[ms], en[ms];

void dfs(int u, int p = -1){
    st[u] = timer++;
    for(auto v : g[u]){
        if(v == p) continue;
        dfs(v, u);
    }
    en[u] = timer - 1;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> values[i];

    g.assign(n, vector<int>());
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0);
    for(int i = 0; i < n; i++){
        update(1, 0, n - 1, st[i], values[i]);
    }
    while(q--){
        int cmd;
        cin >> cmd;
        if(cmd == 1){
            int u, x;
            cin >> u >> x;
            u--;
            update(1, 0, n - 1, st[u], x);
        }
        else{
            int u;
            cin >> u;
            u--;
            cout << query(1, 0, n - 1, st[u], en[u]) << '\n';
        }
    }
    return 0;
}