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

vector<vector<pii>> g;
vector<bool> visited;
vector<int> coord;

bool dfs(int u, int p = -1){
    visited[u] = true;
    bool answ = true;
    for(auto [v, w] : g[u]){
        if(!visited[v]){
            coord[v] = coord[u] + w;
            answ &= dfs(v, u);
        }
        if(coord[v] != coord[u] + w) return false;
    }
    return answ;
}

signed main() {
    // optimize;
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        g.assign(n, vector<pii>());
        for(int i = 0; i < m; i++){
            int a, b, w;
            cin >> a >> b >> w;
            if(w < 0){
                swap(a, b);
                w = -w;
            }
            // w eh positivo b esta na frente de a por w
            a--, b--;
            g[a].push_back({b, w});
            g[b].push_back({a, -w});
        }
        visited.assign(n, false);
        coord.assign(n, -1);
        bool answ = true;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                coord[i] = 0;
                answ &= dfs(i);
            }
        }
        cout << (answ ? "YES": "NO") << '\n';
    }
    return 0;
}