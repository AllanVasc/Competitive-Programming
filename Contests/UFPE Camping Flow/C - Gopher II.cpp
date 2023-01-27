//  C - Gopher II
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18;

// Dinic's Algorithm to find the Max Flow of a graph
class Dinic{
    int N;
    vector<int> level;
    vector<bool> dead;

public:

    struct Edge{
        Edge(int vertice, int capacity){
            v = vertice;
            cap = capacity;
        }
        int v;
        int cap;
    };
    int source, sink;
    vector<Edge> edge;
    vector<vector<int>> g;

    Dinic(int size, int u, int v){  // Initializing Dinic
        g.resize(size);
        N = size;
        level.resize(size);
        source = u;
        sink = v;
    }

    void addEdge(int u, int v, int cap){ // Making Residual Network
        g[u].push_back(edge.size());    
        edge.push_back(Edge(v,cap));
        g[v].push_back(edge.size());
        edge.push_back(Edge(u,0));
    }

    int run(){

        int flow = 0;
        while(BFS())
            flow += maxflow(source, INF);
        
        return flow;
    }

private:
    
    bool BFS(){ // Construct the Augmenting Level Path

        for(int i = 0; i < N; i++) level[i] = INF;
        dead.clear();
        dead.resize(N, false);
        level[source] = 0;
        queue<int> q;

        q.push(source);
        while(!q.empty()){

            int u = q.front();
            q.pop();

            if(u == sink) return true;

            for(auto x: g[u]){
                if(level[edge[x].v] == INF && edge[x].cap > 0){
                    level[edge[x].v] = level[u] + 1;
                    q.push(edge[x].v);
                }
            }
        }
        return false;
    }

    int maxflow(int u, int flow){

        if(dead[u] || flow == 0) return 0;
        if(u == sink) return flow;

        int answ = 0;

        for(auto i: g[u]){
            if(level[edge[i].v] != level[u] + 1) continue;
            int f = maxflow(edge[i].v, min(edge[i].cap, flow));
            int reversed_i = (i%2 == 0 ? i+1 : i-1);    // Finding the "even" edge of "i"
            flow -= f;
            answ += f;
            edge[i].cap -= f;
            edge[reversed_i].cap += f;
        }

        if(answ == 0) dead[u] = true;
        return answ;
    }
};

double distance(pair<double,double> a, pair<double,double> b){

    return sqrt( (a.first - b.first)*(a.first - b.first) +
                 (a.second - b.second)*(a.second - b.second));
}
int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,s,v;
    while(cin >> n >> m >> s >> v){

        Dinic g(n+m+2,0,n+m+1);

        vector<pair<double,double>> gophers;
        for(int i = 0; i < n; i++){
            double x,y;
            cin >> x >> y;
            gophers.push_back({x,y});
        }

        for(int i = 0; i < m; i++){
            double x,y;
            cin >> x >> y;
            for(int j = 0; j < gophers.size(); j++){
                if(distance(gophers[j],{x,y})/double(v) <= s){
                    g.addEdge(j+1,n+i+1, 1);
                }
            }
        }

        for(int i = 1; i <= n; i++) g.addEdge(0, i, 1);
        for(int i = 1; i <= m; i++) g.addEdge(n+i, n+m+1, 1);
        
        cout << n - g.run() << '\n';
    }

    return 0;
}
