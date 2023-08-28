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

const int ms = 2e5 + 10;
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
    int n, m, q;
    cin >> n >> m >> q;
    vector<pii> roads;
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        u--, v--;
        roads.push_back({u, v});
    }
    vector<pii> queries;
    vector<int> answ(q, m);
    for(int i = 0; i < q; i++){
        int u, v; cin >> u >> v;
        u--, v--;
        queries.push_back({u, v});
        if(u == v) answ[i] = -1;
    }
    vector<int> L(q, 0), R(q, m - 1);
    bool f = true;
    while(f){
        f = false;
        build();
        vector<vector<int>> check(m);
        for(int i = 0; i < q; i++){
            if(L[i] > R[i]) continue;
            f = true;
            int mid = (L[i] + R[i]) >> 1;
            check[mid].push_back(i);
        }
        for(int i = 0; i < m; i++){
            auto [u, v] = roads[i];
            merge(u, v);
            for(auto x : check[i]){
                auto [a, b] = queries[x];
                if(find(a) == find(b)){
                    answ[x] = min(answ[x], i);
                    R[x] = i - 1;
                }
                else{
                    L[x] = i + 1;
                }
            }
        }
    }
    for(auto x : answ) cout << (x == m ? -1 : x + 1) << '\n';
    return 0;
}