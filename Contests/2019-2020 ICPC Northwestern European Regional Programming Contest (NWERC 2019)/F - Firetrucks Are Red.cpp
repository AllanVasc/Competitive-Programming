#include <bits/stdc++.h>

using namespace std;

#define ii pair<int,int>
#define iii tuple<int,int,int>
const int ms = 2e5 + 10;
vector<ii> g[ms];
vector<iii> ans;
bool vis[ms];

void dfs(int u=0){
    vis[u] = true;
    for(auto [x, val] : g[u]){
        if(vis[x]) continue;
        ans.push_back({u+1, x+1, val});
        dfs(x);
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    map<int,int> mp;

    for(int i=0;i<n; i++){
        int qtd; cin >> qtd;
        for(int j=0; j<qtd; j++){
            int a; cin >> a;
            if(mp.count(a)){
                int idx = mp[a];
                g[idx].push_back({i, a});
                g[i].push_back({idx, a});
            }
            mp[a] = i;
        }
    }
    dfs();
    if(ans.size() != n-1){
        cout << "impossible\n";
    }
    else{
        for(auto [x, y, z] : ans){
            cout << x << " " << y << " " << z << '\n';
        }
    }

}