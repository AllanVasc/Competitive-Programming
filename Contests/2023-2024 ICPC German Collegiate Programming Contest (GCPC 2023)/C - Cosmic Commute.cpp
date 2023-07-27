#include <bits/stdc++.h>

using namespace std;
#define int long long
#define ii pair<int,int>

const int ms = 2e5 + 5;

vector<int> best[ms], g[ms];
int n, m, k;
int d[2][ms], hole[ms];

void bfs(int ini, int id){
    queue<int> q;
    q.push(ini);
    memset(d[id], 0x3f, sizeof d[id]);
    d[id][ini] = 0;

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto v : g[u]){
            if(d[id][u]+1 < d[id][v]){
                q.push(v);
                d[id][v] = d[id][u] +1;
            }
        }
    }
}


signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);


    cin >> n >> m >> k;

    for(int i=0; i<k; i++){
        int a; cin >> a;
        hole[a-1] = 1;
    }


    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    bfs(0, 0);
    bfs(n-1, 1);
    int sum=0;
    for(int i=0; i<n; i++){
        if(hole[i]) sum += d[1][i];
    }


    int ans = d[0][n-1] * (k-1);
    for(int i=0; i<n; i++){
        if(hole[i]){
            ans = min(ans, (k-1)*d[0][i] + (sum - d[1][i]));
        }
    }

    cout << ans/gcd(ans, k-1) << "/" <<  (k-1)/gcd(ans, k-1) << endl; 

}