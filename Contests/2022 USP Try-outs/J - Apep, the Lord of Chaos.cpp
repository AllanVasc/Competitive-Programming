#include<bits/stdc++.h>

using namespace std;
#define int long long 
#define ii pair<int,int>
const int ms = 2e5 + 100;

int ds[ms][2], sz[ms][2], h[ms][2];


void init(){
    for(int i=0; i<ms; i++){
        ds[i][0] = ds[i][1] = i;
        sz[i][0] = sz[i][1] = 1;
        h[i][1] = ms + 10;
    }
}

int dsfind(int i, int x){
    // cout << "GRISI" << endl;
    return (i == ds[i][x] ? i : ds[i][x] = dsfind(ds[i][x], x));
}

void merge(int a, int b, int x){
    a = dsfind(a, x);
    b = dsfind(b, x);
    if(a == b) return;
    if(h[a][x] > h[b][x]) swap(a, b);
    ds[b][x] = a;
}

vector<ii> g[ms];
bool vis[ms];
int tin[ms], low[ms], t;

void bridgeTree(int u, int p =-1){
    vis[u] = true;
    tin[u] = low[u] = t++;
    h[u][0] = u;
    for(auto [to, w] : g[u]){
        if(to == p) continue;
        if(vis[to]){
            merge(u, to, 0);
            low[u] = min(low[u], tin[to]);
        }
        else{
            bridgeTree(to, u);
            low[u] = min(low[u], low[to]);
            if(low[to] > tin[u]){
                // ponte
            }
            else merge(u, to, 0);
        }
    }
}

void build(int n){
    t =0;
    memset(tin, -1, sizeof tin);
    memset(low, -1, sizeof low);
    bridgeTree(0, -1);
    
}

vector<ii> tree[ms];
ii pai[ms];
multiset<int> st;

void getHeight(int u, int height =0, int p=0, int peso =0){
    h[u][1] = height;
    pai[u] = ii(p, peso);
    for(auto [v, w]  :tree[u]){
        if(v == p) continue;
        getHeight(v, height+1, u, w);
    }
}

void qry(int a, int b, int q){
    a = dsfind(a, 1), b = dsfind(b, 1);


    while(a != b){

        if(h[b][1] > h[a][1]){
            ii aux = pai[b];
            st.erase(st.lower_bound(aux.second));
            merge(b, aux.first, 1);
            b = dsfind(aux.first, 1);
        }
        else{
            ii aux = pai[a];
            st.erase(st.lower_bound(aux.second));
            merge(a, aux.first, 1);
            a = dsfind(aux.first, 1);
        }
    }
}


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        a--, b--;
        g[a].push_back(ii(b, w));
        g[b].push_back(ii(a, w));
    }
    init();
    build(n);


    for(int i=0; i<n; i++){
        for(auto [v, w] : g[i]){
            int x = dsfind(i, 0);
            int y = dsfind(v, 0);
            if(x != y){
                tree[x].push_back(ii(y, w));
                if(x < y){
                    //cout << x << "  " << y << endl;
                    st.insert(w);
                }
            }
            
        }
    }
    getHeight(0);

    for(int i=0; i<n; i++){
        for(auto [v, w] : g[i]){
            int x = dsfind(i, 0);
            int y = dsfind(v, 0);

            if(x == y){
                merge(i, v, 1);
            }
            
        }
    }


    int q;
    cin >> q;

    while(q--){
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        qry(u, v, q);
        //cout << "ALLAN" << endl;
        if(st.empty()){
            cout << "-1\n";
        }
        else cout << *(st.begin()) << '\n';
    }
    





    return 0;
}
