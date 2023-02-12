#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 998244353;

vector<vector<int>> g;
vector<int> sizes;

int precalc(int v, int p){
    sizes[v] = 1;
    for(auto u : g[v]){
        if(u == p) continue;
        precalc(u, v);
        sizes[v] += sizes[u];
    }
    return sizes[v];
}
int answ = -1;
void solve(int v, int p){
    bool is_centroid = true;
    for(auto u : g[v]){
        if(u == p) continue;
        if(sizes[u] > g.size() / 2){
            is_centroid = false;
            solve(u, v);
        }
    }
    if(is_centroid) answ = v;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    g.assign(n, vector<int>());
    sizes.assign(n, 0);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    precalc(0,0);
    solve(0,0);

    cout << answ + 1 << '\n';
    return 0;
}