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
vector<int> leafs;
void dfs(int u, int p = -1){
    if(g[u].size() == 1) leafs.push_back(u);
    for(auto v : g[u]){
        if(v == p) continue;
        dfs(v, u);
    }
}

signed main() {
    optimize;

    int n; cin >> n;
    int head; cin >> head;
    g.assign(n, vector<int>());
    for(int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(head);

    int m = leafs.size();
    cout << (m + 1) / 2 << '\n';
    vector<bool> matched(m, false);
    for(int i = 0; i < m; i++){
        if(!matched[i]){
            cout << leafs[i] << " " << leafs[(i + m/2) % m] << '\n';
            matched[i] = true;
            matched[(i + m/2) % m] = true;
        }
    }
    return 0;
}