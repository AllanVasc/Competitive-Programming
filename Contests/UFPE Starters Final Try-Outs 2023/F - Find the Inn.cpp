#include<bits/stdc++.h>
using namespace std;

#define int long long
using ii = pair<int,int>;
const int INF = 1e18;

vector<vector<ii>> g;

int dijkstra(int src){
    int n = g.size();
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    vector<int> dist(n, LONG_LONG_MAX);
    pq.push({0, src});
    dist[src] = 0;
    while(!pq.empty()){
        auto [cost, u] = pq.top();
        pq.pop();
        if(cost > dist[u]) continue;
        for(auto [v, w] : g[u]){
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist[n - 1];
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n, m, t, k, p;
    cin >> n >> m >> t >> k >> p;
    map<int,int> special;
    for(int i = 0; i < p; i++){
        int u;
        cin >> u;
        u--;
        special[u] = 1;
    }
    g.assign(n, vector<ii>());
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        w = 60*w;
        g[u].push_back({v, w + k * special[v]});
        // g[v].push_back({u, w + k * special[u]});
    }

    int mn = dijkstra(0);
    cout << (mn <= 60*t ? mn : -1) << '\n';
    return 0;
}