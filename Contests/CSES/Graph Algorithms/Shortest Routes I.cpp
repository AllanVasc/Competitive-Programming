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
vector<int> dist;

void dijkstra(int start){
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while(!pq.empty()){

        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        
        if(dist[u] < d) continue;
        
        for(auto i : g[u]){
            int v = i.first;
            int w = i.second;

            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }

    }
}

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    g.assign(n, vector<ii>());
    dist.assign(n, INF);
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u-1].push_back({v-1, w});
    }

    dijkstra(0);

    for(int i = 0; i < n; i++){
        cout << dist[i] << " ";
    }
    cout << '\n';
    
    return 0;
}