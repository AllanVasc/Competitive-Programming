#include <bits/stdc++.h>
using namespace std;

#define int long long
#define optimize ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define iii tuple<int,int,int>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

vector<vector<int>> g;
vector<int> timer;
int t = 0;
vector<iii> answ;
bool dfs(int u, int p = -1){
    timer[u] = t++;
    // cout << "to em " << u + 1 << " timer = " << timer[u] << '\n';
    vector<int> nodes;
    for(auto v : g[u]){
        if(v == p) continue;
        if(timer[v] == -1){
            if(dfs(v, u)){
                // precisa de ajuda
                nodes.push_back(v);
            }
        }
    }
    // n ao tem mais filhos a serem visitados
    for(auto v : g[u]){
        if(v == p) continue;
        if(timer[v] < timer[u]) nodes.push_back(v);
    }
    if(nodes.size() % 2){ // Dou match certinho
        answ.push_back({nodes.back(), u, p});
        nodes.pop_back();
        while(!nodes.empty()){
            int x = nodes.back();
            nodes.pop_back();
            int y = nodes.back();
            nodes.pop_back();
            answ.push_back({x, u, y});
        }
        return false;
    }
    else{
        // eh par, vai faltar a aresta (eu, pai)
        // cout << "to em " << u + 1 << " vai faltar pai" << '\n';
        // cout << "nodes = ";
        // for(auto x : nodes) cout << x + 1 << " ";
        // cout << '\n';
        while(!nodes.empty()){
            int x = nodes.back();
            nodes.pop_back();
            int y = nodes.back();
            nodes.pop_back();
            answ.push_back({x, u, y});
        }
        return true;
    }
}

signed main() {
    optimize;
    int n, m;
    cin >> n >> m;
    g.assign(n, vector<int>());
    timer.assign(n, -1);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0);
    // cout << "timer = ";
    // for(auto x: timer){
    //     cout << x << " ";
    // }
    // cout << '\n';
    cout << answ.size() << '\n';
    for(auto [x, u, y] : answ){
        cout << x + 1 << " " << u + 1 << " " << y + 1 << '\n';
    }
    return 0;
}