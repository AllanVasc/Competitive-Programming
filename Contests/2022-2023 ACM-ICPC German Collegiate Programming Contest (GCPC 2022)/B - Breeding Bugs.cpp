#include <bits/stdc++.h>
using namespace std;

#define int long long
#define optimize ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define iii tuple<int,int,int>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

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

int32_t main() {
    optimize;
    
    // Given a graph with n vertices where two vertices are connected iff their sum is prime,
    // find a maximum independent set.
    const int maxVal = 2e7;
    vector<bool> isp(maxVal + 1, true);
    isp[0] = isp[1] = false;
    for(int i = 2; i <= maxVal; i++){
        if(!isp[i]) continue;
        for(int j = i * i; j <= maxVal; j += i)
            isp[j] = false;
    }
    int n;
    cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    vector<pii> even, odd;
    int qtdOnes = 0;
    for(int i = 0; i < n; i++){
        if(v[i] == 1) qtdOnes++;
        if(v[i] == 1 && qtdOnes > 1) continue;
        if(v[i] % 2 == 0){
            even.push_back({v[i], i});
        }
        else{
            odd.push_back({v[i], i});
        }
    }
    int src = n;
    int sink = n + 1;
    Dinic g(n + 5, src, sink);
    for(int i = 0; i < odd.size(); i++){
        auto [odd1, idx1] = odd[i];
        for(int j = 0; j < even.size(); j++){
            auto [even1, idx2] = even[j];
            if(isp[odd1 + even1]){
                g.addEdge(idx1, idx2, 1);
            }
        }
    }
    for(auto [x, i] : odd) g.addEdge(src, i, 1);
    for(auto [x, i] : even) g.addEdge(i, sink, 1);
    cout << n - max(0LL, (qtdOnes - 1)) - g.run() << '\n';
    return 0;
}