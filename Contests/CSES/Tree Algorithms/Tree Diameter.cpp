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
int answ;

int dfs(int u, int parent){
    int max1 = 0;
    int max2 = 0;
    for(auto v : g[u]){
        if(v != parent){
            int depth = dfs(v, u);
            if(depth > max1){
                max2 = max1;
                max1 = depth;
            }
            else if(depth > max2){
                max2 = depth;
            }

            answ = max(answ, max1 + max2);
        }
    }
    return 1 + max(max1, max2);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;
    g.assign(n + 1, vector<int>());

    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }

    dfs(0,0);
    cout << answ << '\n';

    return 0;
}