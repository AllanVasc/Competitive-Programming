// 
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int INF = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;

int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n,m,t,d;
    cin >> n >> m >> t >> d;

    vector<vector<int>> distance;
    set<int> station;

    distance.assign(n, vector<int>(n, INF));

    for(int i = 0; i < t; i++){
        int aux;
        cin >> aux;
        station.insert(aux-1);
    }
    station.insert(0);
    station.insert(n-1);

    for(int i = 0; i < m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        distance[u-1][v-1] = w;
        distance[v-1][u-1] = w;
    }

    for(int i = 0; i < n; i++) distance[i][i] = 0;
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(station.count(i) == 0 || station.count(j) == 0 || distance[i][j] > d) distance[i][j] = INF;
        } 
    }

    for(auto k : station){
        for(auto i : station){
            for(auto j : station){
                distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
            }
        }
    }

    if(distance[0][n-1] != INF) cout << distance[0][n-1] << '\n';
    else cout << "stuck" << '\n';

    return 0;
}
