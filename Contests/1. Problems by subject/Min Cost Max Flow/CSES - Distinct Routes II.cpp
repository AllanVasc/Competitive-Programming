#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

// Implementation of the Min Cost Max Flow algorithm using Dijkstra
struct MCMF{
    struct Edge{
        int from, to, cap, cost, flow;
        Edge(int from, int to, int cap, int cost) :
        from(from), to(to), cap(cap), cost(cost), flow(0) {}
    };
    int n, src, sink;
    const int INF = 1e18;
    vector<Edge> edgeList;
    vector<vector<int>> g;
    vector<int> dist, pot, parent;

    int dirty = false;
    void dfs(int u,vector<bool> &visited, vector<int> &aux){
        if(u == sink){
            if(dirty) return;
            cout << aux.size() << '\n';
            for(auto i : aux) cout << i + 1 << " ";
            cout << '\n';
            dirty = true;
        }
        else{
            for(auto x : g[u]){
                int v = edgeList[x].to;
                if(u == src) dirty = false;
                if(x % 2 == 0 && edgeList[x].flow && !dirty){
                    if(!visited[x]){
                        visited[x] = true;
                        aux.push_back(v);
                        dfs(v, visited, aux);
                        aux.pop_back();
                    }
                }
            }
        }
    }
 
    void solve(){
        vector<bool> visited(edgeList.size(), false);
        vector<int> aux;
        aux.push_back(src);
        dfs(src, visited, aux);
    }

    MCMF(int n, int src, int sink){
        this->n = n;
        this->src = src;
        this->sink = sink;
        g.assign(n, vector<int>());
        dist.assign(n, INF);
        pot.assign(n, 0);
    }

    void addEdge(int from, int to, int cap, int cost){
        int m = edgeList.size();
        edgeList.push_back(Edge(from, to, cap, cost));
        g[from].push_back(m);
        edgeList.push_back(Edge(to, from, 0, -cost));
        g[to].push_back(m + 1);
    }

    // {flow, cost} To calculate Min Cost Max Flow put k = INF
    ii run(int k){
        ii answ = {0, 0};
        // If there are negative weights in the initial graph 
        // it is necessary to run spfa once to configure the potentials
        // spfa();
        fixPot();
        while(answ.first < k && spfa()){
            ii flow = augment();
            int max_add = min(flow.first, k - answ.first);
            answ.first += max_add;
            answ.second += max_add * flow.second;
            fixPot();
        }
        return answ;
    }

    // {flow, cost}
    ii augment(){
        ii flow = {INF, 0};

        int v = sink;
        while(v != src){
            Edge aux = edgeList[parent[v]];
            flow.first = min(flow.first, aux.cap - aux.flow);
            flow.second += aux.cost;
            v = aux.from;
        }

        v = sink;
        while(v != src){
            edgeList[parent[v]].flow += flow.first;
            edgeList[parent[v] ^ 1].flow -= flow.first;
            v = edgeList[parent[v]].from;
        }
        return flow;
    }

    bool spfa(){
        dist.assign(n, INF);
        parent.assign(n, -1);
        queue<int> q;
        vector<bool> inqueue(n, false);
        vector<int> count(n, 0);
        dist[src] = 0;
        q.push(src);
        inqueue[src] = true;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            inqueue[u] = false;
            for(auto id : g[u]){
                Edge aux = edgeList[id];
                if(aux.cap - aux.flow == 0) continue;
                int new_dist = dist[u] + aux.cost + pot[u] - pot[aux.to];
                if(new_dist < dist[aux.to]){
                    parent[aux.to] = id;
                    dist[aux.to] = new_dist;
                    if(!inqueue[aux.to]){
                        q.push(aux.to);
                        inqueue[aux.to] = true;
                        count[aux.to]++;
                        if(count[aux.to] > n) return false; // Found a negative cycle
                    }
                }
            }
        }
        return dist[sink] < INF;
    }

    bool dijkstra(){
        dist.assign(n, INF);
        parent.assign(n, -1);
        priority_queue<ii, vector<ii>, greater<ii>> pq;
        pq.push({0, src});
        dist[src] = 0;
        while(!pq.empty()){
            auto [d, u] = pq.top();
            pq.pop();
            if(dist[u] < d) continue;
            for(auto id : g[u]){
                Edge aux = edgeList[id];
                if(aux.cap - aux.flow == 0) continue;
                int new_dist = dist[u] + aux.cost + pot[u] - pot[aux.to];
                if(new_dist < dist[aux.to]){
                    dist[aux.to] = new_dist;
                    parent[aux.to] = id;
                    pq.push({new_dist, aux.to});
                }
            }
        }
        return dist[sink] < INF;
    }

    void fixPot(){
        for(int i = 0; i < n; i++){
            if(dist[i] < INF) pot[i] += dist[i];
        }
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    int source = 0;
    int sink = n - 1;
    MCMF mcmf(n, source, sink);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        mcmf.addEdge(u, v, 1, 1);
    }
    ii answ = mcmf.run(k);
    if(answ.first != k){
        cout << -1 << '\n';
    }
    else{
        cout << answ.second << '\n';
        mcmf.solve();
    }
    return 0;
}