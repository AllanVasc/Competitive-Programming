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
vector<vector<int>> g;
string names[ms];
int sz[ms], depth[ms], answ[ms];
set<string> dif[ms];
vector<ii> queries[ms];

void dfsSize(int u, int dep, int p){
    sz[u] = 1;
    depth[u] = dep;
    for(auto v : g[u]){
        if(v == p) continue;
        dfsSize(v, dep + 1, u);
        sz[u] += sz[v];
    }
}

void add(int u, int p, int bigChild, int x){
    if(x == 1){
        dif[depth[u]].insert(names[u]);
    }
    else dif[depth[u]].erase(names[u]);

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

    // cout << "u = " << u + 1 << '\n';
    for(int i = 0; i < queries[u].size(); i++){
        auto [dep, idx] = queries[u][i];
        answ[idx] = dif[depth[u] + dep].size();
        // for(auto y : dif[depth[u] + dep]) cout << y << '\n';
    }

    if(keep == false){
        add(u, p, -1, -1);
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    g.assign(n, vector<int>());
    vector<int> roots;
    for(int i = 0; i < n; i++){
        int pai;
        cin >> names[i] >> pai;
        if(pai == 0){
            roots.push_back(i);
            continue;
        }
        pai--;
        g[i].push_back(pai);
        g[pai].push_back(i);
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        int u, dep;
        cin >> u >> dep;
        u--;
        queries[u].push_back({dep, i});
    }
    for(int u : roots){
        dfsSize(u, 1, -1);
        DsuOnTree(u, -1, false);
    }
    
    for(int i = 0; i < q; i++){
        cout << answ[i] << "\n";
    }
    return 0;
}