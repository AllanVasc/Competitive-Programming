//  J - Programming Tutors
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

    void mincut(){

        set<int> a;
        set<int> b;

        vector<bool> visited(N,false);
        queue<int> q;
        q.push(source);

        while(!q.empty()){

            int v = q.front();
            visited[v] = true;
            q.pop();
            a.insert(v);

            for(auto itr: g[v]){
                Edge aux = edge[itr];
                if(aux.cap > 0 && visited[aux.v] == false){
                    q.push(aux.v);
                }
            }
        }

        for(int i = 1; i < visited.size(); i++){
            if(visited[i] == false) b.insert(i);
        }

        bool flag = true;
        for(auto u: a){
            for(auto j: g[u]){
                Edge aux = edge[j];
                if(b.find(aux.v) != b.end()){
                    if(flag) cout << u << " " << aux.v << '\n';
                    flag = flag^true;
                }
            }
        }
    }

    void maxmatching(int n){

        for(int i = 1; i <= n; i++){
            for(int j = 0; j < g[i].size(); j++){
                Edge aux = edge[g[i][j]];
                if(aux.v > n && aux.cap == 0){
                    cout << i << " " << aux.v - n << '\n';
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

int distance(ii a, ii b){
    return abs((a.first - b.first)) + abs((a.second - b.second));
}

vector<ii> students;
vector<ii> tutors;
bool check(int limit, int n){

    Dinic g(2*n+2,0, 2*n+1);

    for(int i = 1; i <= n; i++) g.addEdge(0, i, 1);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(distance(students[i], tutors[j]) <= limit){
                g.addEdge(i+1,n+j+1,1);
            }
        }
    }

    for(int i = 1; i <= n; i++) g.addEdge(n+i,2*n+1,1);

    return g.run() == n;
}

int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        ii aux;
        cin >> aux.first >> aux.second;
        students.push_back(aux);
    }
    for(int i = 0; i < n; i++){
        ii aux;
        cin >> aux.first >> aux.second;
        tutors.push_back(aux);
    }

    int l = 0;
    int r = 4*1e8 + 100;
    int answ = 4*1e8 + 100;
    while(l <= r){

        int mid = l + (r-l)/2;

        if(check(mid,n)){
            answ = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    
    cout << answ << '\n';

    return 0;
}
