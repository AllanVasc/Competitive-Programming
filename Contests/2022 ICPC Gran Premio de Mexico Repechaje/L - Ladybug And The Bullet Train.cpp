#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e6 + 100;
vector<vector<int>> g;
int sz[MAXN];
bool is_here[MAXN];
int targetDad = -1;

void dfs1(int u, int p, int target){
    sz[u] = 1;
    is_here[u] = (u == target);
    for(auto v : g[u]){
        if(v == p) continue;
        if(v == target) targetDad = u;
        dfs1(v, u, target);
        sz[u] += sz[v];
        is_here[u] = is_here[u] || is_here[v];
    }
}
int answ = 0;
void dfs2(int u, int p, int target){
    if(targetDad == u){
        answ++;
        return;
    }
    for(auto v : g[u]){
        if(v == p) continue;
        if(is_here[v]){
            answ++;
            dfs2(v, u, target);
        }
        else{
            answ += 2 * sz[v];
        }
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, x;
    cin >> n >> x;
    x--;

    g.assign(n, vector<int>());
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(0, 0, x);
    dfs2(0, 0, x);
    // cout << "path:" << '\n';
    // for(int i = 0; i < n; i++){
    //     cout << i + 1 << " " << path[i] << "\n";
    // }
    // cout << '\n';
    cout << answ << '\n';
    return 0;
}