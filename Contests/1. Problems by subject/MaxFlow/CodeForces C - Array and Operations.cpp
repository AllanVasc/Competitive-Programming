// CodeForces C - Array and Operations
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = 0x3f3f3f3f;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
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

int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n, m;
    cin >> n >> m;

    vector<int> numbers;

    vector<vector<ii>> factor;

    numbers.resize(n);
    factor.resize(n);
    for(int i = 0; i < n; i++){
        cin >> numbers[i];
    }

    set<int> primes;

    for(int i = 0; i < n; i++){
        int aux = numbers[i];
        for(int j = 2; j*j <= aux && aux != 1; j++){
            int cnt = 0;
            while(aux%j == 0){
                cnt++;
                aux = aux/j;
            }
            if(cnt != 0){
                factor[i].push_back({j,cnt});
                primes.insert(j);
            }
        }
        if(aux != 1){
            factor[i].push_back({aux,1});
            primes.insert(aux);
        }
    }

    vector<ii> pairs;
    pairs.resize(m);
    for(int i = 0; i < m; i++){
        cin >> pairs[i].first >> pairs[i].second;
    }

    int answ = 0;
    for(auto i: primes){
        Dinic g(n+2, 0, n+1);

        for(int j = 0; j < m; j++){
            if(pairs[j].first%2 == 0) swap(pairs[j].first, pairs[j].second);
            g.addEdge(pairs[j].first, pairs[j].second, INF);
        }

        for(int j = 1; j <= n; j+=2){
            ii aux = {i,0};
            auto find = upper_bound(factor[j-1].begin(), factor[j-1].end(), aux);
            int cap = 0;
            if(find != factor[j-1].end() && find->first == i){
                cap = find->second;
            }
            g.addEdge(0, j, cap);
        }

        for(int j = 2; j <= n; j+=2){
            ii aux = {i,0};
            auto find = upper_bound(factor[j-1].begin(), factor[j-1].end(), aux);
            int cap = 0;
            if (find != factor[j-1].end() && find->first == i){
                cap = find->second;
            }
            g.addEdge(j, n+1, cap);
        }

        answ += g.run();
    }

    cout << answ << '\n';

    return 0;
}