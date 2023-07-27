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
vector<int> leaf;
void dfs(int u, int p = -1){
    bool has_child = false;
    for(auto v : g[u]){
        if(v == p) continue;
        has_child = true;
        dfs(v, u);
        leaf[u] += leaf[v];
    }
    if(!has_child) leaf[u]++;
}

signed main() {
    optimize;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        g.assign(n, vector<int>());
        leaf.assign(n, 0);
        for(int i = 0; i < n - 1; i++){
            int u, v;
            cin >> u >> v;
            u--, v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(0);
        int q;
        cin >> q;
        while(q--){
            int u, v;
            cin >> u >> v;
            u--, v--;
            int answ = leaf[u] * leaf[v];
            cout << answ << '\n';
        }
    }
    return 0;
}