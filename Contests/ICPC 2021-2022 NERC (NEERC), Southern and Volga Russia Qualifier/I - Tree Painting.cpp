#include<bits/stdc++.h>
using namespace std;

#define int long long
using ii = pair<int,int>;
const int INF = 1e18;

vector<vector<int>> g;
const int ms = 21e5 + 100;
int sz[ms];

void dfs(int u, int p){
    sz[u] = 1;
    for(auto v : g[u]){
        if(v == p) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

int answ[ms];

void paint(int u, int p, int flag, int start){
    answ[u] = flag;
    for(auto v : g[u]){
        if(v == p) continue;
        if(v == start) paint(v, u, 1, start);
        else paint(v, u, flag, start);
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;
    g.assign(n, vector<int>());
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0,0);
    int found = -1;
    for(int i = 0; i < n; i++){
        if(sz[i] == n/2){
            found = i;
            break;
        }
    }

    if(found == -1){
        cout << "NO" << '\n';
    }
    else{
        cout << "YES" << '\n';
        paint(0, 0, 0, found);
        for(int i = 0; i < n; i++){
            cout << answ[i] << " ";
        }
        cout << '\n';
    }


    return 0;
}