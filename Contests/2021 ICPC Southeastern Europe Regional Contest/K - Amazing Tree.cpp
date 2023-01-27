// 
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = 1e18;
const int INF = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;

vector<vector<int>> adj;
vector<int> lowest_leaf;
vector<int> visited;
vector<int> answ;

void addEdge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs_preprocess(int v, int p){
    for(auto u : adj[v]){
        if(u == p) continue;
        dfs_preprocess(u,v);
    }

    lowest_leaf[p] = INF;
    sort(adj[v].begin(), adj[v].end(), [](int a, int b){
        return lowest_leaf[a] < lowest_leaf[b];
    });

    adj[v].pop_back(); // Remove father edge
    if(adj[v].empty()){ // If is leaf
        lowest_leaf[v] = v;
    }
    else    // isn't leaf
        lowest_leaf[v] = lowest_leaf[ adj[v].front() ];
}

void dfs(int v, bool foundRoot){ 
    int size = adj[v].size();

    if(foundRoot || adj[v].empty()){  // Dfs normal || leaf
        for(auto u : adj[v]){
            dfs(u, true);
        }
        answ.push_back(v);
    }
    else{
        if(v > lowest_leaf[adj[v].back()]){ // V is root
            dfs(v, true);
        }
        else{
            for(int i = 0; i < size-1; i++){
                dfs(adj[v][i], true);
            }
            answ.push_back(v);
            dfs(adj[v].back(), false);
        }
    }
}

int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;
        
        adj.assign(n+5, vector<int>(0));
        lowest_leaf.assign(n + 5, INF);

        for(int i = 0; i < n-1; i++){
            int u,v;
            cin >> u >> v;
            addEdge(u-1, v-1);
        }

        int root = -1;
        for(int i = 0; i < n; i++){
            if(adj[i].size() == 1){
                root = i;
                break;
            }
        }

        // cout << "Root (min leaf) = " << root+1 << '\n';
        dfs_preprocess(adj[root][0], root);

        // for(int i = 0; i < n; i++){
        //     cout << "Lowest de " << i+1 << " eh: " << lowest_leaf[i]+1 << '\n';
        // }

        // cout << "ARVORE: " << '\n';
        // for(int i = 0; i < n; i++){
        //     cout << i+1 << " -> ";
        //     for(int j = 0; j < adj[i].size(); j++){
        //         cout << adj[i][j]+1 << " ";
        //     }
        //     cout << '\n';
        // }
        
        dfs(root, false);
        for(int i = 0; i < answ.size(); i++){
            cout << answ[i] + 1 << " ";
        }
        cout << '\n';
        adj.clear();
        answ.clear();
    }

    return 0;
}
