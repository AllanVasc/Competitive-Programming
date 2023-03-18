#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int ms = 5e5 + 100;
vector<vector<int>> g;
vector<vector<ii>> queries;
int sz[ms], depth[ms], answ[ms];
string letters;
int curr[ms][26];

void dfsSize(int u, int dep, int p = -1){
    sz[u] = 1;
    depth[u] = dep;
    for(auto v : g[u]){
        if(v == p) continue;
        dfsSize(v, dep + 1, u);
        sz[u] += sz[v];
    }
}

void add(int u, int p, int bigChild, int x){
    curr[depth[u]][letters[u] - 'a'] += x;
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
    if(bigChild != -1){
        DsuOnTree(bigChild, u, true);
    }
    add(u, p, bigChild, 1);
    
    for(int i = 0; i < queries[u].size(); i++){
        auto [dep, idx] = queries[u][i];
        int len = 0, odd = 0;
        for(int j = 0; j < 26; j++){
            len += curr[dep][j];
            if(curr[dep][j] % 2 == 1) odd++;
        }
        if(len % 2 == 0){
            if(odd == 0) answ[idx] = 1;
            else answ[idx] = 0;
        }
        else{
            if(odd == 1) answ[idx] = 1;
            else answ[idx] = 0;
        }
    }

    if(keep == false){
        add(u, p, -1, -1);
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, q;
    cin >> n >> q;
    g.assign(n, vector<int>());
    queries.assign(n, vector<ii>());
    for(int i = 2; i <= n; i++){
        int p;
        cin >> p;
        p--;
        g[i - 1].push_back(p);
        g[p].push_back(i - 1);
    }
    cin >> letters;
    for(int i = 0; i < q; i++){
        int u, dep;
        cin >> u >> dep;
        u--;
        queries[u].push_back({dep, i});
    }
    dfsSize(0, 1);
    DsuOnTree(0, -1, false);
    for(int i = 0; i < q; i++){
        cout << (answ[i] ? "Yes" : "No") << '\n';
    }
    return 0;
}