#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

map<vector<int>, int> hasher;

int hashify(vector<int> x){
    sort(x.begin(), x.end());
    if(!hasher[x]){
        hasher[x] = hasher.size();
    }
    return hasher[x];
}

int hashTree(int u, int p, vector<vector<int>>& g){
    vector<int> children;
    for(int v : g[u]){
        if(v == p) continue;
        children.push_back(hashTree(v, u, g));
    }
    return hashify(children);
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
        int h1 = hashTree(0, 0, g1);
        int h2 = hashTree(0, 0, g2);

        if(h1 == h2) cout << "YES" << "\n";
        else cout << "NO" << '\n';
    }
    
    return 0;
}