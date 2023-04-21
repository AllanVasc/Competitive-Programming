#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int ms = 2*1e5 + 100;
int hs[ms];
map<vector<int>, int> hasher;

int hashfy(vector<int> x){
    sort(x.begin(), x.end());
    if(!hasher[x]){
        hasher[x] = hasher.size();
    }
    return hasher[x];
}

int hashTree(int u, int p, vector<vector<int>>& g){
    vector<int> children;
    for(auto v : g[u]){
        if(v == p) continue;
        children.push_back(hashTree(v, u, g));
    }
    return hs[u] = hashfy(children);
}

bool symmetric(int u, int p, vector<vector<int>>& g){
    map<int,int> freq;
    for(auto v : g[u]){
        if(v == p) continue;
        freq[hs[v]]++;
    }
    vector<int> odds;
    for(auto x : freq){
        if(x.second % 2){
            odds.push_back(x.first);
        }
    }
    if(odds.size() == 0) return true;
    else if(odds.size() > 1) return false;
    for(int v : g[u]){
        if(v == p) continue;
        if(hs[v] == odds[0]) return symmetric(v, u, g);
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> g(n);
        for(int i = 0; i < n - 1; i++){
            int u, v;
            cin >> u >> v;
            u--, v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        hasher.clear();
        hashTree(0, 0, g);
        if(symmetric(0,0,g)) cout << "YES" << "\n";
        else cout << "NO" << '\n';
    }
    return 0;
}