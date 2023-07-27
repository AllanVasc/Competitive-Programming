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

vector<vector<pair<int,int>>> g;
int bfs(int src){
    int n = g.size();
    int answ = 0;
    queue<tuple<int,int,int>> q;
    vector<bool> visited(n, false);
    visited[src] = true;
    q.push({src, 1, -1});
    while(!q.empty()){
        auto [u, d, t] = q.front();
        q.pop();
        answ = max(answ, d);
        for(auto [v, time] : g[u]){
            if(!visited[v]){
                if(time >= t){
                    // cost nothing
                    q.push({v, d, time});
                }
                else{
                    q.push({v, d + 1, time});
                }
                visited[v] = true;
            }
        }
    }
    return answ;
}

signed main() {
    optimize;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        g.assign(n, vector<pii>());
        for(int i = 0; i < n - 1; i++){
            int u, v;
            cin >> u >> v;
            u--, v--;
            g[u].push_back({v, i});
            g[v].push_back({u, i});
        }
        cout << bfs(0) << '\n';
    }
    return 0;
}