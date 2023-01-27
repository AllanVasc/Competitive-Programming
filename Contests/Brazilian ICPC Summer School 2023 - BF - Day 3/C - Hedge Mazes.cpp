#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

vector<vector<int>> g_orig;
vector<vector<int>> g_changed;

vector<bool> visited;
vector<int> discovered, low;
int timer = 0;

vector<int> component;

void dfs(int u, int p = -1){
    visited[u] = true;
    discovered[u] = low[u] = timer;
    timer++;
    for(auto to : g_orig[u]){
        if(to == p) continue;
        if(visited[to]) low[u] = min(low[u], discovered[to]);
        else{
            dfs(to, u);
            low[u] = min(low[u], low[to]);
            if(low[to] > discovered[u]){    // It's a bridge
                g_changed[u].push_back(to);
                g_changed[to].push_back(u);
            }
        }
    }
}

void find_bridges(int n){
    timer = 0;
    visited.assign(n, false);
    discovered.assign(n, -1);
    low.assign(n, -1);
    for(int i = 0; i < n; i++){
        if(!visited[i]) dfs(i);
    }
}

void dfs2(int u, int id){
    component[u] = id;
    for(auto i : g_changed[u]){
        if(component[i] == -1) dfs2(i, id);
    }
}

void solve(int n){
    component.assign(n, -1);
    for(int i = 0; i < n; i++){
        if(component[i] == -1) dfs2(i, i);
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int r, c, q;
    while(cin >> r >> c >> q){
        if(r == 0 && c == 0 && q == 0) return 0;

        g_orig.assign(r, vector<int>());
        for(int i = 0; i < c; i++){
            int u, v;
            cin >> u >> v;
            u--, v--;
            g_orig[u].push_back(v);
            g_orig[v].push_back(u);
        }

        g_changed.assign(r, vector<int>());
        find_bridges(r);
        solve(r);

        for(int i = 0; i < q; i++){
            int u, v;
            cin >> u >> v;
            u--, v--;
            cout << (component[u] == component[v] ? "Y" : "N") << '\n';
        }
        cout << "-" << '\n';
    }

    return 0;
}