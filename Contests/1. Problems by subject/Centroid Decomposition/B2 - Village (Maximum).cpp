#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 998244353;

const int MAXN = 1e5 + 10;
vector<vector<int>> g;
int sz[MAXN];
int answ = 0;
vector<int> ord;
void dfs(int u, int p = -1){
    int n = g.size();
    sz[u] = 1;
    ord.push_back(u);
    for(auto v : g[u]){
        if(v == p) continue;
        dfs(v, u);
        sz[u] += sz[v];
        answ += 2 * min(sz[v], n - sz[v]);
    }
}

int32_t main() {
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
    dfs(0);
    cout << answ << '\n';
    vector<int> new_order(n);
    for(int i = 0; i < n; i++){
        int u = ord[i];
        int v = ord[ (i + n/2) % n];
        new_order[v] = u;
    }
    for(int i = 0; i < n; i++){
        cout << new_order[i] + 1 << " ";
    }
    cout << '\n';
    return 0;
}