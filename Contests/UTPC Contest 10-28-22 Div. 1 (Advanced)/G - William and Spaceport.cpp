#include <bits/stdc++.h>
using namespace std;

#define int long long
#define optimize ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ALL(x) x.begin(), x.end()
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define iii tuple<int,int,int>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
const int ms = 1e5 + 100;
vector<vi> g;
int sz[ms], contrib[ms];

void dfs(int u, int p){
    sz[u] = 1;
    for(auto v : g[u]){
        if(v == p) continue;
        dfs(v, u);
        sz[u] += sz[v];
        contrib[u] += sz[v] * (n - sz[v]);
    }
    contrib[u] += (n - sz[u]) * sz[u];
    contrib[u] += n - 1;
}

int32_t main() {
    optimize;
    
    int k;
    cin >> n >> k;
    g.assign(n, vi());
    vi cost(n);
    for(int i = 0; i < n; i++){
        cin >> cost[i];
    }
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, 0);
    priority_queue<pii> pq;
    int answ = 0;
    for(int i = 0; i < n; i++){
        answ += contrib[i] * cost[i];
        pq.push({contrib[i], cost[i]});
    }

    while(!pq.empty() && k > 0){
        auto [qtt, c] = pq.top();
        pq.pop();
        int takeOut = min(k, c);
        answ -= takeOut * qtt;
        k -= takeOut;
        if(c - takeOut > 0) pq.push({qtt, c - takeOut});
    }
    cout << answ << '\n';
    return 0;
}