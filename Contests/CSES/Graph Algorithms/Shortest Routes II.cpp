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

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    g.assign(n, vector<int>(n, INF));
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u-1][v-1] = min(w, g[u-1][v-1]);
        g[v-1][u-1] = min(w, g[v-1][u-1]);
    }

    for(int i = 0; i < n; i++) g[i][i] = 0;

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]); 
            }
        }
    }

    while(q--){
        int a, b;
        cin >> a >> b;
        
        cout << ((g[a-1][b-1] == INF) ? -1 : min(g[a-1][b-1], g[b-1][a-1])) << '\n';
    }
    
    return 0;
}