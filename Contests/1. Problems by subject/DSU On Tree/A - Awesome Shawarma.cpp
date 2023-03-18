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
int n, l, r;
vector<vector<int>> g;
int sz[ms], depth[ms];
int answ;

vector<int> bit;
void build(){
    memset(sz, 0, sizeof sz);
    memset(depth, 0, sizeof depth);
    answ = 0;
    bit = vector<int>(1e6 + 1, 0);
}
int prefix_query(int idx){
    int result = 0;
    for(++idx; idx > 0; idx -= idx & -idx) result += bit[idx];
    return result;
}
int range_query(int l1, int r1){
    if(l1 == 0) return prefix_query(r1);
    else return prefix_query(r1) - prefix_query(l1 - 1);
}
void update(int idx, int add) {
    for (++idx; idx < bit.size(); idx += idx & -idx) bit[idx] += add;
}

void dfsSize(int u, int p){
    sz[u] = 1;
    for(auto v : g[u]){
        if(v == p) continue;
        depth[v] = depth[u] + 1;
        dfsSize(v, u);
        sz[u] += sz[v];
    }
}

void add(int u, int p, int bigChild, int x){
    update(depth[u], x);
    for(auto v : g[u]){
        if(v == p || v == bigChild) continue;
        add(v, u, bigChild, x);
    }
}

void solve(int u, int p, int ref){
    int dist = depth[u] - depth[ref];
    
    int bigLimit = (n - 1) + depth[ref] - dist - l;
    int smallLimit = (n - 1) + depth[ref] - dist - r; 

    if(bigLimit >= 0) 
        answ += range_query(max(0LL, smallLimit), bigLimit);

    for(auto v : g[u]){
        if(v == p) continue;
        solve(v, u, ref);
    }
}

void DsuOnTree(int u, int p, bool keep){
    int mxS = -1, bigChild = -1;
    for(auto v : g[u]){
        if(v != p && mxS < sz[v]){
            mxS = sz[v];
            bigChild = v;
        }
    }
    for(auto v : g[u]){
        if(v == p || v == bigChild) continue;
        DsuOnTree(v, u, false);
    }
    if(bigChild != -1) DsuOnTree(bigChild, u, true);
    
    for(auto v : g[u]){
        if(v == p || v == bigChild) continue;
        solve(v, u, u);
        add(v, u, bigChild, 1);
    }

    int dist = 0;
    
    int bigLimit = (n - 1) + depth[u] - dist - l;
    int smallLimit = (n - 1) + depth[u] - dist - r; 
    if(bigLimit >= 0) 
        answ += range_query(max(0LL, smallLimit), bigLimit);

    update(depth[u], 1);
    if(keep == false) add(u, p, -1, -1);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    freopen("awesome.in", "r", stdin);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> l >> r;
        g.assign(n, vector<int>());
        for(int i = 0; i < n - 1; i++){
            int u, v;
            cin >> u >> v;
            u--, v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        build();
        dfsSize(0, -1);
        DsuOnTree(0, -1, false);
        cout << answ << '\n';
    }
    return 0;
}