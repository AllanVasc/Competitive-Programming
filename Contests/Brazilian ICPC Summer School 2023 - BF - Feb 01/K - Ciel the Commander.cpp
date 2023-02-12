#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 998244353;

const int MAXN = 1e5;

vector<int> g[MAXN];
int parent[MAXN], sz[MAXN], removed[MAXN], height[MAXN];

// Preprocessing subtree sizes
void dfsSubtree(int u, int p){
    sz[u] = 1;
    for(auto v : g[u]){
        if(v != p && !removed[v]){
            dfsSubtree(v, u);
            sz[u] += sz[v];
        }
    }
}

// For each subtree we find its centroid
int getCentroid(int u, int p, int curr_size){
    for(auto v : g[u]){
        if(v != p && !removed[v] && sz[v] * 2 >= curr_size){
            return getCentroid(v, u, curr_size);
        }
    }
    return u;
}

// Algorithm to perform Centroid Decomposition
void decompose(int u, int p = -1, int lvl = 0){
    dfsSubtree(u, -1);
    int ctr = getCentroid(u, -1, sz[u]);
    parent[ctr] = p;
    height[ctr] = lvl;  // Assigning a level to the centroid
    removed[ctr] = 1;
    for(auto v : g[ctr]){
        if(v != p && !removed[v]){
            decompose(v, ctr, lvl + 1);
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    decompose(0);
    for(int i = 0; i < n; i++){
        cout << (char) ('A' + height[i]) << " ";
    }
    cout << '\n';
    return 0;
}