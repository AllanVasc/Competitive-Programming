#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>

vector<vector<int>> g;
const int INF = 1e6;

vector<vector<int>> dir = { {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool check(int r, int c, int mask, vector<vector<int>>& dist){
    int n = g.size();
    int m = g[0].size();
    if(r < 0 || r >= n) return false;
    if(c < 0 || c >= m) return false;
    if((mask & (1 << g[r][c])) == 0) return false;
    if(dist[r][c] != INF) return false;

    return true;
}

bool bfs(ii& start, ii& end, int mask){
    int n = g.size();
    int m = g[0].size();
    queue<ii> q;
    vector<vector<int>> dist(n, vector<int>(m, INF));
    if( (mask & (1 << g[start.first][start.second])) )q.push(start);
    dist[start.first][start.second] = 0;
    while(!q.empty()){
        auto [r, c] = q.front();
        q.pop();
        if(dist[end.first][end.second] != INF) return true;
        for(auto i : dir){
            int rr = r + i[0];
            int cc = c + i[1];
            if(check(rr, cc, mask, dist)){
                dist[rr][cc] = dist[r][c] + 1;
                q.push({rr, cc});
            }
        }
    }
    return false;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    ii start, end;
    cin >> start.first >> start.second;
    cin >> end.first >> end.second;

    start.first--, start.second--;
    end.first--, end.second--;

    g.assign(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> g[i][j];
            g[i][j]--;
        }
    }

    int answ = 10;
    // cout << bfs(start, end, 71) << '\n';
    for(int mask = 0; mask < (1 << 10); mask++){
        int qtd = __builtin_popcount(mask);
        if( qtd < answ){
            if(bfs(start, end, mask)){
                answ = min(answ, qtd);
            }
        }
    }

    cout << answ << '\n';
    return 0;
}