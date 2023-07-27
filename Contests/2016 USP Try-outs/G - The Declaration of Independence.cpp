#include <bits/stdc++.h>

using namespace std;

#define ii pair<int,int>
#define iii tuple<int,int,int>
const int ms = 1e5+ 5;

vector<iii> g[ms];
vector<int> qry[ms];
int ans[ms], vis[ms];
deque<int> dq;

void dfs(int u=0, bool rem = false){
    vis[u] = true;
    for(auto x : qry[u]) ans[x] = dq.front();
    int tome;
    if(rem){
        tome = dq.front();
        dq.pop_front();
    }


    for(auto [v, val, in] : g[u]){
        if(vis[v]) continue;
        if(in)dq.push_back(val);
  
        dfs(v, !in);
        if(in)dq.pop_back();
    }
    if(rem) dq.push_front(tome);
}




int main(){
    cin.tie();
    ios::sync_with_stdio(0);

    int q, cnt=0;
    cin >> q;

    for(int i=0; i<q; i++){
        char cmd;
        cin >> cmd;
        if(cmd == 'E'){
            int v, x;
            cin >> v >> x;
            g[v].push_back(iii(i+1, x, 1));
        }
        else{
            int v;
            cin >> v;
            g[v].push_back(iii(i+1, -1, 0));
            qry[i+1].push_back(cnt++);
        }
    }

    dfs(0);

    for(int i=0; i<cnt; i++) cout << ans[i] << '\n';
}