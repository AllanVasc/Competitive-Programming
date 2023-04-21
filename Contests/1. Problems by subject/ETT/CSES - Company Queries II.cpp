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
vector<vector<int>> g;
vector<int> euler;
int depth[ms], first[ms];
vector<int> seg;

// We put in the crossing a certain vertex whenever we pass by it
void dfs(int u, int p = -1){
    first[u] = euler.size();
    euler.push_back(u);
    for(auto v : g[u]){
        if(v == p) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
        euler.push_back(u);
    }
}

// Using a segmentation tree to answer the RMQ
// Obs.: We can use a Sparse Table to query in O(1)

// Call using build(1, 0, euler.size() - 1)
void build(int p, int l, int r){
    if(l == r){
        seg[p] = euler[l];
    }
    else{
        int m = (l + r) / 2;
        int lc = 2*p;
        int rc = lc + 1;

        build(lc, l, m);
        build(rc, m + 1, r);
        
        int vl = seg[lc];
        int vr = seg[rc];
        seg[p] = (depth[vl] < depth[vr]) ? vl : vr;
    }
}

int query(int p, int l, int r, int ql, int qr){
    if(l >= ql && r <= qr){
        return seg[p];
    }
    else{
        int m = (l + r) / 2;
        int lc = 2*p;
        int rc = lc + 1;

        if(qr <= m) return query(lc, l, m, ql, qr);
        else if(ql > m) return query(rc, m + 1, r, ql, qr);
        
        int vl = query(lc, l, m, ql, qr);
        int vr = query(rc, m + 1, r, ql, qr);
        
        return (depth[vl] < depth[vr]) ? vl : vr;
    }
}

int lca(int u, int v){
    int l = first[u];
    int r = first[v];
    if(l > r) swap(l, r);
    return query(1, 0, euler.size() - 1, l, r);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, q;
    cin >> n >> q;
    g.assign(n, vector<int>());
    for(int i = 1; i < n; i++){
        int u;
        cin >> u;
        u--;
        g[i].push_back(u);
        g[u].push_back(i);
    }
    dfs(0);
    seg.assign(4 * euler.size(), 0);
    build(1, 0, euler.size() - 1);

    while(q--){
        int u, v;
        cin >> u >> v;
        u--, v--;
        cout << lca(u,v) + 1 << '\n';
    }
    return 0;
}