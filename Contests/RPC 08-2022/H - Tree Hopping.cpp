// 
#include <bits/stdc++.h>
using namespace std;
  
#define int long long
  
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18;
const int MOD = 1e9 + 7;

const int MAXN = 1e5 + 100;
const int LOG = 20;

vector<vector<int>> children;
int up[MAXN][LOG];
int depth[MAXN];

void dfs(int a, int p) {
	for(int b : children[a]){
		if(b == p) continue;    // don't go back to the father
        depth[b] = depth[a] + 1;
		up[b][0] = a;           // a is parent of b
		for(int j = 1; j < LOG; j++) {
			up[b][j] = up[ up[b][j-1] ][j-1];
		}
		dfs(b, a);
	}
}

int lca(int a, int b){
    if(depth[a] < depth[b]) swap(a,b);

    int k = depth[a] - depth[b];
    for(int j = LOG - 1; j >= 0; j--){
        if(k & (1 << j)){
            a = up[a][j];
        }
    }
    if(a == b) return a;
    for(int j = LOG-1; j >= 0; j--){
        if(up[a][j] != up[b][j]){
            a = up[a][j];
            b = up[b][j];
        }
    }
    return up[a][0];
}

int dist(int u,int v){
    int parent = lca(u,v);
    int dist = depth[u] - depth[parent] + depth[v] - depth[parent];
    // cout << "lca de " << u << " e " << v << " eh =  " << parent << " com dist = " << dist << '\n';
    return dist;
}

void build(int n){
    children.assign(n, vector<int>());

    for(int i = 0; i < n; i++){
        for(int j = 0; j < LOG; j++){
            up[i][j] = 0;
        }
        depth[i] = 0;
    }
}

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        build(n);

        for(int i = 0; i < n-1; i++){
            int u,v;
            cin >> u >> v;

            children[u-1].push_back(v-1);
            children[v-1].push_back(u-1);
        }

        vector<int> way(n,0);
        for(int i = 0; i < n; i++) cin >> way[i];
        
        dfs(0,0);
        // for(int i = 0; i < n; i++){
        //     cout << "depth de " << i << " = " << depth[i] << '\n';
        // }

        
        bool answ = true;
        for(int i = 1; i < n; i++){
            if(dist(way[i-1] - 1, way[i] - 1) > 3) answ = false;
        }

        cout << answ << '\n';
    }

    return 0;
}