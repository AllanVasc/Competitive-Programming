#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int MAXN = 2e5 + 100;
vector<vector<int>> g(MAXN);
bool visited[MAXN];

int bfs(int src){
    visited[src] = true;
    queue<int> q;
    q.push(src);
    int menor = src;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        if(g[curr].size() < g[menor].size()) menor = curr;
        for(auto v : g[curr]){
            if(!visited[v]){
                q.push(v);
                visited[v] = true;
            }
        }
    }
    return menor;
}

void solve(int n){
    int less_degree = 0;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            int vtx = bfs(i);
            if(g[less_degree].size() > g[vtx].size()){
                less_degree = vtx;
            }
        }
    }
    vector<int> answ(n, 1);
    answ[less_degree] = 0;
    for(auto i : g[less_degree]){
        answ[i] = 0;
    }
    for(int i = 0; i < n; i++){
        cout << answ[i] << " ";
    }
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    solve(n);

    return 0;
}