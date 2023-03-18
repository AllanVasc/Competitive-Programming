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
int sz[ms], number[ms];
map<int,int> freq;
int answ = 0;

void dfsSize(int u, int p = -1){
    sz[u] = 1;
    for(auto v : g[u]){
        if(v == p) continue;
        dfsSize(v, u);
        sz[u] += sz[v];
    }
}

void solve(int u, int p, int val){
    if(val % number[u] == 0){
        answ += freq[val / number[u]];
    }
    for(auto v : g[u]){
        if(v == p) continue;
        solve(v, u, val);
    }
}

void add(int u, int p, int bigChild, int x){
    freq[number[u]] += x;
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
    for(auto v : g[u]){
        if(v == p || v == bigChild) continue;
        solve(v, u, number[u]);
        add(v, u, -1, 1);
    }
    answ += freq[1];
    freq[number[u]]++;
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
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 0; i < n; i++) cin >> number[i];
    dfsSize(0);
    DsuOnTree(0, -1, false);
    cout << answ << '\n';
    return 0;
}