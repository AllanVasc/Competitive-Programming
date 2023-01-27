#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

vector<vector<pair<int,int>>> g;

int spfa(int src){
    int n = g.size();
    
    vector<int> dist(n, INF);
    vector<int> visited(n, 0);
    queue<int> q;

    dist[src] = 0;
    q.push(src);
    visited[src] = 1;

    while(!q.empty()){

        int u = q.front();
        q.pop();
        visited[u] = false;

        for(auto edge : g[u]){
            int v = edge.first;
            int curr_dist = edge.second;

            if( max(dist[u] + curr_dist,(int) 0) < dist[v]){
                dist[v] = max(dist[u] + curr_dist,(int) 0);
                if(!visited[v]){
                    q.push(v);
                    visited[v] = 1;
                }
            }
        }
    }
    return dist[n-1];
}

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    g.assign(n, vector<pair<int,int>>());
    for(int i = 0; i < m; i++){
        int x,y,a,b;
        cin >> x >> y >> a >> b;
        g[x-1].push_back({y-1, a-b});
    }

    int answ = spfa(0);
    if(answ == INF) cout << -1 << '\n';
    else cout << answ << '\n';

    return 0;
}