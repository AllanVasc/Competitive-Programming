#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> grid;
using ii =  pair<int,int>;
vector<vector<int>> distMonster;

vector<vector<int>> dir = { {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

const int INF = 1e9;

bool check(int r, int c){
    int n = grid.size();
    int m = grid[0].size();
    if(r < 0 || r >= n) return false;
    if(c < 0 || c >= m) return false;
    if(distMonster[r][c] != INF) return false;

    return true;
}

void bfsmonster(vector<ii>& monster){
    queue<ii> q;
    for(int i = 0; i < monster.size(); i++){
        q.push(monster[i]);
        distMonster[monster[i].first][monster[i].second] = 0;
    }
    while(!q.empty()){
        auto curr = q.front();
        q.pop();
        for(int i = 0; i < dir.size(); i++){
            int rr = curr.first + dir[i][0];
            int cc = curr.second + dir[i][1];

            if(check(rr, cc)){
                q.push({rr, cc});
                distMonster[rr][cc] = distMonster[curr.first][curr.second] + 1;
            }
        }
    }
}

vector<vector<int>> dist;

bool checkStart(int r, int c, int d){
    int n = grid.size();
    int m = grid[0].size();
    if(r < 0 || r >= n) return false;
    if(c < 0 || c >= m) return false;
    if(distMonster[r][c] <= d) return false;
    if(dist[r][c] != INF) return false;

    return true;
}


int bfs(ii start, ii end, int d){
    queue<ii> q;
   
    dist.assign(grid.size(), vector<int>(grid[0].size(), INF));

    if(distMonster[start.first][start.second] <= d) return -1;

    q.push(start);
    dist[start.first][start.second] = 0;

    while(!q.empty()){
        auto curr = q.front();
        q.pop();

        if(curr == end) return dist[end.first][end.second];

        for(int i = 0; i < dir.size(); i++){
            int rr = curr.first + dir[i][0];
            int cc = curr.second + dir[i][1];

            if(checkStart(rr, cc, d)){
                q.push({rr, cc});
                dist[rr][cc] = dist[curr.first][curr.second] + 1;
            }
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, d;
    cin >> n >> m >> d;

    grid.assign(n, vector<char>(m, '*'));
    distMonster.assign(n, vector<int>(m, INF));

    vector<ii> monsters;
    ii start = {-1, -1};
    ii end = {-1 , -1};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'M'){
                monsters.push_back({i, j});
            }
            else if(grid[i][j] == 'S') start = {i, j};
            else if(grid[i][j] == 'F') end = {i, j};
        }
    }

    bfsmonster(monsters);

    // cout << "dist monster = " << '\n';
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout << distMonster[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    cout << bfs(start, end, d) << '\n';

    // cout << "dist  = " << '\n';
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout << dist[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    
    return 0;
}