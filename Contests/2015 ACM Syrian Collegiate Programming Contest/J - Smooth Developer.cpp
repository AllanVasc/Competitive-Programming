#include<bits/stdc++.h>
using namespace std;

#define int long long

const int ms = 1e6 + 100;
vector<vector<int>> g;
vector<bool> visited;
set<int> answ;

void dfs(int u){
    answ.insert(u);
    visited[u] = true;
    for(auto v : g[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        
        map<string, int> name_int;
        map<int, string> int_name;

        visited.assign(ms, false);
        g.assign(ms, vector<int>());
        answ.clear();

        int cnt = 0;
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            int qtd;
            cin >> qtd;
            if(name_int.find(s) == name_int.end()){
                name_int[s] = cnt;
                int_name[cnt] = s;
                cnt++;
            }
            for(int j = 0; j < qtd; j++){
                string s1;
                cin >> s1;
                g[name_int[s]].push_back(name_int[s1]);
            }
        }

        for(int i = 0; i < k; i++){
            string s;
            cin >> s;
            if(!visited[name_int[s]]){
                dfs(name_int[s]);
            }
        }

        for(int x : answ){
            cout << int_name[x] << '\n';
        }

    }
    return 0;
}