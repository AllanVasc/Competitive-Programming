#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18;
const int MOD = 998244353;

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
vector<vector<int>> dir = { {-1, 0}, {1, 0}, {0, 1}, {0, -1}};

bool is_border(int r, int c, int n, int m){
    return (r == 0 || r == n - 1) || (c == 0 || c == m - 1);
}

bool is_valid(int r, int c, int n, int m){
    if(r < 0 || r >= n) return false;
    if(c < 0 || c >= m) return false;
    return true;
}

void debug(int u, int v, int custo){
    cout << "ligando " << u << " com " << v << " com custo = " << custo <<  '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, m, c;
    cin >> n >> m >> c;
    swap(n, m);
    vector<string> grid;
    for(int i = 0; i < n; i++){
        string aux;
        cin >> aux;
        grid.push_back(aux);
    }
    vector<int> costs(c);
    for(int i = 0; i < c; i++) cin >> costs[i];

    int source = 2 * n * m + 4;
    int sink = 2 * n * m + 5;
    Dinic g(2 * n*m + 100, source, sink);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            // cout << "i = " << i << " j = " << j << " :" << grid[i][j] << '\n';
            if(grid[i][j] == 'B'){
                // cout << "eh B" << '\n';
                // debug(source, i*m + j, INF);
                // debug(i*m + j, n*m + i*m + j, INF);

                g.addEdge(source, i*m + j, INF);
                g.addEdge(i*m + j, n*m + i*m + j, INF);
            }
            if(grid[i][j] == '.'){
                // cout << "eh ." << '\n';
                // debug(i*m + j, n*m + i*m + j, INF);
                g.addEdge(i*m + j, n*m + i*m + j, INF);
            }
            if(isalpha(grid[i][j]) && grid[i][j] != 'B'){
                // cout << "eh letra" << '\n';
                // debug(i*m + j, n*m + i*m + j, costs[grid[i][j] - 'a']);
                g.addEdge(i*m + j, n*m + i*m + j, costs[grid[i][j] - 'a']);
            }
            if(is_border(i, j, n, m)){
                // cout << "eh borda" << '\n';
                // debug(n*m + i*m + j, sink, INF);
                g.addEdge(n*m + i*m + j, sink, INF);
            }

            for(auto offset : dir){
                int rr = i + offset[0];
                int cc = j + offset[1];
                if(is_valid(rr, cc, n, m)){
                    g.addEdge(n*m + i*m + j, rr*m + cc, INF);
                }
            }
        }
    }

    int answ = g.run();
    cout << (answ == INF ? -1 : answ) << '\n';
    return 0;
}