#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

vector<vector<ii>> g;
vector<vector<int>> dist;

void dijkstra(int src, int discont){
    int n = g.size();
    dist.assign(2, vector<int>(n, INF));
    priority_queue<iii, vector<iii>, greater<iii>> pq;
    pq.push({0, src, 0});
    dist[0][src] = 0;

    while(!pq.empty()){
        auto [curr_dist, u, div] = pq.top();
        pq.pop();

        if(dist[div][u] < curr_dist) continue;

        for(auto [v, w] : g[u]){
            if(div == 0){
                if(dist[div][u] + discont < dist[1][v]){
                    dist[1][v] = dist[div][u] + discont;
                    pq.push({dist[1][v], v, 1});
                }
            }
            if(dist[div][u] + w < dist[div][v]){
                dist[div][v] = dist[div][u] + w;
                pq.push({dist[div][v], v, div});
            }
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n, m, f;
    cin >> n >> m >> f;

    g.assign(n, vector<ii>());
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u - 1].push_back({v - 1, w});
        g[v - 1].push_back({u - 1, w});
    }
    
    dijkstra(0, f);
    for(int i = 1; i < n; i++){
        cout << (min(dist[0][i],dist[1][i]) == INF ? -1 : min(dist[0][i],dist[1][i])) << '\n';
    }

    return 0;
}