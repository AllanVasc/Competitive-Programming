#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int ms = 1e5 + 100;
const int LOG = 20;
vector<vector<int>> g;
vector<ii> queries[ms];
int sz[ms], depth[ms], answ[ms];
int up[ms][LOG];
int freq[ms];

void dfs(int u, int p){
    sz[u] = 1;
    for(auto v : g[u]){
        if(v == p) continue;
        depth[v] = depth[u] + 1;
        up[v][0] = u; 
        for(int j = 1; j < LOG; j++){
            up[v][j] = up[ up[v][j - 1]][j - 1];
        }
        dfs(v, u);
        sz[u] += sz[v];
    }
}

int kAncestor(int u, int k){
    if(depth[u] < k) return -1;
    for(int i = 0; i < LOG; i++){
        if(k & (1 << i)) u = up[u][i];
    }
    return u;
}

void add(int u, int p, int bigChild, int x){
    freq[depth[u]] += x;
    for(auto v : g[u]){
        if(v == p || v == bigChild) continue;
        add(v, u, bigChild, x);
    }
}

void DsuOnTree(int u, int p, bool keep){
    int maxSize = -1, bigChild = -1;
    for(auto v : g[u]){
        if(v != p && maxSize < sz[v]){
            maxSize = sz[v];
            bigChild = v;
        }
    }
    for(auto v : g[u]){
        if(v == p || v == bigChild) continue;
        DsuOnTree(v, u, false);
    }
    if(bigChild != -1) DsuOnTree(bigChild, u, true);
    add(u, p, bigChild, 1);

    for(int i = 0; i < queries[u].size(); i++){
        auto [vtx, idx] = queries[u][i];
        answ[idx] = freq[depth[vtx]];
        if(answ[idx]) answ[idx]--;
    }

    if(keep == false) add(u, p, -1, -1);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    g.assign(n, vector<int>());
    vector<int> roots;
    for(int i = 0; i < n; i++){
        int p;
        cin >> p;
        if(p == 0){
            roots.push_back(i);
            continue;
        }
        p--;
        g[i].push_back(p);
        g[p].push_back(i);
    }
    for(int i = 0; i < roots.size(); i++){
        dfs(roots[i], -1);
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        int u, k;
        cin >> u >> k;
        u--;
        int ancestor = kAncestor(u, k);
        if(ancestor == -1) continue;
        queries[ancestor].push_back({u, i});
    }
    for(int i = 0; i < roots.size(); i++){
        DsuOnTree(roots[i], -1, false);
    }

    for(int i = 0; i < q; i++) 
        cout << answ[i] << (i == q - 1 ? '\n' : ' ');
    return 0;
}