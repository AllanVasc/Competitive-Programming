#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int ms = 2e5 + 100;
vector<int> neigh[ms];
int val[ms];
int visited[ms];

bool expand(int root, int n){
    set<ii> reacheable;
    reacheable.insert({val[root], root});
    int sz = 0;
    while(reacheable.size()){
        auto [cost, u] = (*reacheable.begin());
        visited[u] = root;
        if(cost > sz) {
            return (sz == n); 
        }
        reacheable.erase(reacheable.begin());
        sz++;
        for(auto v : neigh[u]){
            if(visited[v] < root){
                reacheable.insert({val[v], v});
            }
        }
    }
    return (sz == n);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            cin >> val[i];
            visited[i] = -1;
            neigh[i].clear();
        }
        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            u--, v--;
            neigh[u].push_back(v);
            neigh[v].push_back(u);
        }
        bool has_answ = false;
        for(int i = 0; i < n; i++){
            if(val[i] == 0 && visited[i] == -1){
                if(expand(i, n)){
                    has_answ = true;
                }
            }
        }
        
        if(!has_answ) cout << "NO" << '\n';
        else cout << "YES" << '\n';
    }
    return 0;
}