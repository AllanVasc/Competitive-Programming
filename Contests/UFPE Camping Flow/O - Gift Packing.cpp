//  O - Gift Packing
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18;

// Implementation of the Min Cost Flow algorithm
class MinCostFlow{
private:
    struct Edge{
        int u,v,cap,cost,flow;
        Edge(int from, int to, int cap, int cost):
            u(from), v(to), cap(cap), cost(cost), flow(0) {}
    };
    int n, source, sink;
    vector<Edge> edge;
    vector<vector<int>> g;
    vector<int> dist;
    vector<int> parent;

public:
    MinCostFlow(int n, int source, int sink){ // Initializing
        this->n = n;
        this->source = source;
        this->sink = sink;
        g.assign(n, vector<int>());
    }

    void addEdge(int u, int v, int cap, int cost){
        int m = edge.size();
        edge.emplace_back(u, v, cap, cost);
        g[u].push_back(m);
        edge.emplace_back(v, u, 0, -cost);
        g[v].push_back(m+1);
    }

    ii run(int k){  // Running Min Cost Flow, to calculate Min Cost Max Flow put k = INF
        ii answ = {0,0};    // {flow, cost}
        while(answ.first < k && spfa()){
            ii aux = get_flow_and_cost();   // {flow, cost}
            int max_add = min(aux.first, k - answ.first);

            answ.first += max_add;
            answ.second += max_add * aux.second;
        }
        return answ;
    }

private:
    bool spfa(){ // Shortest Path Faster Algorithm
        dist.assign(n, INF);
        parent.assign(n, -1);
        queue<int> q;
        vector<bool> inqueue(n, false);
        vector<int> count(n, 0);

        dist[source] = 0;
        q.push(source);
        inqueue[source] = true;

        while(!q.empty()){
            int u = q.front();
            q.pop();
            inqueue[u] = false;

            for(auto id: g[u]){
                Edge aux = edge[id];

                int new_dist = dist[u] + aux.cost;
                if(aux.cap - aux.flow > 0 && new_dist < dist[aux.v]){
                    
                    parent[aux.v] = id;
                    dist[aux.v] = new_dist;

                    if(!inqueue[aux.v]){
                        q.push(aux.v);
                        inqueue[aux.v] = true;

                        count[aux.v]++;
                        if(count[aux.v] > n) return false; // Found a negative cycle
                    }
                }
            }
        }
        return dist[sink] < INF;
    }

    ii get_flow_and_cost(){
        ii flow_cost = {INF,0};

        int v = sink;
        while(v != source){
            Edge aux = edge[parent[v]]; 
            flow_cost.first = min(flow_cost.first, aux.cap - aux.flow);
            flow_cost.second += aux.cost;
            v = aux.u;
        }

        v = sink;
        while(v != source){
            edge[parent[v]].flow += flow_cost.first;
            edge[parent[v] ^ 1].flow -= flow_cost.first;
            v = edge[parent[v]].u;
        }
        return flow_cost;
    }
};

int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    int count = 1;

    while(t--){
        int n;
        cin >> n;

        MinCostFlow g(2*n+2, 0, 2*n+1);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int cost_i_j;
                cin >> cost_i_j;
                g.addEdge(i+1,n+j+1,1, -cost_i_j);
            }
        }

        for(int i = 1; i <= n; i++) g.addEdge(0, i,1,0);
        for(int i = 1; i <= n; i++) g.addEdge(n+i,2*n+1,1,0);

        cout << "Case " << count << ": " << abs(g.run(INF).second) << '\n';
        count++;
    }
    return 0;
}
