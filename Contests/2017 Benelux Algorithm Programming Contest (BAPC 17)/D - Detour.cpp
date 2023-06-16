#include <bits/stdc++.h>

using namespace std;
#define int long long

vector <vector <pair <int, int>>> g;
const int inf = 1e18;
// int n;
// set <pair <int, int>> toRemove;

// vector <int> dikstra(){
//     vector <int> path;
//     vector <int> par(n, -1);

//     vector <int> dist(n, inf);
//     priority_queue <tuple <int, int>, vector <tuple <int, int>>, greater <tuple <int, int>>> pq;

//     dist[1] = 0;
//     pq.emplace(0, 1);

//     while(!pq.empty()){
//         int u, w;
//         tie(w, u) = pq.top();

//         pq.pop();

//         if(dist[u] != w) continue;

//         for(auto i:g[u]){
//             if(dist[i.first] > dist[u] + i.second){
//                 dist[i.first] = dist[u] + i.second;
//                 par[i.first] = u;
//                 pq.emplace(dist[i.first], i.first);
//             }
//         }
//     }

//     if(dist[0] >= inf) return path;

//     for(int i = 0; i < n; i++){
//         if(i == 1) continue;

//         for(auto j:g[i]){
//             if(dist[i] == dist[j.first] + j.second){
//                 // cout << i << " " << j.first << "\n";
//                 toRemove.emplace(i, j.first);
//                 toRemove.emplace(j.first, i);
//                 continue;
//             }
//         }
//     }

//     int cur = 0;
//     while(~cur){
//         path.push_back(cur);
//         cur = par[cur];
//     }

//     // cout << path.size() << "\n";

//     return path;
// }

// void exclude(){

//     vector <vector <pair <int, int>>> ng(n);

//     for(int i = 0; i < n; i++){
//         for(auto j:g[i]){
//             if(toRemove.find(make_pair(i, j.first)) == toRemove.end()){
//                 ng[i].push_back(j);
//             }
//         }
//     }

//     g = ng;
// }

vector<int> parent;
bool dijkstra(int src){
    int n = g.size();
    parent.assign(n, -1);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(n, inf);
    pq.push({0, src});
    dist[src] = 0;
    while(!pq.empty()){
        auto [cost, u] = pq.top();
        pq.pop();
        if(cost > dist[u]) continue;
        for(auto [v,w] : g[u]){
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
                parent[v] = u;
            }
        }
    }

    if(dist[0] == inf) return false;
    return true;
}

vector<int> path;
bool bfs(int src){
    queue<int> q;
    q.push(src);
    int n = g.size();
    vector<int> visited(n, false);
    visited[src] = true;
    vector<int> newParent(n, -1);
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        for(auto [v,w] : g[u]){
            if(parent[u] == v) continue;
            if(visited[v]) continue;
            newParent[v] = u;
            q.push(v);
            visited[v] = true;
        }
    }

    if(visited[1] == 0) return false;
    int curr = 1;
    while(curr != -1){
        path.push_back(curr);
        curr = newParent[curr];
    }
    reverse(path.begin(), path.end());
    return true;
}



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    g.assign(n, vector<pair<int,int>>());
    for(int i = 0; i < m; i++){
        int u, v, d;
        cin >> u >> v >> d;
        g[u].push_back({v, d});
        g[v].push_back({u, d});
    }

    if(dijkstra(1)){
        if(bfs(0)){
            cout << path.size() << " ";
            for(auto u : path){
                cout << u << " ";
            }
            cout << '\n';
        }
        else{
            cout << "impossible" << '\n';
        }
    }
    else{
        cout << "impossible" << '\n';
    }

    return 0;
}

// signed main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0), cout.tie(0);

//     int m;
//     cin >> n >> m;

//     g.resize(n);

//     for(int i = 0; i < m; i++){
//         int a, b, w;
//         cin >> a >> b >> w;

//         g[a].emplace_back(b, w);
//         g[b].emplace_back(a, w);
//     }

//     vector <int> path;
//     path = dikstra();

//     exclude();
//     path = dikstra();

//     if(!path.empty()){
//         cout << path.size();
//         for(int i = 0; i < path.size(); i++) cout << " " << path[i];
//         cout << "\n";
//     }
//     else cout << "impossible\n";

//     return 0;
// }