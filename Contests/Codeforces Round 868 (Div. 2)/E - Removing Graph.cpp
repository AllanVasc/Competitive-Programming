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

int l, r;
vector<vector<int>> g;
vector<bool> visited;
int cnt;
void dfs(int u){
    visited[u] = true;
    cnt++;
    for(auto v : g[u]){
        if(!visited[v]) dfs(v);
    }
}

const int ms = 2e5 + 10;
int cycle[ms], chain[ms];
int solveChain(int sz){
    if(sz == 0) return 0;
    int & answ = chain[sz];
    if(answ != -1) return answ;
    set<int> nim;
    for(int i = l; i <= min(r, sz); i++){
        for(int j = 0; j <= sz - i; j++){
            nim.insert(solveChain(j) ^ solveChain(sz - i - j));
        }
    }
    answ = 0;
    while(nim.count(answ) != 0) answ++;
    return answ;
}

int solveCycle(int sz){
    if(sz == 0) return 0;
    int & answ = cycle[sz];
    if(answ != -1) return answ;
    set<int> nim;
    for(int i = l; i <= min(r, sz); i++){
        nim.insert(solveChain(sz - i));
    }
    answ = 0;
    while(nim.count(answ) != 0) answ++;
    return answ;
}

int32_t main() {
    optimize;
    
    int n;
    cin >> n >> l >> r;
    g.assign(n, vector<int>());
    for(int i = 0; i < n; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> sizes;
    visited.assign(n, false);
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            cnt = 0;
            dfs(i);
            sizes.push_back(cnt);
        }
    }
    
    int answ = 0;
    // memset(cycle, -1, sizeof cycle);
    // memset(chain, -1, sizeof chain);
    // for(int i = 0; i < sizes.size(); i++){
    //     // cout << "sz = " << sizes[i] << '\n';
    //     answ ^= solveCycle(sizes[i]);
    // }
    for(int i = 0; i < sizes.size(); i++){
        if(sizes[i] <= r + l - 1) answ ^= sizes[i] / l;
    }
    if(answ == 0){
        cout << "Bob" << '\n';
    }
    else{
        cout << "Alice" << '\n';
    }
    return 0;
}