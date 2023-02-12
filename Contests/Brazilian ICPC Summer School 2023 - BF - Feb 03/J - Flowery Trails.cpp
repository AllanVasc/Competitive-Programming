#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 998244353;

const int MAXN = 1e5;
vector<vector<ii>> g;

vector<int> dijkstra(int src){
    int n = g.size();
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    vector<int> dist(n, INF);
    pq.push({0, src});
    dist[src] = 0;
    while(!pq.empty()){
        auto [d, u] = pq.top();
        pq.pop();
        if(dist[u] < d) continue;
        for(auto [v, w] : g[u]){
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, t;
    cin >> n >> t;
    g.assign(n, vector<ii>());
    for(int i = 0; i < t; i++){
        int u, v, len;
        cin >> u >> v >> len;
        g[u].push_back({v, len});
        g[v].push_back({u, len});
    }
    vector<int> dist_src = dijkstra(0);
    vector<int> dist_sink = dijkstra(n - 1);
    int answ = 0;
    for(int u = 0; u < n; u++){
        for(auto [v, len] : g[u]){
            if(dist_src[n - 1] == dist_src[u] + len + dist_sink[v]){
                answ += len;
            }
        }
    }
    cout << 2 * answ << '\n';
    return 0;
}