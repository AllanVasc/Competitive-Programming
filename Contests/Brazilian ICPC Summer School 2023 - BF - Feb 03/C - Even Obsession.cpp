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

int dijkstra(int src){
    int n = g.size();
    vector<vector<int>> dist(2, vector<int>(n, INF));
    priority_queue<iii, vector<iii>, greater<iii>> pq;
    pq.push({0, src, 0}); // dist, vtx, state
    dist[0][src] = 0;
    while(!pq.empty()){
        auto [d, u, state] = pq.top();
        pq.pop();

        if(dist[state][u] < d) continue;

        for(auto [v, w] : g[u]){
            int new_state = !state;
            if(dist[new_state][v] > dist[state][u] + w){
                dist[new_state][v] = dist[state][u] + w;
                pq.push( {dist[new_state][v], v, new_state});
            }

        }
    }
    return (dist[0][n - 1] == INF ? -1 : dist[0][n - 1]);
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int c, v;
    while(cin >> c >> v){
        g.assign(c, vector<ii>());
        for(int i = 0; i < v; i++){
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }
        cout << dijkstra(0) << '\n';
    }
    return 0;
}