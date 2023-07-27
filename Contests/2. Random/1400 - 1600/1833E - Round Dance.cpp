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

vector<set<int>> g;
vector<int> visited;
bool dfs(int u, int p = -1){
    visited[u] = true;
    bool flag = false;
    for(auto v : g[u]){
        if(v == p) continue;
        if(visited[v] == true){
            // fechei uma comp
            flag = true;
        }
        else{
            flag |= dfs(v, u);
        }
    }
    return flag;
}

signed main() {
    optimize;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        g.assign(n, set<int>());
        for(int i = 0; i < n; i++) cin >> v[i];
        for(int i = 0; i < n; i++){
            g[i].insert(v[i] - 1);
            g[v[i] - 1].insert(i);
        }
        visited.assign(n, false);
        int closed = 0;
        int open = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                if(dfs(i)){
                    closed++;
                    // cout << "comp de " << i + 1 << '\n';
                }
                else open++;
            }
        }

        cout << closed + min(open, 1LL) << " " << closed + open << '\n';
    }
    return 0;
}