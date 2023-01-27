//  W - Wormhole
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18; 
 
const int MAXN = 80;
 
vector<pair<int,long double>> adj[MAXN];
 
void addEdge(int u,int v, long double w){
    adj[u].emplace_back(v,w);
}
 
long double dist(int x_1,int y_1,int z_1,
                 int x_2,int y_2,int z_2){
 
    return sqrtl((x_1 - x_2)*(x_1 - x_2)+
                 (y_1 - y_2)*(y_1 - y_2)+
                 (z_1 - z_2)*(z_1 - z_2));
}
 
long double dijkstra(int src, int target){
    vector<long double> dist;
 
    dist.assign(MAXN, LONG_LONG_MAX);
    priority_queue< pair<long double,int>, vector<pair<long double,int>>, greater<pair<long double,int>>> pq;
 
    pq.push(make_pair(0,src));
    dist[src] = 0;
 
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
 
        if(u == target){
            break;
        }
 
        for(auto i : adj[u]){
            int v = i.first;
            long double w = i.second;
 
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v],v));
            }
        }
    }
    return dist[target];
}
 
int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    
    cout << fixed;
    cout << setprecision(0);
 
    int casos = 1;
    while(t--){
        cout << "Case " << casos << ":\n";
 
        map<string,int> name_to_int;
        map<int,string> int_to_name; 
 
        vector<tuple<int,int,int>> coord;
        int n;
        cin >> n;
        
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
 
            name_to_int[s] = i;
            int_to_name[i] = s;
            
            int x,y,z;
            cin >> x >> y >> z;
            coord.emplace_back(x,y,z);
        }
        
        for(int i = 0; i < n; i++){ // Add distances
            for(int j = i+1; j < n; j++){
                addEdge(i,j,dist( get<0>(coord[i]), get<1>(coord[i]), get<2>(coord[i]),
                                  get<0>(coord[j]), get<1>(coord[j]), get<2>(coord[j])));
                addEdge(j,i,dist( get<0>(coord[i]), get<1>(coord[i]), get<2>(coord[i]),
                                  get<0>(coord[j]), get<1>(coord[j]), get<2>(coord[j])));
            }
        }
 
        int w;
        cin >> w;
        for(int i = 0; i < w; i++){ // Add wormhole
            string s1,s2;
            cin >> s1 >> s2;
            addEdge(name_to_int[s1], name_to_int[s2], 0);
        }
 
        int q;
        cin >> q;
        for(int i = 0; i < q; i++){
            string s1,s2;
            cin >> s1 >> s2;
            long double answ = dijkstra(name_to_int[s1],name_to_int[s2]);
            cout << "The distance from " << s1 << " to " << s2 << " is " << answ << " parsecs.\n";
        }
 
        for(int i = 0; i < MAXN; i++) adj[i].clear();
        casos++;
    }
 
    return 0;
}