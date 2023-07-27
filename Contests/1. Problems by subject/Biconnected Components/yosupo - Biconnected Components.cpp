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

        // cout << (stV.empty() ? "ta ok1\n" : "ops1\n");
        // while(!stV.empty()){
        //     cout << stV.top() + 1 << " ";
        //     stV.pop();
        // }
        // cout << '\n';
        // cout << (stE.empty() ? "ta ok2\n" : "ops2\n");
        cout << blocks.size() << '\n';
        for(auto v : blocks){
            cout << v.size() << " ";
            for(auto x : v){
                cout << x << " ";
            }
            cout << '\n';
        }
    }
};

signed main() {
    optimize;

    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>());
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        // u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    BlockCutTree bct(g);
    return 0;
}