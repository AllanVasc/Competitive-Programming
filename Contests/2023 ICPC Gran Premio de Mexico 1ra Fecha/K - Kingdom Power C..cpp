#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long

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

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, s, e;
    cin >> n >> s >> e;
    int source = 2*n;
    int sink = 2*n + 1;
    Dinic g(2*n + 2, source, sink);
    for(int i = 0; i < s; i++){
        int startlevel;
        cin >> startlevel;
        startlevel--;
        g.addEdge(source, startlevel, 1);
    }
    for(int i = 0; i < e; i++){
        int endLevel;
        cin >> endLevel;
        endLevel--;
        g.addEdge(endLevel + n, sink, 1);
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g.addEdge(u + n, v, 1);
    }
    for(int i = 0; i < n; i++) g.addEdge(i, i + n, 1);
    cout << g.run() << '\n';
    return 0;
}