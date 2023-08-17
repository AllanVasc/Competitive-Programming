#include <bits/stdc++.h>
#define ii pair<int,int>

using namespace std;

int aux;
vector<int> tome;
void dfs(int u, int p, int mx, vector<int> &vis, vector<vector<ii>> &g){
    vis[u] = 2;
    for(auto [v, id] : g[u]){
        if(vis[v] == 1 || v == p || id >= mx) continue;

        if(vis[v] == 2){
            tome.push_back(id);
            aux = v;
        }
        else{
            dfs(v, u, mx, vis, g);
            if(aux >= 0){
                aux = (u == aux ? -2 : aux);
                tome.push_back(id);
            }
        }
        if(aux != -1) break;
    }
    vis[u] = 1;
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;
        vector<ii> edges(m);
        vector<vector<ii> > g(n);
        for(int i=0; i<m; i++){
            int a, b;
            cin >> a >> b;
            a--, b--;
            g[a].push_back(ii(b, i));
            g[b].push_back(ii(a, i));
        }

        int l=3, r = m;
        int sz = m+ 2;
        vector<int> ans;
        while(l <= r){
            aux = -1;
            tome.clear();
            int mid = (l+r)/2;
            vector<int> vis(n, 0);

            for(int i=0; i<n && tome.empty(); i++){
                if(vis[i] == 0){
                    dfs(i, -1, mid, vis, g);
                }
            }

            if(!tome.empty()){
                r = mid -1;
                if(mid < sz){
                    ans.swap(tome);
                    sz = mid;
                }
            }
            else l = mid+1;
        }

        if(sz > m){
            cout << "-1\n";
        }
        else{
            sort(ans.begin(), ans.end());
            for(int i=0; i<ans.size(); i++) cout << ans[i]+1 << (i+1 == ans.size() ? '\n' : ' ');
        }
    

    }
}