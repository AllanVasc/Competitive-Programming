#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int MAXN = 1e5 + 100;
const int MAXW = 1e12;
const int LOG = 20;

vector<int> weight;
vector<int> soma, esq, dir;
vector<vector<int>> g;
int parent[MAXN], depth[MAXN], up[MAXN][LOG];
map<int, int> roots;

int create(){
    soma.push_back(0);
    esq.push_back(0);
    dir.push_back(0);
    return soma.size() - 1;
}

int update(int p, int l, int r, int id, int val){
    int novo = create();
    soma[novo] = soma[p];
    esq[novo] = esq[p];
    dir[novo] = dir[p];
    if(l == r){
        soma[novo] += val;
        return novo;
    }
    int m = (l + r) >> 1;
    if(id <= m){
        int aux = update(esq[novo], l, m, id, val);
        esq[novo] = aux;
    }
    else{
        int aux = update(dir[novo], m + 1, r, id, val);
        dir[novo] = aux;
    }
    soma[novo] = soma[esq[novo]] + soma[dir[novo]];
    return novo;
}

void build(int u, int lastRoot, int p = 0){
    parent[u] = p;
    roots[u] = update(lastRoot, -MAXW, MAXW, weight[u], 1);
    for(auto v : g[u]){
        if(v == p) continue;
        depth[v] = depth[u] + 1;
        up[v][0] = u;
        for(int j = 1; j < LOG; j++){
            up[v][j] = up[ up[v][j - 1]][j - 1];
        }
        build(v, roots[u], u);
    }
}

int lca(int u, int v){
    if(depth[u] < depth[v]) swap(u, v);
    int k = depth[u] - depth[v];
    for(int j = LOG - 1; j >= 0; j--){
        if(k & (1 << j)){
            u = up[u][j];
        }
    }
    if(u == v) return u;
    for(int j = LOG - 1; j >= 0; j--){
        if(up[u][j] != up[v][j]){
            u = up[u][j];
            v = up[v][j];
        }
    }
    return up[u][0];
}

int descent(int rootU, int rootV, int rootL, int rootPL, int l, int r, int k){
    if(l == r){
        return l;
    }
    int m = (l + r) >> 1;
    int check = soma[esq[rootU]] + soma[esq[rootV]] - soma[esq[rootL]] - soma[esq[rootPL]];
    if(k > check) return descent(dir[rootU], dir[rootV], dir[rootL], dir[rootPL], m + 1, r, k - check);
    else return descent(esq[rootU], esq[rootV], esq[rootL], esq[rootPL], l, m, k); 
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    weight.assign(n + 1, 0);
    for(int i = 1; i <= n; i++) cin >> weight[i];
    g.assign(n + 1, vector<int>());
    g[0].push_back(1);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    create();
    roots[0] = create();
    build(1, roots[0]);

    while(m--){
        int u, v, k;
        cin >> u >> v >> k;
        int lcaof = lca(u, v);
        cout << descent(roots[u], roots[v], roots[lcaof], roots[parent[lcaof]], -MAXW, MAXW, k) << '\n';
    }
    return 0;
}