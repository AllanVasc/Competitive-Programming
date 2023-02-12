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
int dist[MAXN][30]; // Distance from the nodes to the centroid (represented by the level)
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

// For each node, we calculate its distance
// to the centroid (represented by the level)
void setDist(int u, int p, int lvl){
    for(auto v : g[u]){
        if(v == p || removed[v]) continue;
        dist[v][lvl] = dist[u][lvl] + 1;
        setDist(v, u, lvl);
    }
}

// Algorithm to perform Centroid Decomposition
void decompose(int u, int p = -1, int lvl = 0){
    dfsSubtree(u, -1);
    int ctr = getCentroid(u, -1, sz[u]);
    parent[ctr] = p;
    height[ctr] = lvl;  // Assigning a level to the centroid
    removed[ctr] = 1;
    setDist(ctr, p, lvl);
    for(auto v : g[ctr]){
        if(v != p && !removed[v]){
            decompose(v, ctr, lvl + 1);
        }
    }
}

multiset<int> answ[MAXN];
int color[MAXN];

int distance(int u, int v){
    int x = u;
    int y = v;
    if(height[x] < height[y]) swap(x, y);
    while(height[x] > height[y]) x = parent[x];
    while(x != y){
        x = parent[x];
        y = parent[y];
    }
    return dist[u][height[x]] + dist[v][height[x]];
}

void updateToWhite(int x, int u){
    answ[x].insert(distance(x, u));
    if(parent[x] != -1) updateToWhite(parent[x], u);
}

void updateToBlack(int x, int u, int remove){
    // cout << "valores em x = " << x + 1 << '\n';
    // for(auto i : answ[x]){
    //     cout << i << '\n';
    // }
    // cout << "vou remover: " << remove << '\n';
    auto itr = answ[x].find(remove);
    answ[x].erase(itr);
    if(parent[x] != -1) updateToBlack(parent[x], u, distance(parent[x], u));
}

int query(int x, int u){
    if(x == -1) return INF;
    auto itr = answ[x].begin();

    return min(query(parent[x], u), distance(x, u) + *itr);
}

int32_t main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 0; i < MAXN; i++) answ[i].insert(INF);
    decompose(0);
    int q;
    cin >> q;
    while(q--){
        int cmd, u;
        cin >> cmd >> u;
        u--;
        // cout << "cmd = " << cmd << " u = " << u + 1 << '\n';
        if(cmd == 0){
            if(color[u] == 0){
                updateToWhite(u, u);
            }
            else{
                updateToBlack(u,u, 0);
            }
            color[u] = !color[u];
        }
        else{
            int ans = query(u, u);
            cout << (ans == INF ? -1 : ans) << '\n';
        }
    }
    return 0;
}