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
vector<int> depth;
void dfs(int u, int parent, int dep){
    depth[u] = dep;
    for(auto v : g[u]){
        if(v == parent) continue;
        dfs(v, u, dep + 1);
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n, q;
    cin >> n >> q;

    g.assign(n, vector<int>());
    vector<int> parent(n, 0);
    for(int i = 1; i < n; i++){
        int u;
        cin >> u;
        parent[i] = u - 1;
        g[i].push_back(u - 1);
        g[u - 1].push_back(i);
    } 
    
    int LOG = 30;
    vector<vector<int>> up;
    up.assign(n + 1, vector<int>(LOG, 0));
    depth.assign(n + 1, 0);
    // up[N][LOG]
    for(int j = 0; j < LOG; j++){
        for(int v = 0; v < n; v++){
            if(j == 0) up[v][j] = parent[v];
            else up[v][j] = up[ up[v][j - 1] ][j - 1];
        }
    }
    dfs(0, 0, 0);
    // for(int i = 0; i < n; i++){
    //     cout << "depth " << i << " = " << depth[i] << '\n';
    // }

    for(int i = 0; i < q; i++){
        int x, k;
        cin >> x >> k;
        int answ = x - 1;
        int value = 0;
        if(depth[answ] < k){
            answ = -2;
        }
        else{
            while(k){
                if(k & 1){
                    answ = up[answ][value];
                }
                value++;
                k >>= 1;
            }
        }
        cout << answ + 1 << '\n';
    }

    return 0;
}