#include <bits/stdc++.h>
using namespace std;

#define int long long
using ll = long long;

const ll INF = 1e9 + 7;

// Dinic's Algorithm to find the Max Flow of a graph
class Dinic{
    int N;
    vector<ll> level;
    vector<bool> dead;

public:

    struct Edge{
        Edge(int vertice, ll capacity){
            v = vertice;
            cap = capacity;
        }
        ll v;
        ll cap;
    };
    int source;
    int sink;
    vector<Edge> edge;
    vector<vector<int>> g;

    Dinic(int size, int u, int v){  // Initializing Dinic
        g.resize(size);
        N = size;
        level.resize(size);
        source = u;
        sink = v;
    }

    void addEdge(int u, int v, ll cap){ // Making Residual Network
        g[u].push_back(edge.size());    
        edge.push_back(Edge(v,cap));
        g[v].push_back(edge.size());
        edge.push_back(Edge(u,0));
    }

    ll run(){

        ll flow = 0;
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
        
        for(int i = 1; i < N; i++){ // If the graph is 0-based you need to put i = 0
            if(reachable.find(i) == reachable.end())
                unreachable.insert(i);
        }

        bool flag = true;
        for(auto i: reachable){ // Printing edges responsible for connecting the 2 subgraphs
            for(auto j: g[i]){
                if(unreachable.find(edge[j].v) != unreachable.end()){
                    if(flag == true)cout << i << " " << edge[j].v << '\n';
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

    ll maxflow(int u, ll flow){

        if(dead[u] || flow == 0) return 0;
        if(u == sink) return flow;

        ll answer = 0;

        for(auto i: g[u]){
            if(level[edge[i].v] != level[u] + 1) continue;
            ll f = maxflow(edge[i].v, min(edge[i].cap, flow));
            int reversed_i = (i%2 == 0 ? i+1 : i-1);    // Finding the "even" edge of "i"
            flow -= f;
            answer += f;
            edge[i].cap -= f;
            edge[reversed_i].cap += f;
        }

        if(answer == 0) dead[u] = true;
        return answer;
    }
};

/*

Time Complexity

Dinic                               -> O(V²E)
Dinic Maximum Matching              -> O(E*sqrt(V))
Dinic in Unit Capacities Networks   -> O(E*V^(2/3))

Links:

https://www.geeksforgeeks.org/ford-fulkerson-algorithm-for-maximum-flow-problem/
https://www.youtube.com/watch?v=oHy3ddI9X3o
https://cp-algorithms.com/graph/edmonds_karp.html
https://cp-algorithms.com/graph/dinic.html
https://www.youtube.com/watch?v=M6cm8UeeziI
https://www.youtube.com/watch?v=duKIzgJQ1w8

*/