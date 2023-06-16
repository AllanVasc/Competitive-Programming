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

vector<pii> blue, red;

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

int sq(int x){
    return x * x;
}

int dist(pii a, pii b){
    return sq(a.first - b.first) + sq(a.second - b.second);
}

bool check(int maxDist, int n){
    int b = blue.size();
    int r = red.size();
    int src = b + r;
    int sink = src + 1;
    Dinic g(r + b + 2, src, sink);
    // cout << "maxDist = " << maxDist << '\n';
    for(int i = 0 ; i < b; i++){
        for(int j = 0; j < r; j++){
            if(dist(blue[i], red[j]) < maxDist){
                g.addEdge(i, b + j, 1);
                // cout << i << " " << b + j << " dist = " << dist(blue[i], red[j]) << '\n';
            }
        }
    }
    for(int i = 0; i < b; i++) g.addEdge(src, i, 1);
    for(int i = 0; i < r; i++) g.addEdge(b + i, sink, 1);

    int maxFlow = g.run();
    // cout << (r + b - maxFlow >= n) << '\n';
    return r + b - maxFlow >= n;
}

int32_t main() {
    optimize;
    
    int n, b, r;
    cin >> n >> b >> r;
    for(int i = 0; i < b; i++){
        int x, y;
        cin >> x >> y;
        blue.push_back({x, y});
    }
    for(int i = 0; i < r; i++){
        int x, y;
        cin >> x >> y;
        red.push_back({x, y});
    }

    int left = 0;
    int right = 1e10;
    int answ = 0;
    check(9, n);
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(check(mid, n)){
            answ = max(answ, mid);
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    cout << setprecision(8) << fixed;
    cout << sqrtl(answ) << '\n';

    return 0;
}