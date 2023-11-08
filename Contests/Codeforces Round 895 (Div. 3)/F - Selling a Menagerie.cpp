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

signed main() {
    optimize;
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<vector<int>> g(n);
        vector<int> inDegree(n, 0);
        for(int i = 0; i < n; i++){
            int ai; cin >> ai;
            ai--;
            g[i].push_back(ai);
            inDegree[ai]++;
        }
        vector<int> cost(n);
        for(int i = 0 ; i < n; i++) cin >> cost[i];
        
        vector<int> vis(n, false);
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(!inDegree[i]) q.push(i);
        }

        vector<int> answ;
        while(!q.empty()){
            auto u = q.front();
            q.pop();
            vis[u] = true;
            answ.push_back(u);
            for(auto v : g[u]){
                if(--inDegree[v] == 0) q.push(v);
            }
        }

        for(int i = 0; i < n; i++){
            if(vis[i]) continue;
            vector<int> cyc;
            int mx = -1;
            int start = -1;
            int curr = 0;
            for(int j = i; vis[j] == false; j = g[j][0]){
                cyc.push_back(j);
                vis[j] = true;
                curr += 2 * cost[j];
            }
            // cout << "curr = " << curr << '\n';
            int sz = cyc.size();
            for(int j = 0; j < sz; j++){
                int val = curr - cost[cyc[(j - 1 + sz) % sz]];
                if(val > mx){
                    mx = val;
                    start = j;
                }
            }
            for(int j = start; j < sz; j++) answ.push_back(cyc[j]);
            for(int j = 0; j < start; j++) answ.push_back(cyc[j]);
        }
        for(auto x : answ) cout << x + 1 << " ";
        cout << '\n';
    }
    return 0;
}