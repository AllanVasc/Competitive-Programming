#include <bits/stdc++.h>

using namespace std;

vector <vector <int>> g0, g;
vector <int> vis;
vector <bool> state;
vector <pair <int, int>> ans;

bool dfs(int x){
    vis[x] = 1;

    for(auto i:g[x]){
        if(vis[i]) continue;

        if(dfs(i)){
            state[x] = !state[x];
            state[i] = !state[i];
            ans.emplace_back(x, i);
        }
    }

    return state[x];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    g0.resize(n);
    g.resize(n);
    vis.assign(n, 0);
    state.resize(n);

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;

        a--, b--;

        g0[a].push_back(b);
        g0[b].push_back(a);
    }

    for(int i = 0; i < n; i++)
        state[i] = (g0[i].size() & 1);
    
    for(int i = 0; i < k; i++){
        int a, b;
        cin >> a >> b;

        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i = 0; i < n; i++){
        if(vis[i]) continue;

        if(dfs(i)){
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    cout << ans.size() << "\n";
    for(auto [from, to] : ans){
        cout << from+1 << " " << to+1 << "\n";
    }

    return 0;
}