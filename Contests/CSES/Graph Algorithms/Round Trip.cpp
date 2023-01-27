#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

vector<vector<int>> g;
vector<int> visited;
vector<int> path;
bool printed = false;

vector<int> print_list;
void dfs_aux(int u, int parent){
    path.push_back(u);
    visited[u] = true;
    for(auto v : g[u]){
        if(v != parent){
            if(visited[v] == false){
                dfs_aux(v, u);
            }
            else{
                if(!printed){
                    
                    print_list.push_back(v);
                    for(int i = path.size() - 1; i >= 0; i--){
                        print_list.push_back(path[i]);
                        if(path[i] == v) break;
                    }

                    printed = true;
                }
            }
        }
    }
    path.pop_back();
}

void dfs(){
    int n = g.size();
    for(int i = 0; i < n; i++){
        if(visited[i] == false){
            dfs_aux(i, i);
        }
    }
}


int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    g.assign(n, vector<int>());
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    visited.assign(n, 0);
    dfs();

    if(printed){
        cout << print_list.size() << '\n';
        for(int i = 0; i < print_list.size(); i++){
            cout << print_list[i] + 1 << " ";
        }
        cout << '\n';
    }
    else{
        cout << "IMPOSSIBLE" << '\n';
    }
    return 0;
}