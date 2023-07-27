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
vector<bool> visited, cutpoint;
vector<int> discovered, low;
int timer;

void dfs(int v, int p = -1){
    visited[v] = true;
    discovered[v] = low[v] = timer;
    timer++;
    int children = 0;
    for(auto to : g[v]){
        if(to == p) continue;
        if(visited[to]) low[v] = min(low[v], discovered[to]);
        else{
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if(p != -1 && low[to] >= discovered[v]){ // Caution: Can be called multiple times for "v"
                cutpoint[v] = true;
            }
            children++;
        }
    }
    if(p == -1 && children > 1) cutpoint[v] = true;
}

void find_cutpoints(int n){
    timer = 0;
    visited.assign(n, false);
    cutpoint.assign(n, false);
    discovered.assign(n, -1);
    low.assign(n, -1);
    for(int i = 0; i < n; i++){
        if(!visited[i]) dfs(i);
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    int cs = 1;
    while(cin >> n){
        if(n == 0) break;
        if(cs != 1) cout << '\n';
        map<string, int> mp;
        vector<string> names;
        g.assign(n, vector<int>());
        for(int i = 0; i < n; i++){
            string s; cin >> s;
            names.push_back(s);
            mp[s] = mp.size();
        }
        int m; cin >> m;
        for(int i = 0; i < m; i++){
            string s1, s2; cin >> s1 >> s2;
            int u = mp[s1];
            int v = mp[s2];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        find_cutpoints(n);
        vector<string> answ;
        for(int i = 0; i < cutpoint.size(); i++){
            if(cutpoint[i]) answ.push_back(names[i]);
        }
        sort(ALL(answ));
        cout << "City map #" << cs << ": " << answ.size() << " camera(s) found" << '\n';
        for(auto x : answ) cout << x << '\n';
        cs++;
    }
    return 0;
}