#include <bits/stdc++.h>

using namespace std;

const int ms = 1e3 + 5;

vector<int> g[ms];
bool vis[ms];
vector<int> ord;

void dfs(int u){
    vis[u] = true;
    for(auto v : g[u]){
        if(!vis[v]) dfs(v);
    }
    ord.push_back(u);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            char c; cin >> c;
            if(c == '1') g[i].push_back(j);
        }
    }

    dfs(0);
    if(ord.size() != n){
        cout << "impossible\n";
    }
    else{
        for(int i=0; i<n; i++) cout << ord[i] << (i+1 == n? '\n' : ' ');
    }

    
}