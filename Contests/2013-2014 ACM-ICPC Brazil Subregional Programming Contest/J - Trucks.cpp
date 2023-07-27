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

vector<int> par, sz, cost;
void build(int n){
    par.assign(n, 0);
    sz.assign(n, 1);
    cost.assign(n, 0);
    for(int i = 0; i < n; i++){
        par[i] = i;
    }
}

int find(int u){
    return u == par[u] ? u : find(par[u]);
}
int find(int u, int t){
    if(u == par[u] || cost[u] < t) return u;
    else return find(par[u], t);
}
void merge(int u, int v, int t){
    u = find(u);
    v = find(v);
    if(u == v) return;
    if(sz[u] < sz[v]) swap(u, v);
    // cout << "conectar " << v << " no " << u << '\n';
    par[v] = u;
    sz[u] += sz[v];
    cost[v] = t;
}

signed main() {
    optimize;
    int n, m, q;
    cin >> n >> m >> q;
    vector<tuple<int,int,int>> edges;
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edges.push_back({w, u, v});
    }
    sort(edges.rbegin(), edges.rend());
    build(n);
    for(auto [w, x, y] : edges){
        merge(x, y, w);
    }
    while(q--){
        int u, v;
        cin >> u >> v;
        u--, v--;

        // int ru = find(u, 2);
        // int rv = find(v, );
        // // cout << "ru = " << ru << '\n';
        // // cout << "rv = " << rv << '\n';

        int l = 0;
        int r = 1e5;
        int answ = l;
        while(l <= r){
            int mid = (l + r) >> 1;
            int ru = find(u, mid);
            int rv = find(v, mid);
            if(ru == rv){ // eh posivel
                answ = max(answ, mid);
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        cout << answ << '\n';

    }
    return 0;
}