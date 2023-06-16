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

bool bfs(int src, vector<pii> & answ){
    int n = g.size();
    int last = -1;
    vector<int> pred(n, -1);
    for(int i = 0; i < g[src].size(); i++){
        int adjSrc = g[src][i];
        queue<int> q;
        vector<bool> visited(n, false);
        q.push(adjSrc);
        visited[src] = true;
        visited[adjSrc] = true;
        pred[adjSrc] = adjSrc;
        while(!q.empty() && last == -1){
            auto u = q.front();
            q.pop();
            // cout << "u = " << u + 1 << '\n';
            for(auto v : g[u]){
                if(u != adjSrc && v == src){ // Found cycle
                    last = u;
                    break;
                }
                if(v == src) continue;
                if(!visited[v]){
                    // cout << "v = " << v + 1 << '\n';
                    q.push(v);
                    visited[v] = true;
                    pred[v] = u;
                }
            }
        }
        if(last != -1){
            unordered_map<int, bool> used;
            used[src] = true;
            used[adjSrc] = true;
            used[last] = true;
            answ.push_back({src, adjSrc});
            answ.push_back({last, src});
            while(last != pred[last]){
                answ.push_back({last, pred[last]});
                used[pred[last]] = true;
                last = pred[last];
            }
            int cnt = 0;
            for(int j = 0; j < g[src].size() && cnt != 2; j++){
                if(used[g[src][j]] == false){
                    answ.push_back({src, g[src][j]});
                    cnt++;
                }
            }
            return true;
        }
    }
    return false;
}

int32_t main() {
    //optimize;
    
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        g.assign(n, vector<int>());
        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            u--, v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<pii> answ;
        for(int i = 0; i < n; i++){
            if(g[i].size() >= 4){
                if(bfs(i, answ)){
                    break;
                }
            }
        }
        if(answ.size() != 0){
            cout << "YES" << '\n';
            cout << answ.size() << '\n';
            for(auto [u,v] : answ){
                cout << u + 1 << " " << v + 1 << '\n';
            }
        }
        else{
            cout << "NO" << '\n';
        }
    }
    return 0;
}