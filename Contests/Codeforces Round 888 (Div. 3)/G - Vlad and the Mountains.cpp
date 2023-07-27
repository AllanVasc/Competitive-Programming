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

const int ms = 2e5 + 100;
int parent[ms], sz[ms], cost[ms];
void build(int n){
    for(int i = 0; i < n; i++){
        parent[i] = i;
        sz[i] = 1;
        cost[i] = 0;
    }
}

int find(int u){
    return u == parent[u] ? u : find(parent[u]);
}
int find(int u, int t){
    if(parent[u] == u || cost[u] > t) return u;
    else return find(parent[u], t);
}

void merge(int u, int v, int t){
    u = find(u);
    v = find(v);
    if(u == v) return;
    if(sz[u] < sz[v]) swap(u, v);
    parent[v] = u;
    sz[u] += sz[v];
    cost[v] = t;
}

signed main() {
    optimize;
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> h(n);
        for(int i = 0; i < n; i++){
            cin >> h[i];
        }
        vector<iii> edges;
        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            u--, v--;
            edges.push_back({max(h[u], h[v]), u, v});
        }
        sort(ALL(edges));
        build(n);
        for(auto [c, u, v] : edges){
            merge(u, v, c);
        }
        int q; cin >> q;
        while(q--){
            int u, v, e;
            cin >> u >> v >> e;
            u--, v--;
            cout << (find(u, h[u] + e) == find(v, h[u] + e) ? "YES" : "NO") << '\n';
        }
    }
    return 0;
}