#include <bits/stdc++.h>
using namespace std;
  
#define int long long
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

vector<tuple<int,int,int>> edgeList;
vector<int> dist;

// Bellman-Ford Algorithm (Single source shortest path with negative weight edges)
// Returns true if valid answer exists.
bool bellmanFord(int src, int n){
    const int INF = 0x3f3f3f3f3f3f3f3f;
    const int NINF = -INF; 
    dist.assign(n, INF);
    dist[src] = 0;

    // Relax all edges n - 1 times. If we're sure that we don't have
    // negative cycles, we can use a flag to stop when there isn't update
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < edgeList.size(); j++){
            int u, v, w;
            tie(u,v,w) = edgeList[j];
            if(dist[u] == INF) continue;
            dist[v] = min(dist[v], dist[u] + w);
            dist[v] = max(dist[v], NINF);
        }
    }

    // Check the existence of a negative cycle. If you have only one update we can return true.
    // We perform n - 1 steps to check if the cycle affects a specific node.
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < edgeList.size(); j++){
            int u, v, w;
            tie(u,v,w) = edgeList[j];
            if(dist[u] == INF) continue;
			if(dist[u] + w < dist[v]) dist[v] = NINF; // We can only return false here
        }
    }

    // There isn't negative cycle and our answer is in dist
    // change to "return dist[node] != NINF" to verify a specific node.
    return dist[n - 1] != NINF;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edgeList.push_back({u - 1, v - 1, -w});
    }

    if(bellmanFord(0, n)){
        cout << -dist[n-1] << '\n';
    }
    else{
        cout << -1 << '\n';
    }

    return 0;
}