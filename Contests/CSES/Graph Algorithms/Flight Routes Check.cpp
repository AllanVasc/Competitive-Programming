#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

struct SCC {
    int n;
    vector<vector<int>> g, gt, condensation_g;
    vector<bool> visited;
    stack<int> order;
    vector<int> parent, root_nodes;

public:
    SCC(vector<vector<int>> &graph){
        n = graph.size();
        this->g = graph;

        gt.assign(n, vector<int>());
        for(int i = 0; i < n; i++){
            for(auto v : g[i]){
                gt[v].push_back(i);
            }
        }
        build();
    }

private:
    void build(){
        visited.assign(n, false);
        for(int i = 0; i < n; i++){
            if(!visited[i]) toposort(i);
        }

        parent.assign(n, -1);
        
        while(!order.empty()){
            int u = order.top();
            order.pop();
            if(parent[u] == -1){
                findComponent(u, u);
                root_nodes.push_back(u);
            }
        }

        // Building the Condensation Graph
        condensation_g.assign(n, vector<int>());
        for(int u = 0; u < n; u++){
            for(auto v : g[u]){
                int root_u = parent[u];
                int root_v = parent[v];
                if(root_u != root_v)
                    condensation_g[root_u].push_back(root_v);
            }
        }
    }

    void toposort(int u){
        visited[u] = true;
        for(auto v : g[u]){
            if(!visited[v]) toposort(v);
        }
        order.push(u);
    }

    void findComponent(int u, int root){
        parent[u] = root;
        for(auto v : gt[u]){
            if(parent[v] == -1) findComponent(v, root);
        }
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[a-1].push_back(b - 1);
    }

    SCC scc(g);
    vector<int> components = scc.root_nodes;

    if(components.size() == 1){
        cout << "YES" << '\n';
    }
    else{
        cout << "NO" << '\n';
        cout << components[1] + 1 << " " << components[0] + 1 << '\n';
    }
    return 0;
}