// 
#include <bits/stdc++.h>
using namespace std;
  
#define int unsigned int
  
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1061109567;
const int MOD = 1e9 + 7;

vector<vector<pair<int,int>>> g;
vector<int> dist;

void addedge(int u, int v, int w){
    g[u].emplace_back(v,w);
}

void dijkstra(int src, int n){
    dist.assign(n, INF);
    priority_queue< pair<ll,int> , vector <pair<ll,int>> , greater<pair<ll,int>> > pq;

    pq.push({0,src});
    dist[src] = 0;

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();

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

    int n;
    cin >> n;

    vector<int> v(n,0);
    for(int i = 0; i < n; i++) cin >> v[i];

    g.assign(n, vector<pair<int,int>>());

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            addedge(i,j,v[i] & v[j]);
            // cout << "add " << i << " - " << j << " = " << (v[i] & v[j]) << '\n';
            
            // int digit = (int) log2(v[i]) + 1;
            // cout << "digitos = " << digit << '\n';
            int bi = ~v[i];
            // cout << "bi = " << bi << '\n';

            // digit = (int) log2(v[j]) + 1;
            int bj = ~v[j];

            addedge(i,j,bi & bj);
            // cout << "add " << i << " - " << j << " = " << (bi & bj) << '\n';
        }
    }

    dijkstra(0, n);

    cout << dist[n-1] << '\n';

    return 0;
}