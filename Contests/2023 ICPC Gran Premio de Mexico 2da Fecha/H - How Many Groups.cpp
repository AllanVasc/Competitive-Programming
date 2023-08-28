#include <bits/stdc++.h>

using namespace std;

#define int long long
const int ms = 1e6 + 10;

vector<int> g[ms];
int tome[ms], group[ms], ans[ms];
bool vis[ms];

void dfs(int u, int cnt){
    vis[u] = true;
    bool aux = (tome[group[u]] == false);
    tome[group[u]] = true;
    if(aux) cnt++;
    ans[u] = cnt;
    for(auto v : g[u]){
        if(vis[v]) continue;
        dfs(v, cnt);
    }
    if(aux) {
        cnt--;
        tome[group[u]] = false;
    }
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    int root = -1;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        x--;
        if(x != -1) g[x].push_back(i);
        else root = i;
    } 

    for(int i=0; i<n; i++) cin >> group[i];
    dfs(root, 0);
    for(int i=0; i<n; i++) cout << ans[i] << ' ';
    cout << '\n';


}