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
vector<bool> visited, cutpoint;
vector<int> discovered, low;
int timer;

void dfs(int v, int p = -1){
    visited[v] = true;
    discovered[v] = low[v] = timer;
    timer++;
    int children = 0;
    for(auto to : g[v]){
        if(to == p) continue;
        if(visited[to]) low[v] = min(low[v], discovered[to]);
        else{
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if(p != -1 && low[to] >= discovered[v]){ // Caution: Can be called multiple times for "v"
                cutpoint[v] = true;
            }
            children++;
        }
    }
    if(p == -1 && children > 1) cutpoint[v] = true;
}

void find_cutpoints(int n, int src){
    timer = 0;
    visited.assign(n, false);
    cutpoint.assign(n, false);
    discovered.assign(n, -1);
    low.assign(n, -1);
    dfs(src);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for(int i = 0; i < n; i++){
        cin >> grid[i];
    }
    g.assign(n*m, vector<int>());
    int area = 0;
    int src = -1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '.') continue;
            area++;
            src = i * m + j;
            if(j + 1 < m && grid[i][j + 1] == '#'){
                g[i * m + j].push_back(i * m + j + 1);
                g[i * m + j + 1].push_back(i * m + j);
            }
            if(i + 1 < n && grid[i + 1][j] == '#'){
                g[i * m + j].push_back((i + 1) * m + j);
                g[(i + 1) * m + j].push_back(i * m + j);
            }
        }
    }

    if(area <= 2){
        cout << -1 << '\n';
    }
    else{
        find_cutpoints(n * m, src);
        bool found = false;
        for(int i = 0; i < cutpoint.size(); i++){
            found |= cutpoint[i];
        }

        cout << (found ? "1" : "2") << '\n';
    }
    return 0;
}