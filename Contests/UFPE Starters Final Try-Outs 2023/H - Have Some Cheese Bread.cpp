#include<bits/stdc++.h>
using namespace std;

#define int long long
using ii = pair<int,int>;
const int INF = 1e18;

vector<vector<ii>> g;

int dijkstraMin(int src){
    int n = g.size();
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    vector<int> dist(n, INF);
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

int dijkstraMax(int src){
    int n = g.size();
    priority_queue<ii, vector<ii>> pq;
    vector<int> dist(n, -1);
    pq.push({0, src});
    dist[src] = 0;
    while(!pq.empty()){
        auto [cost, u] = pq.top();
        pq.pop();
        if(cost < dist[u]) continue;
        for(auto [v, w] : g[u]){
            if(dist[v] < dist[u] + w){
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
    
    int n, c, m;
    cin >> n >> c >> m;
    map<int, int> special;
    g.assign(n, vector<ii>());
    for(int i = 0; i < c; i++){
        int u;
        cin >> u;
        u--;
        special[u]++;
    }
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back({v, special[u]});
    }
    int minAnsw = dijkstraMin(0);
    int maxAnsw = dijkstraMax(0);
    cout << minAnsw + special[n - 1] << " " << maxAnsw + special[n - 1] << '\n';

    return 0;
}