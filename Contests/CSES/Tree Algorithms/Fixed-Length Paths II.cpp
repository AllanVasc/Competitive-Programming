#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 998244353;

const int MAXN = 2e5 + 20;

int bit[MAXN];
int freq[MAXN];

// Return the sum of [0,idx] in "v" 
int prefix_query(int idx){
    int result = 0;
    for(++idx; idx > 0; idx -= idx & -idx) result += bit[idx];
    return result;
}

// Computes the range sum between two indices (both inclusive) [l,r] in "v"
int range_query(int l, int r){
    if (l == 0) return prefix_query(r);
    else return prefix_query(r) - prefix_query(l - 1);
}

// Update bit adding "add" (idx represent the position in "v")
void update(int idx, int add) {
    for (++idx; idx < MAXN; idx += idx & -idx) bit[idx] += add;
}

vector<int> g[MAXN];
int sz[MAXN], removed[MAXN];
int answ, low, high;

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

void dfsFindMaxDepth(int u, int p, int depth, int &max_depth){
    if(depth > high) return;
    max_depth = max(max_depth, depth);
    for(auto v : g[u]){
        if(!removed[v] && v != p){
            dfsFindMaxDepth(v, u, depth + 1, max_depth);
        }
    }
}

void dfsCount(int u, int p, int depth, int max_depth, int flag){
    if(depth > high) return;

    if(flag){
        answ += range_query(max(0LL, low - depth), high - depth);
    }
    else{
        update(depth, freq[depth] + 1);
    }

    for(auto v : g[u]){
        if(!removed[v] && v != p){
            dfsCount(v, u, depth + 1, max_depth, flag);
        }
    }
}

void solve(int u, int p){
    int max_depth = 0;
    for(auto v : g[u]){
        if(!removed[v] && v != p){
            dfsFindMaxDepth(v, u, 1, max_depth);
        }
    }
    update(0, 1);
    for(auto v : g[u]){
        if(!removed[v] && v != p){
            dfsCount(v, u, 1, max_depth, true);
            dfsCount(v, u, 1, max_depth, false);
        }
    }
    for(int i = 0; i <= max_depth; i++){
        update(i, -range_query(i,i));
        // freq[i] = 0;
    }
}

// Algorithm to perform Centroid Decomposition
void decompose(int u, int p = -1, int lvl = 0){
    dfsSubtree(u, -1);
    int ctr = getCentroid(u, -1, sz[u]);
    
    solve(ctr, -1);
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
    cin >> n >> low >> high;
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    decompose(0);
    cout << answ << '\n';
    return 0;
}