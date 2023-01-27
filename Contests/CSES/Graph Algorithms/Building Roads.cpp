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
vector<int> answ;

void bfs_aux(int v){
    visited[v] = true;
    queue<int> q;
    q.push(v);

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(auto u : g[curr]){
            if(!visited[u]){
                q.push(u);
                visited[u] = true;
            }
        }
    }
}

void bfs(){
    int n = g.size();
    visited.assign(n, 0);
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            if(i != 0) answ.push_back(i+1);
            bfs_aux(i);
        }
    }
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
        g[v-1].push_back(u-1);
    }

    bfs();

    cout << answ.size() << '\n';
    for(int i = 0; i < answ.size(); i++){
        cout << 1 << " " << answ[i] << '\n';
    }

    return 0;
}