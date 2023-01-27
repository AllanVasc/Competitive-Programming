//  D - Array and Operations
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

int32_t main(){
 
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);

    int n,m;
    cin >> n >> m;

    vector<int> numbers;
    numbers.resize(n);
    for(int i = 0; i < n; i++) cin >> numbers[i];

    vector<vector<ii>> factors;
    set<int> s;
    factors.resize(n);

    for(int i = 0; i < n; i++){
        int aux = numbers[i];
        for(int j = 2; j*j <= numbers[i]; j++){
            int count = 0;
            while(aux%j == 0){
                aux /= j;
                count++;
            }
            if(count != 0){
                s.insert(j);
                factors[i].push_back({j,count});
            }
        }
        if(aux != 1){
            s.insert(aux);
            factors[i].push_back({aux,1});
        }
    }

    // cout << "DIVISORES: " << '\n';
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < factors[i].size(); j++)
    //         cout << factors[i][j].first << "^" << factors[i][j].second << " " ;
    //     cout << '\n';
    // }

    vector<ii> edges;
    edges.resize(m);
    for(int i = 0; i < m; i++) cin >> edges[i].first >> edges[i].second;

    int answ = 0;

    for(auto itr: s){
        Dinic g(n+2,0,n+1);

        for(int j = 0; j < m; j++){
            if(edges[j].first%2 == 0) swap(edges[j].first, edges[j].second);
            g.addEdge(edges[j].first, edges[j].second, INF);
        }

        for(int j = 0; j < n; j+=2){ // ODD
            ii aux = {itr,0};
            auto prime = upper_bound(factors[j].begin(), factors[j].end(), aux);
            if(prime != factors[j].end() && prime->first == itr){
                g.addEdge(0, j+1, prime->second);
            }
        }

        for(int j = 1; j < n; j+=2){ // EVEN
            ii aux = {itr,0};
            auto prime = upper_bound(factors[j].begin(), factors[j].end(), aux);
            if(prime != factors[j].end() && prime->first == itr){
                g.addEdge(j+1, n+1, prime->second);
            }
        }

        answ += g.run();
    }
        
        cout << answ << '\n';

    return 0;
}
