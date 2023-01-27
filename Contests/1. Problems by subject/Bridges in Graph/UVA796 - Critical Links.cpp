#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

vector<vector<int>> g;
vector<bool> visited;
vector<int> discovered, low;
int timer = 0;

vector<ii> bridges;

// Tarjan's Algorithm for finding bridges in a graph
// Bridges = It's an edge which, when removed, increases the number of connected components in the graph.
void dfs(int v, int p = -1){
    visited[v] = true;
    discovered[v] = low[v] = timer;
    timer++;
    for(int to : g[v]){
        if(to == p) continue;
        if(visited[to]) low[v] = min(low[v], discovered[to]);
        else{
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if(low[to] > discovered[v]){    // It's a bridge
                if(v < to) bridges.push_back({v, to});
                else bridges.push_back({to, v});
            }
        }
    }
}

void find_bridges(int n){
    timer = 0;
    visited.assign(n, false);
    discovered.assign(n, -1);
    low.assign(n, -1);
    bridges.clear();
    for(int i = 0; i < n; i++){
        if(!visited[i]) dfs(i);
    }
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    while(cin >> n){
        
        g.assign(n, vector<int>());
        for(int i = 0; i < n; i++){
            int u;
            cin >> u;
            char trash;
            int qtd;
            cin >> trash >> qtd >> trash;
            for(int j = 0; j < qtd; j++){
                int v; 
                cin >> v;
                g[u].push_back(v);
                g[v].push_back(u);
            }
        }
        find_bridges(n);
        cout << bridges.size() << " critical links\n";
        sort(bridges.begin(), bridges.end());
        for(int i = 0; i < bridges.size(); i++){
            cout << bridges[i].first << " - " << bridges[i].second << "\n";
        }
        cout << '\n';
    }
    return 0;
}