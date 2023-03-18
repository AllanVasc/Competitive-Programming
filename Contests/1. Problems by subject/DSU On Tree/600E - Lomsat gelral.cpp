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
int sz[ms], answ[ms], cnt[ms], color[ms];
int bigFreq, bigSum;

void dfsSize(int u, int p = -1){
    sz[u] = 1;
    for(auto v : g[u]){
        if(v == p) continue;
        dfsSize(v, u);
        sz[u] += sz[v];
    }
}

void add(int u, int p, int bigChild, int x){
    cnt[color[u]] += x;
    if(cnt[color[u]] > bigFreq){
        bigFreq = cnt[color[u]];
        bigSum = color[u];
    }
    else if(cnt[color[u]] == bigFreq){
        bigSum += color[u];
    }
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
    answ[u] = bigSum;
    if(keep == false){
        add(u, p, -1, -1);
        bigFreq = 0, bigSum = 0;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> color[i];
    g.assign(n, vector<int>());
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfsSize(0);
    DsuOnTree(0, -1, false);
    for(int i = 0; i < n; i++){
        cout << answ[i] << " ";
    }
    cout << '\n';
    return 0;
}