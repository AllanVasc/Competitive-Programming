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

// 2-SAT solver using Kosaraju's Algorithm
struct TwoSAT{
    int n;
    vector<vector<int>> g, gt;
    vector<int> component;
    vector<bool> vis, assignment;
    stack<int> order;

    TwoSAT(int n) : n(n){
        g.assign(2 * n + 2, vector<int>());
        gt.assign(2 * n + 2, vector<int>());
        component.assign(2 * n + 2, -1);
        vis.assign(2 * n + 2, false);
    }

    // (a or b) = (!a -> b) and (!b -> a)
    void addOr(int a, int b){ add(-a, b); add(-b, a); }
    // (a and b) = (a or a) and (b or b)
    void addAnd(int a, int b){ addOr(a, a); addOr(b, b); }
    // (a -> b) = (!a or b)
    void addImp(int a, int b){ addOr(-a, b); }
    // (a xor b) = (a or b) and (!a or !b)
    void addXor(int a, int b){ addOr(a, b); addOr(-a, -b); }
    // (a equal b) = (a <--> b) = (a -> b) and (b -> a)
    void addEqual(int a, int b){ addImp(a, b); addImp(b, a); }
    // (a != b) = (a xor b)
    void addDiff(int a, int b){ addXor(a, b); }

    bool solve(){
        // 0 and 1 are dead nodes
        for(int i = 2; i < 2 * n + 2; i++){
            if(!vis[i]) dfs(i);
        }
        reverse();
        int idx = 0;
        while(!order.empty()){
            int u = order.top();
            order.pop();
            if(component[u] == -1){
                findComponent(u, idx++);
            }
        }
        assignment.resize(n + 1);   // 1-based
        for(int i = 1; i <= n; i++){
            if(component[trad(i)] == component[trad(-i)]) 
                return false;
            assignment[i] = component[trad(i)] > component[trad(-i)];
        }
        return true;
    }

private:
    // + -> xi (even), - -> !xi (odd)
    int trad(int v){ return v > 0 ? 2 * v : 2 * abs(v) + 1; }
    void add(int a, int b){ g[trad(a)].push_back(trad(b)); }

    void reverse(){
        for(int i = 0; i < 2 * n + 2; i++)
            for(auto v : g[i])
                gt[v].push_back(i);
    }

    void dfs(int u){
        vis[u] = true;
        for(auto v : g[u]){
            if(!vis[v]) dfs(v);
        }
        order.push(u);
    }

    void findComponent(int u, int root){
        component[u] = root;
        for(auto v : gt[u]){
            if(component[v] == -1) findComponent(v, root);
        }
    }
};

vector<vector<int>> original;
vector<vector<set<int>>> collision;

int32_t main() {
    // optimize;
    
    int n, len, lamp;
    cin >> n >> len >> lamp;
    original.assign(n, vector<int>(n, 0));
    collision.assign(n, vector<set<int>>(n, set<int>()));
    TwoSAT sat(lamp);
    for(int i = 1; i <= lamp; i++){
        int r, c;
        cin >> r >> c;
        r--, c--;
        for(int j = c; j < min(c + len + 1, n); j++){ // Direita
            for(auto x : collision[r][j]){
                if(x < 0) continue;
                sat.addOr(i, x);
            }
            collision[r][j].insert(i);
        }
        for(int j = c - 1; j >= max(0LL, c - len); j--){ // esquerda
            for(auto x : collision[r][j]){
                if(x < 0) continue;
                sat.addOr(i, x);
            }
            collision[r][j].insert(i);
        }
        for(int j = r; j < min(r + len + 1, n); j++){ // baixo
            for(auto x : collision[j][c]){
                if(x > 0) continue;
                sat.addOr(-i, x);
            }
            collision[j][c].insert(-i);
        }
        for(int j = r - 1; j >= max(0LL, r - len); j--){ // cima
            for(auto x : collision[j][c]){
                if(x > 0) continue;
                sat.addOr(-i, x);
            }
            collision[j][c].insert(-i);
        }
    }
    // cout << "colission:" << endl;
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << "[" << i << "," << j << "] = ";
    //         for(auto x : collision[i][j]) cout << x << " ";
    //         cout << endl;
    //     }
    // }
    cout << sat.solve() << '\n';
    return 0;
}