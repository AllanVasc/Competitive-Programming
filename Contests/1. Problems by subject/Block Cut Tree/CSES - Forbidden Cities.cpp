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

struct BlockCutTree{
    vector<vector<int>> g, blocks, tree;
    vector<vector<pii>> edgBlocks;
    stack<int> stV; // Store the vertices in DFS order
    stack<pii> stE; // Store the edges in DFS order
    vector<int> disc, low, art, pos;
    int n, timer;

    BlockCutTree(vector<vector<int>> g) : g(g){
        n = g.size();
        disc.assign(n, -1);
        low.assign(n, -1);
        art.assign(n, 0);
        pos.assign(n, -1);
        build();
    }

    void dfs(int u, int p = -1){
        disc[u] = low[u] = timer++;
        stV.push(u);

        if(p != -1) stE.push({u, p});
        for(int v : g[u]){ // Backedges
            if(v != p && disc[v] != -1) stE.push({u, v});
        }
        bool hasFwd = false;
        for(int v : g[u]){
            if(v == p) continue;
            if(disc[v] == -1){ // Unvisited
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if(low[v] >= disc[u]){ // "u" is Articulation
                    art[u]++;
                    blocks.emplace_back(1, u);
                    while(blocks.back().back() != v){
                        blocks.back().push_back(stV.top());
                        stV.pop();
                    }

                    edgBlocks.emplace_back(1, stE.top());
                    stE.pop();
                    while(edgBlocks.back().back() != pair(v, u)){
                        edgBlocks.back().push_back(stE.top());
                        stE.pop();
                    }
                }
                hasFwd = true;
            }
            else low[u] = min(low[u], disc[v]);
        }
        if(p == -1){
            if(art[u]) art[u]--;
            if(!hasFwd){    // BCC = {u}
                blocks.emplace_back(1, u);
                edgBlocks.emplace_back();
            }
        }
    }

    void build(){
        int timer = 0;
        for(int i = 0; i < n; i++){
            if(disc[i] == -1) dfs(i);
        }

        tree.assign(blocks.size(), vector<int>());
        for(int i = 0; i < n; i++){
            if(art[i]){
                pos[i] = tree.size();
                tree.emplace_back();
            }
        }

        for(int i = 0; i < blocks.size(); i++){
            for(int j : blocks[i]){
                if(!art[j]) pos[j] = i;
                else{   // Edge BCC - Articulation
                    tree[i].push_back(pos[j]);
                    tree[pos[j]].push_back(i);
                }
            }
        }
        // cout << "Debug" << '\n';
        // for(int i = 0; i < blocks.size(); i++){
        //     cout << "block " << i << ": ";
        //     for(auto j : blocks[i]){
        //         cout << j + 1 << " ";
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';
        // for(int i = 0; i < blocks.size(); i++){
        //     cout << "edges of " << i << ": ";
        //     for(auto [u,v] : edgBlocks[i]){
        //         cout << "(" << u + 1 << "," << v + 1 << ") ";
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';
        // cout << "art[i] = :";
        // for(auto x : art) cout << x << " ";
        // cout << '\n';
        // cout << '\n';
        // cout << "pos[i] = :";
        // for(auto x : pos) cout << x << " ";
        // cout << '\n';
        // cout << "tree:" << '\n';
        // for(int i = 0; i < tree.size(); i++){
        //     cout << i << ": ";
        //     for(int j = 0; j < tree[i].size(); j++){
        //         cout << tree[i][j] << " ";
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';
        build_binary();
    }

    const int ms = 1e6;
    const int LOG = 20;
    vector<vector<int>> up;
    vector<int> depth;
    void dfs2(int u, int p = -1){
        for(auto v : tree[u]){
            if(v == p) continue;
            depth[v] = depth[u] + 1;
            up[v][0] = u;
            for(int i = 1; i < LOG; i++){
                up[v][i] = up[up[v][i - 1]][i - 1];
            }
            dfs2(v, u);
        }
    }

    void build_binary(){
        up.assign(ms, vector<int>(LOG, 0));
        depth.assign(ms, 0);
        for(int i = 0; i < tree.size(); i++){
            if(!depth[i]){
                dfs2(i);
            }
        }
    }

    int lca(int a, int b) {
        if(depth[a] < depth[b]) swap(a, b);
        int k = depth[a] - depth[b];
        for(int j = LOG - 1; j >= 0; j--) {
            if(k & (1 << j)) {
                a = up[a][j];
            }
        }
        if(a == b) return a;
        for(int j = LOG - 1; j >= 0; j--) {
            if(up[a][j] != up[b][j]) {
                a = up[a][j];
                b = up[b][j];
            }
        }
        return up[a][0];
    }
    int lift(int u, int k){
        for(int i = LOG - 1; i >= 0; i --){
            if(k & (1 << i)) u = up[u][i];
        }
        return u;
    }

    bool query(int a, int b, int c){
        if(a == c || b == c) return false;
        if(!art[c]) return true; // It isn't a articulation point
        a = pos[a];
        b = pos[b];
        c = pos[c];
        // cout << "In tree:" << '\n';
        // cout << "a = " << a << '\n'; 
        // cout << "b = " << b << '\n'; 
        // cout << "c = " << c << '\n'; 
        int lcaTree = lca(a, b);
        // cout << "lca = " << lcaTree << '\n';
        // cout << "depth a = " << depth[a] << '\n';
        // cout << "depth b = " << depth[b] << '\n';
        // cout << "depth c = " << depth[c] << '\n';
        // cout << "depth lca = " << depth[lcaTree] << '\n';
        if(depth[c] < depth[lcaTree]) return true;
        if(depth[c] > max(depth[a], depth[b])) return true;
        // Need to check if lifting I reach "c"
        // cout << "check" << '\n';
        if(depth[c] < depth[a]){
            int k = depth[a] - depth[c];
            if(lift(a, k) == c) return false;
        }
        if(depth[c] < depth[b]){
            int k = depth[b] - depth[c];
            if(lift(b, k) == c) return false;
        }
        return true;
    }
};

signed main() {
    optimize;

    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> g(n, vector<int>());
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    BlockCutTree bct(g);
    while(q--){
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--, c--;
        cout << (bct.query(a, b, c) ? "YES" : "NO") << '\n';
    }
    return 0;
}