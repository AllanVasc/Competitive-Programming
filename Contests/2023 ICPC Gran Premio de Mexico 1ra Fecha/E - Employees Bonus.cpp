#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long

const int ms = 1e5 + 100;
int sz[ms], seg[4 * ms];
vector<int> answ;
vector<vector<tuple<int,int,int>>> pay;
vector<vector<int>> g;
vector<int> needAchive;
const int INF = 1e8;

void precalc(int u, int p = -1){
    sz[u] = 1;
    for(auto v : g[u]){
        if(v == p) continue;
        precalc(v, u);
        sz[u] += sz[v];
    }
}

void update(int p, int l, int r, int idx, int val){
    if(l == r){
        seg[p] = val;
    }
    else{
        int m = (l + r) >> 1;
        int lc = 2*p;
        int rc = lc + 1;
        if(idx <= m) update(lc, l, m, idx, val);
        else update(rc, m + 1, r, idx, val);
        seg[p] = seg[lc] + seg[rc];
    }
}

int query(int p, int l, int r, int sum){
    if(l == r){
        return l;
    }
    int m = (l + r) >> 1;
    int lc = 2*p;
    int rc = lc + 1;
    if(seg[lc] >= sum) return query(lc, l, m, sum);
    else return query(rc, m + 1, r, sum - seg[lc]);
}

void solve(int u, int p){
    for(auto [win, resto, idx] : pay[u]){
        update(1, 0, ms - 1, idx, win + resto);
    }
    if(seg[1] < needAchive[u]){
        answ[u] = min(answ[u], INF);
    }
    else{
        answ[u] = min(answ[u], query(1, 0, ms - 1, needAchive[u]) + 1);
    }
    for(auto [win, resto, idx] : pay[u]){
        update(1, 0, ms - 1, idx, win);
    }
    for(auto v : g[u]){
        if(v == p) continue;
        solve(v, u);
    }
    for(auto [win, resto, idx] : pay[u]){
        update(1, 0, ms - 1, idx, 0);
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, q;
    cin >> n >> q;
    needAchive.assign(n, 0);
    g.assign(n, vector<int>());
    pay.assign(n, vector<tuple<int,int,int>>());
    answ.assign(n, INF);
    for(int i = 0; i < n; i++){
        cin >> needAchive[i];
    }
    vector<int> degree(n, 0);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        degree[v]++;
        g[u].push_back(v);
    }
    vector<int> roots;
    for(int i = 0; i < n; i++){
        if(degree[i] == 0){
            roots.push_back(i);
        }
    }
    
    for(int i = 0; i < roots.size(); i++){
        // cout << "root = " << roots[i] << '\n';
        precalc(roots[i], roots[i]);
    }

    for(int i = 0; i < q; i++){
        int u, lucro;
        cin >> u >> lucro;
        u--;
        pay[u].push_back({lucro/sz[u], lucro % sz[u], i});
    }

    for(int i = 0; i < roots.size(); i++){
        solve(roots[i], roots[i]);
    }
    for(int i = 0; i < n; i++){
        cout << (answ[i] == INF ? -1 : answ[i]) << '\n';
    }
    return 0;
}