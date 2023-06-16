#include <bits/stdc++.h>
using namespace std;

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

vector<vector<int>> g, gt;
vector<bool> visited;
stack<int> st;
int answ = 0;
void dfs(int u){
    visited[u] = true;
    for(auto v : g[u]){
        if(visited[v]) continue;
        dfs(v);
    }
    st.push(u);
}

void dfs2(int u){
    visited[u] = true;
    for(auto v : gt[u]){
        if(visited[v]) continue;
        dfs2(v);
    }
    answ++;
}

int kosaraju(){
    int n = g.size();
    visited.assign(n, false);
    for(int i = 0; i < n; i++){
        if(!visited[i]) dfs(i);
    }
    visited.assign(n, false);
    dfs2(st.top());
    return answ;
}
int32_t main() {
    optimize;
    int n;
    cin >> n;
    vector<int> a_to_idx(n + 1), b_to_idx(n + 1);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        a_to_idx[x] = i;
    }
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        b_to_idx[x] = i;
    }
    g.assign(n, vector<int>());
    gt.assign(n, vector<int>());
    for(int i = 2; i <= n; i++){
        int u = a_to_idx[i];
        int v = a_to_idx[i - 1];
        g[u].push_back(v);
        gt[v].push_back(u);
        u = b_to_idx[i];
        v = b_to_idx[i - 1];
        g[u].push_back(v);
        gt[v].push_back(u);
    }
    
    cout << kosaraju() << '\n';
    return 0;
}