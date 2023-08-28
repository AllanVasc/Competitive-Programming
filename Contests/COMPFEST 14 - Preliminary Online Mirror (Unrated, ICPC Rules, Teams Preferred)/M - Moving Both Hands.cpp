#include <bits/stdc++.h>

using namespace std;
#define int long long

typedef pair <int, int> ii;
vector <vector <ii>> g, gi;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    g.resize(n);
    gi.resize(n);

    for(int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;

        x--; y--;

        g[x].emplace_back(y, w);
        gi[y].emplace_back(x, w);
    }

    int inf = 1e15;
    vector <vector <int>> dist(n, vector <int>(2, inf));

    dist[0][0] = 0;
    dist[0][1] = 0;

    priority_queue <tuple <int, int, int>, vector <tuple <int, int, int>>, greater <tuple <int, int, int>>> pq;
    pq.emplace(0, 0, 0);
    pq.emplace(0, 0, 1);

    while(!pq.empty()){
        auto [w, v, flag] = pq.top();
        pq.pop();

        if(dist[v][flag] < w) continue;

        for(auto [u, weight]:gi[v]){
            if(dist[u][1] > dist[v][flag] + weight){
                dist[u][1] = dist[v][flag] + weight;
                pq.emplace(dist[u][1], u, 1);
            }
        }

        if(!flag){
            for(auto [u, weight]:g[v]){
                if(dist[u][0] > dist[v][flag] + weight){
                    dist[u][0] = dist[v][0] + weight;
                    pq.emplace(dist[u][0], u, 0);
                }
            }
        }
    }

    for(int i = 1; i < n; i++){
        if(i-1) cout << " ";

        if(min(dist[i][0], dist[i][1])  == inf) cout << "-1";
        else cout << min(dist[i][0], dist[i][1]);
    }
    cout << "\n";

    return 0;
}