#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

// Dinic's Algorithm to find the Max Flow of a graph
class Dinic{
    int N;
    vector<int> level;
    vector<bool> dead;
    const int INF = 1e18;

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
        N = size;
        g.resize(N);
        level.resize(N);
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

    // Algorithm to find the edges from MinCut by dividing the graph into 2 subgraphs.
    void mincut(){

        set<int> reachable; // 2 subgraphs
        set<int> unreachable;

        vector<bool> visited(N, false);
        queue<int> q;
        q.push(source);
        reachable.insert(source);

        while(!q.empty()){  // BFS to find all vertices that are reached by the source using positive-capacity edges

            int u = q.front();
            visited[u] = true;
            q.pop();

            for(auto x: g[u]){
                if(!visited[edge[x].v] && edge[x].cap > 0){
                    q.push(edge[x].v);
                    reachable.insert(edge[x].v);
                }
            }
        }
        
        for(int i = 0; i < N; i++){ // If the graph is 0-based you need to put i = 0
            if(reachable.find(i) == reachable.end())
                unreachable.insert(i);
        }

        bool flag = true;
        for(auto i: reachable){ // Printing edges responsible for connecting the 2 subgraphs
            for(auto j: g[i]){
                if(unreachable.find(edge[j].v) != unreachable.end()){
                    if(flag == true)cout << i + 1 << " " << edge[j].v + 1 << '\n';
                    flag = flag^true;
                }
            }
        }
    }

    // Algorithm to find edges from Maximum Matching of a bipartite graph (may have variations which capacity need not be 0)
    void max_matching(int n, int m){

        for(int i = 1; i <= n + m; i++){
            for(auto j: g[i]){
                if(j%2 == 0 && edge[j].cap == 0){
                    if(edge[j].v != 0 && edge[j].v != n+m+1)
                        cout << i << " " << edge[j].v - n << '\n';
                }
            }
        }
    }

private:
    bool BFS(){ // Construct the Augmenting Level Path
        level.assign(N, INF);
        dead.assign(N, false);
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
            int reversed_i = (i % 2 == 0 ? i + 1 : i - 1);    // Finding the "even" edge of "i"
            flow -= f;
            answ += f;
            edge[i].cap -= f;
            edge[reversed_i].cap += f;
        }

        if(answ == 0) dead[u] = true;
        return answ;
    }
};


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n, m;
    cin >> n >> m;

    Dinic g(n, 0, n - 1);
    for(int i = 0; i < m ; i ++){
        int u, v, w = 1;
        cin >> u >> v;
        g.addEdge(u - 1, v - 1, w);
        g.addEdge(v - 1, u - 1, w);
    }

    cout << g.run() << '\n';
    g.mincut();

    return 0;
}