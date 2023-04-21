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

int dfs(int u){
    visited[u] = true;
    int cnt = 1;
    for(auto v : g[u]){
        if(!visited[v]) cnt += dfs(v);
    }
    return cnt;
}

void removeEdge(vector<int>& v, int x){
    for(int &e: v){
        if(e == x){
            swap(e, v.back());
            v.pop_back();
            return;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        
        g.assign(n, vector<int>());
        visited.assign(n, false);
        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            u--, v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        int k = sqrt(n);
        bool has_answ = true;
        if(n != k*k || m != n + k){
            has_answ = false;
        }
        for(int i = 0; i < n; i++){
            if(g[i].size() != 2 && g[i].size() != 4) has_answ = false;
        }
        if(dfs(0) != n){
            has_answ = false;
        }
        for(int u = 0; u < n; u++){
            if(g[u].size() == 2) continue;
            for(int j = 0; j < g[u].size(); j++){
                int v = g[u][j];
                if(g[v].size() > 2){
                    removeEdge(g[u], v);
                    removeEdge(g[v], u);
                    j--;
                }
            }
        }
        visited.assign(n, false);
        for(int i = 0; i < n; i++){
            if(!visited[i] && dfs(i) != k){
                has_answ = false;
            }
        }
        if(has_answ) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}