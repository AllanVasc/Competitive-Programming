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
    }

    vector<vector<int>> g2;
    vector<int> color, isBip;
    bool bipartite(int u, int p = -1){
        bool answ = true;
        for(auto v : g2[u]){
            if(color[v] == -1){
                color[v] = 1 - color[u];
                answ &= bipartite(v, u);
            }
            else{
                if(color[v] == color[u]) return false;
            }
        }
        return answ;
    }

    vector<vector<int>> solve(){
        color.assign(n, -1);
        isBip.assign(blocks.size(), false);
        g2.assign(n, vector<int>());
        for(int i = 0; i < blocks.size(); i++){
            int root = -1;
            for(auto [u, v] : edgBlocks[i]){
                g2[u].push_back(v);
                g2[v].push_back(u);
                root = u;
            }
            if(root != -1){
                color[root] = 1;
                isBip[i] = bipartite(root);
            }
            for(auto u : blocks[i]){
                g2[u].clear();
                color[u] = -1;
            }
        }

        for(int i = 0; i < blocks.size(); i++){
            if(!isBip[i]) continue;
            for(auto [u, v] : edgBlocks[i]){
                g2[u].push_back(v);
                g2[v].push_back(u);
            }
        }
        return g2;
    }
};

vector<int> color;
int white, black;
void dfs(int u, vector<vector<int>> & g, int p = -1){
    white += color[u] == 0;
    black += color[u] == 1;
    for(auto v : g[u]){
        if(color[v] == -1){
            color[v] = 1 - color[u];
            dfs(v, g, u);
        }
    }
}
int cnt;
void countPairs(int u, vector<vector<int>> & g, int p = -1){
    color[u] = true;
    cnt++;
    for(auto v : g[u]){
        if(color[v] == -1){
            countPairs(v, g, u);
        }
    }
}

signed main() {
    optimize;

    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>());
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    BlockCutTree bct(g);
    vector<vector<int>> g2 = bct.solve();
    color.assign(n, -1);
    int insecure = 0;
    int secure = 0;
    for(int i = 0; i < n; i++){
        if(color[i] == -1){
            black = 0;
            white = 0;
            color[i] = 0;
            dfs(i, g2);
            secure += black * white;
            insecure += (black * (black - 1)) / 2;
            insecure += (white * (white - 1)) / 2;
        }
    }

    cout << insecure << " " << secure << '\n';
    return 0;
}