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

const int ms = 1e5 + 10;
int par[ms], sz[ms];
void build(){
    for(int i = 0; i < ms; i++){
        par[i] = i;
        sz[i] = 1;
    }
}
int find(int a){ return a == par[a] ? a : par[a] = find(par[a]); }
void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
}

signed main() {
    optimize;
    int n, m;
    cin >> n >> m;
    vector<pii> roads;
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        u--, v--;
        roads.push_back({u, v});
    }
    int q; cin >> q;
    vector<pii> query;
    vector<int> need(q);
    for(int i = 0; i < q; i++){
        int u, v, qtt; cin >> u >> v >> qtt;
        u--, v--;
        query.push_back({u, v});
        need[i] = qtt;
    }
    vector<int> L(q, 0), R(q, m - 1);
    vector<int> answ(q, m - 1);
    bool flag = true;
    while(flag){
        flag = false;
        build();
        vector<vector<int>> check(m);
        for(int i = 0; i < q; i++){
            if(L[i] > R[i]) continue;
            flag = true;
            int mid = (L[i] + R[i]) >> 1;
            check[mid].push_back(i);
        }
        for(int i = 0; i < m; i++){
            auto [u, v] = roads[i];
            merge(u, v);
            for(auto x : check[i]){
                auto [a, b] = query[x];
                int parA = find(a);
                int parB = find(b);
                int tot = 0;
                if(parA == parB) tot += sz[parA];
                else tot += sz[parA] + sz[parB];
                
                if(tot >= need[x]){
                    answ[x] = min(answ[x], i);
                    R[x] = i - 1;
                }
                else{
                    L[x] = i + 1;
                }
            }
        }
    }
    for(auto x : answ) cout << x + 1 << '\n';
    return 0;
}