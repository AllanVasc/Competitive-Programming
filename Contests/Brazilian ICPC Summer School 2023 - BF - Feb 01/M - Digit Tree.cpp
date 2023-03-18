#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

vector<vector<ii>> g;
int answ = 0;
int m;
int PHI;

const int MAXN = 1e5 + 100;
int sz[MAXN], removed[MAXN], height[MAXN];
int cur_subtree[MAXN], down[MAXN], up[MAXN];
int parts;

int fexp(int x, int y){
    int ans = 1;
    x = x % m;      // Update 'x' if it is more than or equal to 'm'
    while(y){ // We walk through the bits of power "y"
        if(y & 1) ans = (ans*x) % m; // If the least significant bit is set, we multiply the answer by "x"
        y = y >> 1; // We walk to the next bit
        x = (x*x) % m;
    }
    return ans;
}

// Euler's totient function for one number
int phi(int n){
    int answ = n;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            while(n % i == 0) n /= i;
            answ -= answ / i;
        }
    }
    if(n > 1) answ -= answ / n;
    return answ;
}

int inv(int x){
    return fexp(x, PHI - 1);
}

void dfsSubTree(int u, int p){
    sz[u] = 1;
    for(auto [v, w] : g[u]){
        if(v != p && !removed[v]){
            dfsSubTree(v, u);
            sz[u] += sz[v];
        }
    }
}

int getCentroid(int u, int p, int curr_size){
    for(auto [v, w] : g[u]){
        if(v != p && !removed[v] && sz[v] * 2 >= curr_size){
            return getCentroid(v, u, curr_size);
        }
    }
    return u;
}

void dfsClean(int u, int p){
    up[u] = 0;
    down[u] = 0;
    height[u] = 0;
    for(auto [v, w] : g[u]){
        if(v == p || removed[v]) continue;
        dfsClean(v, u);
    }
}

void build(int u, int p, int ctr){
    if(p == ctr){
        cur_subtree[u] = parts;
        parts++;
    }
    else if(p != -1) cur_subtree[u] = cur_subtree[p];
    for(auto [v, w] : g[u]){
        if(v == p || removed[v]) continue;
        down[v] = ((down[u] * 10 % m) + w) % m;
        up[v] = (w * fexp(10, height[u]) % m + up[u]) % m;
        height[v] = height[u] + 1;
        build(v, u, ctr);
    }
}

void dfs3(int u, int p, map<int,int>& freq_up, vector<map<int,int>>& freqBySubtree){
    for(auto [v, w] : g[u]){
        if(v == p || removed[v]) continue;
        freq_up[up[v]]++;
        freqBySubtree[cur_subtree[v]][up[v]]++;
        dfs3(v, u, freq_up, freqBySubtree);
    }
}

void dfs4(int u, int p, map<int,int>& freq_up, vector<map<int,int>>& freqBySubtree){
    if(p == -1){
        answ += freq_up[0] - 1;
    }
    for(auto [v, w] : g[u]){
        if(v == p || removed[v]) continue;
        int val = ((-down[v]) % m + m) % m;
        val = val * inv(fexp(10, height[v])) % m;
        answ += (freq_up[val] - freqBySubtree[cur_subtree[v]][val]);

        dfs4(v, u, freq_up, freqBySubtree);
    }
}

void solve(int ctr){
    dfsClean(ctr, -1); // Clean arrays
    parts = 0;
    build(ctr, -1, ctr);
    parts--;
    cur_subtree[ctr] = -1;
    map<int,int> freq_up;
    vector<map<int,int>> freqBySubtree(parts + 1);
    freq_up[0]++;
    dfs3(ctr, -1, freq_up, freqBySubtree);  // Put every value in maps
    dfs4(ctr, -1, freq_up, freqBySubtree);  // Find paths
}


void decompose(int u, int p = -1, int lvl = 0){
    dfsSubTree(u, -1);
    int ctr = getCentroid(u, -1, sz[u]);

    solve(ctr);
    removed[ctr] = 1;
    for(auto [v, w] : g[ctr]){
        if(v != p && !removed[v]){
            decompose(v, ctr, lvl + 1);
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n >> m;
    PHI = phi(m);
    g.assign(n, vector<ii>());
    for(int i = 0; i < n - 1; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    decompose(0);
    cout << answ << '\n';
    return 0;
}