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
vector<int> lvl, dp; // dp[u] = min lvl that "u" can reach using backedge
vector<bool> cutpoint;

void dfs(int u, int p = -1){
    int children = 0;
    for(auto v : g[u]){
        if(lvl[v] == 0){ // Edge to child
            lvl[v] = lvl[u] + 1;
            dfs(v, u);
            if(dp[v] < lvl[u]){
                dp[u] = min(dp[u], dp[v]);
            }
            else if(p != -1){ // this subtree has no backedge to some "u" ancestor
                cutpoint[u] = true;
            }
            children++;
        }
        else if(lvl[v] < lvl[u]){ // Edge upwards
            dp[u] = min(dp[u], lvl[v]);
        }
    }
    if(p == -1 && children > 1) cutpoint[u] = true;
}

void find_cutpoints(int n, int src){
    lvl.assign(n, 0);
    dp.assign(n, INF);
    cutpoint.assign(n, false);
    lvl[src] = 1;
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