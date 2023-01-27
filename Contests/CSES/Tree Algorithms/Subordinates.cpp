#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

vector<vector<int>> g;
vector<int> subordinates;

int dfs(int u){

    int answ = 0;
    for(auto v : g[u]){
        answ += dfs(v);
    }
    subordinates[u] = answ;
    return answ + 1;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;
    g.assign(n, vector<int>());
    subordinates.assign(n, 0);

    for(int i = 1; i < n; i++){
        int parent;
        cin >> parent;
        g[parent - 1].push_back(i);
    }
    
    dfs(0);

    for(auto i : subordinates){
        cout << i << " ";
    }
    cout << '\n';
    return 0;
}