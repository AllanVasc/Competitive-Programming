#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

vector<vector<char>> grid;
vector<vector<int>> dist;
vector<ii> dir = { {1,0}, {-1,0}, {0,1}, {0,-1}};
vector<char> path = { 'U', 'D', 'L', 'R'};

bool check(int r, int c){
    int n = grid.size();
    int m = grid[0].size();
    if(r < 0 || r >= n) return false;
    if(c < 0 || c >= m) return false;
    if(grid[r][c] == '#') return false;

    return true;
}

bool bfs(ii start, ii end){

    queue<ii> q;
    q.push(start);
    dist[start.first][start.second] = 0;

    while(!q.empty()){
        ii curr = q.front();
        q.pop();

        if(curr.first == end.first && curr.second == end.second){
            return true;
        }

        for(auto offset : dir){
            int cr = curr.first + offset.first;
            int cc = curr.second + offset.second;

            if(check(cr,cc) && dist[cr][cc] == INF){
                dist[cr][cc] = dist[curr.first][curr.second] + 1;
                q.push({cr, cc});
            }
        }
    }
    return false;
}

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    grid.assign(n, vector<char>(m, '*'));
    dist.assign(n, vector<int>(m, INF));
    ii start;
    ii end;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'A'){
                start = {i,j};
            }
            else if(grid[i][j] == 'B'){
                end = {i,j};
            }
        }
    }

    if(bfs(start, end)){
        cout << "YES" << '\n';
        
        ii curr = end;
        vector<char> answ;

        while(curr != start){

            for(int i = 0; i < 4; i++){
                int r = curr.first + dir[i].first;
                int c = curr.second + dir[i].second;

                if(check(r,c) && dist[r][c] == dist[curr.first][curr.second] - 1){
                    answ.push_back(path[i]);
                    curr = {r,c};
                    break;
                }
            }
        }

        reverse(answ.begin(), answ.end());
        cout << answ.size() << '\n';
        for(int i = 0; i < answ.size(); i++){
            cout << answ[i];
        }
        cout << '\n';
    }
    else{
        cout << "NO" << '\n';
    }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout << dist[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    return 0;
}