#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

vector<vector<ii>> g;

int bfs(int src){
    int n = g.size();
    queue<ii> q;
    vector<int> depth(n, INF);
    q.push({src, 0});
    depth[src] = 0;
    int answ = 0;
    int round = 0;
    while(!q.empty()){
        int cnt = q.size();
        priority_queue<ii, vector<ii>, greater<ii>> pq;
        for(int i = 0; i < cnt; i++){
            auto [u, cur_w] = q.front();
            q.pop();
            pq.push({cur_w, u});
            for(auto [v, w] : g[u]){
                if(depth[v] == INF){
                    q.push({v, w * (round + 1)});
                }
            }
        }
        while(!pq.empty()){
            auto [w, u] = pq.top();
            pq.pop();
            if(depth[u] == INF){
                depth[u] = round + 1;
                answ += w;
            }
        }
        round++;
    }
    return answ;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    g.assign(n, vector<ii>());
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    cout << bfs(0) << '\n';
    return 0;
}