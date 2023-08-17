#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MAXN = 1e5+5;
int dist[MAXN][7], vis[MAXN][7];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, s, k;
    cin >> n >> m >> s >> k;
    s--;
    k--;

    memset(dist, 0x3f, sizeof dist);
    vector <vector <vector <int>>> g(n, vector <vector <int>>(7));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 7; j++){
            g[i][j].push_back(i);
        }
    }

    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;

        u--, v--, w--;

        g[u][w].push_back(v);
        g[v][w].push_back(u);
    }

    queue <pair <int, int>> q;
    dist[s][0] = 0;
    vis[s][0] = 1;

    q.emplace(s, 0);
    
    while(!q.empty()){
        
        int u, w;
        tie(u, w) = q.front();
        q.pop();

        for(auto i:g[u][w]){
            if(vis[i][(w+1) % 7]) continue;
            vis[i][(w+1) % 7] = 1;
            dist[i][(w+1) % 7] = dist[u][w] + 1;
            q.emplace(i,(w+1) % 7);
        }
    }

    int ans = 1e9;
    for(int i = 0; i < 7; i++){
        ans = min(ans, dist[k][i]);
        // cout << dist[k][i] << "\n";
    }
    
    cout << ans << "\n";

    return 0;
}