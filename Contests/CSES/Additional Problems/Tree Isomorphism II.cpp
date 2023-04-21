#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int ms = 1e5 + 100;
int h[ms], sz[ms];

int fexp(int x, int y){
    int answ = 1;
    x = x % MOD;
    while(y){
        if(y & 1) answ = answ * x % MOD;
        x = x * x % MOD;
        y >>= 1;
    }
    return answ;
}

void dfs(int u, int p, vector<vector<int>>& g){
    sz[u] = 1;
    for(auto v : g[u]){
        if(v == p) continue;
        dfs(v, u, g);
        sz[u] += sz[v];
    }
}

ii getCentroids(int u, int p, vector<vector<int>>& g){
    int n = g.size();
    for(auto v : g[u]){
        if(v == p) continue;
        if(2 * sz[v] > n) return getCentroids(v, u, g);
    }

    for(auto v : g[u]){
        if(v == p) continue;
        if(2 * sz[v] == n) return {u, v};
    }
    return {u, u};
}

void getHash(int u, int p, vector<vector<int>>& g){
    sz[u] = 1;
    vector<ii> children;
    for(auto v : g[u]){
        if(v == p) continue;
        getHash(v, u, g);
        sz[u] += sz[v];
        children.push_back({h[v], sz[v]});
    }
    sort(children.begin(), children.end());

    h[u] = 1;
    for(auto [val, size] : children){
        int pw2 = fexp(2, 2 * size);
        h[u] = h[u] * pw2 % MOD;
        h[u] = (h[u] + val) % MOD;
    }
    h[u] = 2 * h[u] % MOD;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> g1(n), g2(n);
        for(int i = 0; i < n - 1; i++){
            int u, v;
            cin >> u >> v;
            u--, v--;
            g1[u].push_back(v);
            g1[v].push_back(u);
        }
        for(int i = 0; i < n - 1; i++){
            int u, v;
            cin >> u >> v;
            u--, v--;
            g2[u].push_back(v);
            g2[v].push_back(u);
        }
        dfs(0, 0, g1);
        ii centroids1 = getCentroids(0, 0, g1);
        dfs(0, 0, g2);
        ii centroids2 = getCentroids(0, 0, g2);

        getHash(centroids1.first, -1, g1);
        int hsg11 = h[centroids1.first];
        getHash(centroids1.second, -1, g1);
        int hsg12 = h[centroids1.second];

        getHash(centroids2.first, -1, g2);
        int hsg21 = h[centroids2.first];
        getHash(centroids2.second, -1, g2);
        int hsg22 = h[centroids2.second];


        if(hsg11 == hsg21 ||
           hsg11 == hsg22 ||
           hsg12 == hsg21 ||
           hsg12 == hsg22) cout << "YES" << "\n";
        else cout << "NO" << '\n';
    }
    
    return 0;
}