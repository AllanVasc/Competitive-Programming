#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ii pair<int,int>

const int ms = 1e5 + 5;

int sz[ms], pai[ms];
vector<int> g[ms];
vector<ii> pos;
int n, k;


int dfs(int u=0, int p=-1, int h=0){
    pai[u] = p;
    sz[u] = 1;
    for(auto v : g[u]){
        if(v == p) continue;
        sz[u] +=dfs(v ,u, h+1);
    }
    if(sz[u] >= k) pos.push_back(ii(-h, u)); 
    return sz[u];
}

void printa(int u, int p){
    if(k){
        cout << u+1 << " ";
        k--;
    }
    for(auto v : g[u]){
        if(v == p) continue;
        printa(v, u);
    }
}


signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> k;

    for(int i=1; i<n; i++){
        int a;
        cin >> a;
        a--;
        g[a].push_back(i);
        g[i].push_back(a);
    }

    dfs();

    sort(pos.begin(), pos.end());

    if(pos.empty()){
        cout << -1 << '\n';
    }
    else{
        printa(pos[0].second, pai[pos[0].second]);
        cout << '\n';
    }


    return 0;
}