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
vector<vector<int>> dist_person;
vector<vector<int>> dist_monster;

vector<ii> dir = { {1,0}, {-1,0}, {0,1}, {0,-1} };
vector<char> path = { 'U', 'D', 'L', 'R'};

bool check(int r, int c){
    int n = grid.size();
    int m = grid[0].size();

    if(r < 0 || r >= n) return false;
    if(c < 0 || c >= m) return false;
    if(grid[r][c] == '#') return false;

    return true;
}

void bfs_person(ii start){
    dist_person[start.first][start.second] = 0;
    queue<ii> q;
    q.push(start);

    while(!q.empty()){
        ii curr = q.front();
        q.pop();

        for(auto offset : dir){
            int r = curr.first + offset.first;
            int c = curr.second + offset.second;

            if(check(r, c) && dist_person[r][c] == INF){
                dist_person[r][c] = dist_person[curr.first][curr.second] + 1;
                q.push({r,c});
            }

        }

    }
}

void bfs_monster(vector<ii> start){
    queue<ii> q;

    for(int i = 0; i < start.size(); i++){
        dist_monster[start[i].first][start[i].second] = 0;
        q.push(start[i]);
    }

    while(!q.empty()){
        ii curr = q.front();
        q.pop();

        for(auto offset : dir){
            int r = curr.first + offset.first;
            int c = curr.second + offset.second;

            if(check(r, c) && dist_monster[r][c] == INF){
                dist_monster[r][c] = dist_monster[curr.first][curr.second] + 1;
                q.push({r,c});
            }

        }

    }
}

int32_t main(){
  
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    int n, m;
    cin >> n >> m;

    grid.assign(n, vector<char>(m, '!'));
    ii person;
    vector<ii> monster;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'M') monster.push_back({i,j});
            else if(grid[i][j] == 'A') person = {i,j};
        }
    }
    dist_person.assign(n, vector<int>(m, INF));
    dist_monster.assign(n, vector<int>(m, INF));

    bfs_person(person);
    bfs_monster(monster);

    ii answ = {-1, -1};
    for(int i = 0; i < n; i++){
        if(dist_person[i][0] < dist_monster[i][0]){
            answ = {i, 0};
            break;
        }
        else if(dist_person[i][m-1] < dist_monster[i][m-1]){
            answ = {i, m-1};
            break;
        }
    }

    for(int i = 0; i < m; i++){
        if(dist_person[0][i] < dist_monster[0][i]){
            answ = {0, i};
            break;
        }
        else if(dist_person[n-1][i] < dist_monster[n-1][i]){
            answ = {n-1, i};
            break;
        }
    }

    // cout << "dist person:\n";
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout << dist_person[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    // cout << "dist monster:\n";
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout << dist_monster[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    // cout << "resposta em: " << answ.first << " " << answ.second << '\n';
    if(answ.first == -1){
        cout << "NO" << '\n';
    }
    else{
        cout << "YES" << '\n';
        vector<char> way;
        ii curr = answ;
        while(curr != person){

            for(int i = 0; i < 4; i++){
                int r = curr.first + dir[i].first;
                int c = curr.second + dir[i].second;

                if(check(r,c) && dist_person[r][c] + 1 == dist_person[curr.first][curr.second]){
                    curr = {r,c};
                    way.push_back(path[i]);
                    break;
                }
            }
        }

        reverse(way.begin(), way.end());
        cout << way.size() << '\n';
        for(int i = 0; i < way.size(); i++){
            cout << way[i];
        }
        cout << '\n';
    }

    return 0;
}