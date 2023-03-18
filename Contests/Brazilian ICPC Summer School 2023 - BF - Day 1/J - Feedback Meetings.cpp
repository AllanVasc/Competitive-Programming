#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int ms = 4*1e5 + 100;
int visited[ms];
stack<int> order;
vector<vector<int>> g, gr;
int cnt = 0;

void dfs1(int u){
    visited[u] = true;
    for(auto v : g[u]){
        if(!visited[v]) dfs1(v);
    }
    order.push(u);
}

void dfs2(int u){
    visited[u] = true;
    cnt++;
    for(auto v : gr[u]){
        if(!visited[v]) dfs2(v);
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    g.assign(n, vector<int>()), gr.assign(n, vector<int>());
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        gr[v].push_back(u);
    }
    for(int i = 0; i < n; i++){
        if(!visited[i] && g[i].size() > 0) dfs1(i);
    }

    memset(visited, 0, sizeof visited);
    int answ = 0;
    while(!order.empty()){
        int u = order.top();
        order.pop();
        if(!visited[u]){
            cnt = 0;
            dfs2(u);
            answ += 2*cnt - 1;
        }
    }
    cout << answ << '\n';
    return 0;
}