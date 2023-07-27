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
vector<int> number;
vector<vector<int>> calc;
const int ms = 2e5;
int sz[ms], par[ms], head[ms];
int pos[ms], v[ms];
int t;

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
    calc[number[u]].push_back(pos[u]);
    for(auto v : g[u]){
        if(v == p) continue;
        head[v] = (v == g[u][0] ? head[u] : v);
        dfs_hld(v, u);
    }
}

void build(int root = 0){
    par[root] = root;
    head[root] = root;
    t = 0;
    dfs_sz(root);
    dfs_hld(root);
}

int count(int l, int r, int c){
    return upper_bound(calc[c].begin(), calc[c].end(), r) -
            lower_bound(calc[c].begin(), calc[c].end(), l);
}

int query(int a, int b, int c){
    if(pos[a] < pos[b]) swap(a, b);
    if(head[a] == head[b]){
        return count(pos[b], pos[a], c);
    }
    return count(pos[head[a]], pos[a], c) + query(par[head[a]], b, c);
}

signed main() {
    optimize;
    int n, q;
    while(cin >> n >> q){
        g.assign(n, vector<int>());
        calc.assign(n + 5, vector<int>());
        number.assign(n, 0);
        for(int i = 0; i < n; i++){
            cin >> number[i];
        }
        for(int i = 0; i < n - 1; i++){
            int u, v;
            cin >> u >> v;
            u--, v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        build();
        while(q--){
            int a, b, c;
            cin >> a >> b >> c;
            a--, b--;
            if(query(a, b, c)){
                cout << "Find" << '\n';
            }
            else{
                cout << "NotFind" << '\n';
            }
        }
        cout << '\n';
    }
    return 0;
}