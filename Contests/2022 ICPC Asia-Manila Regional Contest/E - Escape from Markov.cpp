#include <bits/stdc++.h>
#define int long long
#define ii pair<int,int>

using namespace std;

const int ms = 2e5 + 20;
const int inf = 1e18;

vector<int> g[ms], edges[ms];
vector<ii> ord;
int dis[ms], vis[ms];
int l, p, n, m;
int a, b;

int find(int u, int v, int now){ // quero ir de U para V
    int id = lower_bound(ord.begin(), ord.end(), ii(min(u, v), max(u, v))) - ord.begin();
    if(edges[id].size() == l) return l; 
    int start = lower_bound(edges[id].begin(), edges[id].end(), now) - edges[id].begin();
    int aux = now;
    int right = inf;
    for(int j=start; j<edges[id].size(); j++){
        if(edges[id][j] != aux){
            right = aux - now;
            break;
        }
        aux++;
    } 
    if(right == inf && aux < l) right = aux - now;
    int left = inf;
    aux = 0;
    for(int j=0; j<start; j++){
        if(edges[id][j] != aux){
            left = l - now + aux;
            break;
        }
        aux++;
    }

    if(left == inf && aux != now) left = l - now + aux;

    return min(left, right);
}

int dj(){
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    pq.push(ii(0, a));
    while(!pq.empty()){
        auto [d, u] = pq.top();
        pq.pop();
        if(vis[u]) continue;
        vis[u] = true;
        
        for(auto v: g[u]){
            if(vis[v]) continue;
            int wait = find(u, v, dis[u]%l);
            if(wait == l) continue;
            if(dis[u]+wait+1 < dis[v]){
                dis[v] = dis[u] + wait + 1;
                pq.push(ii(dis[v], v));
            }
        }
    }
    return dis[b];
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> m >> p >> l;
    
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
        ord.push_back(ii((min(a, b)), max(a, b)));
    } 
    sort(ord.begin(), ord.end());

    for(int i=0; i<p; i++){
        vector<int> v(l);
        for(int j=0; j<l; j++) {
            cin >> v[j];
            v[j]--;
        }
        for(int j=0; j<l; j++){
            int nxt = v[(j+1)%l];
            int id = lower_bound(ord.begin(), ord.end(), ii(min(v[j], nxt), max(v[j], nxt))) - ord.begin();
            edges[id].push_back(j);
        }
    }

    for(int i=0; i<ord.size(); i++){
        sort(edges[i].begin(), edges[i].end());
        edges[i].erase(unique(edges[i].begin(), edges[i].end()), edges[i].end());
    }

    cin >> a >> b;
    a--, b--;
    for(int i=0; i<n; i++) dis[i] = inf;
    dis[a] = 0;

    int ans = dj();

    if(ans == inf){
        cout << "IMPOSSIBLE\n";
    }
    else cout << dis[b] << endl;


}


