#include<bits/stdc++.h>
using namespace std;

#define int long long
using ii = pair<int,int>;
const int INF = 1e18;

bool check(int r, int c, vector<vector<char>>& grid, vector<vector<bool>>& visited){
    int n = grid.size();
    int m = grid[0].size();
    if(r < 0 || r >= n || c < 0 || c >= m) return false;
    if(visited[r][c] == true) return false;
    if(grid[r][c] == '1') return false;
    return true;
}

vector<int> dir_x = {-1, -1, 0, +1, +1, +1, 0, -1};
vector<int> dir_y = {0, -1, -1, -1, 0, +1, +1, +1};

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<vector<char>> grid;
    grid.assign(2, vector<char>(n, '*'));
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }

    queue<ii> q;
    vector<vector<bool>> visited;
    visited.assign(2, vector<bool>(n, false));
    q.push({0,0});
    visited[0][0] = true;
    while(!q.empty()){
        auto [r, c] = q.front();
        q.pop();

        for(int i = 0; i < dir_x.size(); i++){
            int rr = r + dir_y[i];
            int cc = c + dir_x[i];
            if(check(rr,cc, grid, visited)){
                q.push({rr, cc});
                visited[rr][cc] = true;
            }
        }
    }

    if(visited[1][n - 1]){
        cout << "YES" << '\n';
    }
    else{
        cout << "NO" << '\n';
    }

    return 0;
}