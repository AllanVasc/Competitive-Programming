#include <bits/stdc++.h>
using namespace std;

#define int long long
#define optimize ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define iii tuple<int,int,int>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

vector<vector<int>> cycles;
const int ms = 1e4;
int par[ms], sz[ms];
void build(){
    for(int i = 0; i < ms; i++){
        par[i] = i;
        sz[i] = 1;
    }
}
int find(int u) { return u == par[u] ? u : par[u] = find(par[u]); }
void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
}

void dfs(int u, vector<int> & v, vector<bool> & vis){
    int n = v.size() - 1;
    vis[u] = true;
    cycles.back().push_back(u);
    for(int i = 1; i <= n; i++){
        if(v[i] == u){
            if(vis[i]) break;
            dfs(i, v, vis);
        }
    }
}

signed main() {
    optimize;
    int n; cin >> n;
    vector<int> v(n + 1);
    for(int i = 0; i < n; i++) cin >> v[i + 1];
    int m; cin >> m;

    vector<bool> vis(n + 1, false);
    for(int i = 1; i <= n; i++){
        if(vis[i]) continue;
        cycles.push_back(vector<int>());
        dfs(i, v, vis);
    }
    int fp = 0;
    build();
    for(int i = 0; i < cycles.size(); i++){
        // cout << "cycle " << i << " = ";
        for(auto x : cycles[i]){
            // cout << x << " ";
            merge(cycles[i][0], x);
        }
        // cout << '\n';
        sort(cycles[i].begin(), cycles[i].end());
        fp += cycles[i].size() - 1;
    }
    // cout << "fp = " << fp << '\n';

    vector<pii> swaps;
    // preciso baguncar mais, da merge em ciclos
    for(int i = 2; i <= n && fp < m; i++){
        if(find(1) != find(i)){
            fp++;
            merge(1, i);
            swaps.push_back({1, i});
        }
    }

    // Preciso ajeitar (quebrar ciclos)
    for(int i = 1; i <= n && fp > m; i++){
        vector<int> pos(n + 1, -1);
        int curr = 0;
        for(int j = v[i]; j != i; j = v[j]) pos[j] = curr++;
        pos[i] = curr;
        curr = 0;
        for(int j = i + 1; j <= n && fp > m; j++){
            if(pos[j] >= curr){
                swaps.push_back({i, j });
                fp--;
                curr = pos[j] + 1;
                swap(v[i], v[j]);
            }
        }
    }

    cout << swaps.size() << '\n';
    for(auto [x, y] : swaps) cout << x << " " << y << " ";
    cout << '\n';
    return 0;
}