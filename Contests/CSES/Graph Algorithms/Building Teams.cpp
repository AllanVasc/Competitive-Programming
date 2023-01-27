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
vector<int> visited;

bool bfs(int start){
    visited[start] = 0;
    queue<int> q;
    q.push(start);

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(auto v : g[curr]){
            if(visited[v] == -1){
                visited[v] = 1 - visited[curr];
                q.push(v);
            }
            if(visited[curr] == visited[v]) return false;
        }
    }

    return true;
}

bool bipartite(){
    int n = g.size();
    int answ = true;

    for(int i = 0; i < n; i++){
        if(visited[i] == -1){
            answ = answ && bfs(i);
        }
    }

    return answ;
}
int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    g.assign(n, vector<int>());
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u-1].push_back(v-1);
        g[v-1].push_back(u -1 );
    }

    visited.assign(n, -1);

    if(bipartite()){
        for(int i = 0; i < n; i++){
            cout << visited[i] + 1 << " ";
        }
        cout << '\n';
    }
    else{
        cout << "IMPOSSIBLE" << '\n';
    }

    return 0;
}