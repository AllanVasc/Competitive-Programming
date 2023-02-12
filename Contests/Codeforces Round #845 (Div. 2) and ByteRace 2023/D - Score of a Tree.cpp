#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

vector<vector<int>> g;
const int MAXN = 2 * 1e5 + 10;
int dist[MAXN];

void dfs(int u, int p = -1){
    dist[u] = 1;
    for(auto v : g[u]){
        if(v == p) continue;
        dfs(v, u);
        dist[u] = max(dist[u], 1 + dist[v]);
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;

    int pw[MAXN];
    pw[0] = 1;
    for(int i = 1; i < MAXN; i++) pw[i] = pw[i - 1] * 2 % MOD;

    while(t--){
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

        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += dist[i];
            sum %= MOD;
        }

        cout << pw[n - 1] * sum % MOD << '\n';
    }

    return 0;
}