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
ii responsable[ms];
int sz[ms], answ[ms];

struct Dsu{
    vector<int> parent, sz;
    vector<ii> changes;
    int comps;

    Dsu(int n){
        comps = n;
        parent.assign(comps, 0);
        iota(parent.begin(), parent.end(), 0);
        sz.assign(comps, 1);
    }

    int find(int u){
        if(u == parent[u]) return u;
        else return find(parent[u]);
    }

    void merge(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b){
            changes.push_back({-1, -1});
            return;
        }
        if(sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        changes.push_back({a, b});
        comps--;
    }

    void rollback(){
        auto [a, b] = changes.back();
        changes.pop_back();
        if(a == -1) return;
        sz[a] -= sz[b];
        parent[b] = b;
        comps++;
    }
};

void dfsSize(int u, int p){
    sz[u] = 1;
    for(auto v : g[u]){
        if(v == p) continue;
        dfsSize(v, u);
        sz[u] += sz[v];
    }
}

void add(int u, int p, int bigChild, int x, Dsu & dsu){
    if(x == 1){
        auto [x1,x2] = responsable[u];
        if(x1 != -1) dsu.merge(x1, x2);
    }
    else{
        auto [x1,x2] = responsable[u];
        if(x1 != -1) dsu.rollback();
    }
    for(auto v : g[u]){
        if(v == p || v == bigChild) continue;
        add(v, u, bigChild, x, dsu);
    }
}

void DsuOnTree(int u, int p, bool keep, Dsu & dsu){
    int mx = -1, bigChild = -1;
    for(auto v : g[u]){
        if(v != p && mx < sz[v]){
            mx = sz[v];
            bigChild = v;
        }
    }
    for(auto v : g[u]){
        if(v == p || v == bigChild) continue;
        DsuOnTree(v, u, false, dsu);
    }
    if(bigChild != -1) DsuOnTree(bigChild, u, true, dsu);
    add(u, p, bigChild, 1, dsu);

    answ[u] = dsu.comps;
    if(!keep) add(u, p, -1, -1, dsu);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    Dsu dsu(k);
    g.assign(n, vector<int>());
    for(int i = 1; i < n; i++){
        int p; cin >> p;
        p--;
        g[i].push_back(p);
        g[p].push_back(i);
    }
    for(int i = 0; i < n; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        responsable[i] = {u, v};
    }

    dfsSize(0, -1);
    DsuOnTree(0, -1, false, dsu);

    for(int i = 0; i < n; i++){
        cout << answ[i] << '\n';
    }

    return 0;
}