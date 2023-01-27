#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int MAXN = 100000 + 100;
int parent[MAXN];
int sizes[MAXN];

void build(){
    for(int i = 0; i < MAXN; i++){
        parent[i] = i;
        sizes[i] = 1;
    }
}

int Find(int x){
    if(x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

int qtd_components;
void Union(int x, int y){
    x = Find(x);
    y = Find(y);
    if(x != y){
        qtd_components--;
        if(sizes[x] < sizes[y]) swap(x, y);
        parent[y] = x;
        sizes[x] += sizes[y]; 
    }
}

int32_t main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<ii> edges;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges.push_back({u, v});
    }

    int q;
    cin >> q;
    vector<int> queries;
    vector<bool> removed(m, false);
    for(int i = 0; i < q; i++){
        int aux;
        cin >> aux;
        aux--;
        queries.push_back(aux);
        removed[aux] = true;
    }

    build();
    qtd_components = n;
    for(int i = 0; i < m; i++){
        if(removed[i] == false){
            auto [u, v] = edges[i];
            Union(u, v);
        }
    }

    vector<int> answ(q);
    for(int i = q - 1; i >= 0; i--){
        answ[i] = qtd_components;
        auto [u, v] = edges[ queries[i] ];
        Union(u, v);
        // cout << "parent = ";
        // for(int i = 0; i < n; i++){
        //     cout << parent[i] << " ";
        // }
        // cout << '\n';
    }

    for(int i = 0; i < q; i++){
        cout << answ[i] << " ";
    }
    cout << '\n';
    
    return 0;
}