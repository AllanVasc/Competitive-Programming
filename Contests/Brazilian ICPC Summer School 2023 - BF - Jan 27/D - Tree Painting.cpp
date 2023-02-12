#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> g;
    g.assign(n, vector<int>());
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int leaves = 0;
    for(int i = 0; i < n; i++){
        if(g[i].size() == 1) leaves++;
    }

    cout << (leaves + 1) / 2 << '\n';
    return 0;
}