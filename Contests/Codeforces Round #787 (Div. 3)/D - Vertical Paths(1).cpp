// D - Vertical Paths
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

int main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int t;
    cin >> t;
 
    while(t--){

        int n;
        cin >> n;

        // Graph inplementation using Adjacency List (0-Based)
        vector<int> adj[n];
        vector<bool> leaf(n, true);

        for(int i = 0; i < n; i++){
            int parent;
            cin >> parent;

            if(parent -1 != i){
                adj[i].push_back(parent-1);
            }

            leaf[parent - 1] = false;
        }

        if(n == 1){
            cout << "1" << '\n';
            cout << "1" << '\n';
            cout << "1" << '\n';
            cout << '\n';
            continue;
        }

        vector<bool> visited(n,false);
        vector<vector<int>> paths;

        for(int i = 0; i < n; i++){

            if(leaf[i] == true){

                vector<int> auxPath;
                int node = i;
                
                while(visited[node] == false){
                    
                    auxPath.push_back(node);
                    visited[node] = true;

                    if(adj[node].size() != 0){
                        node = adj[node][0];
                    }
                }

                paths.push_back(auxPath);
            }
        }

        // Answer
        cout << paths.size() << '\n';

        for(int i = 0; i < paths.size(); i++){

            cout << paths[i].size() << '\n';

            for(int j = paths[i].size()-1; j >= 0 ; j--){
                cout << paths[i][j]+1 << " ";
            }
            cout << '\n';
        }
        cout << '\n';

    }
 
    return 0;
}
