// 
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int INF = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;

const int MAXN = 2*1e5 + 100;
vector<vector<int>> g;

bool visited[MAXN];
bool slp[MAXN];

void addEdge(int u, int v){
    g[u].push_back(v);
    g[v].push_back(u);
}

void dfs(int u){

    visited[u] = true;

    for(auto v : g[u]){
        if(!visited[v]){
            if(slp[u] == 0){
                cout << v+1 << " ";
                slp[v] = true;
            }
            dfs(v);
        }
    }
    
    if(!slp[u]){
        cout << u+1 << " ";
        slp[u] = true;
    }
}

int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    g.assign(n+10, vector<int>());
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        addEdge(u-1,v-1);
    }

    dfs(0);
    cout << "\n";

    return 0;
}
