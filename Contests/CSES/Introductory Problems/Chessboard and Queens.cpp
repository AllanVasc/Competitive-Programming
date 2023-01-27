#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

vector<vector<int>> grid;
int answ = 0;

vector<int> dr = {-1, 0, 1, 0, -1, -1, +1, +1};
vector<int> dc = {0, 1, 0, -1, -1, +1, +1, -1};

bool verify(int r, int c){
    if(grid[r][c] == 0) return false;
    for(int i = 0; i < 8; i++){
        int curr_r = r;
        int curr_c = c;
        while(curr_r < 8 && curr_r >= 0 && curr_c < 8 && curr_c >= 0){
            if(grid[curr_r][curr_c] == -1) return false;
            curr_r += dr[i];
            curr_c += dc[i];
        }
    }

    return true;
}

void solve(int r, int c, int k){
    if(k == 8){
        answ++;
        return;
    }
    if(r == 8 || c == 8) return;

    for(int i = r; i < 8; i++){
        for(int j = c; j < 8; j++){
            if(verify(i, j)){
                int backup = grid[i][j];
                grid[i][j] = -1;
                solve(i + 1, 0, k + 1);
                grid[i][j] = backup;
            }
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    const int n = 8;
    grid.assign(8, vector<int>(8, 0));
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < n; j++){
            char aux;
            cin >> aux;
            if(aux == '.') grid[i][j] = 1;
            else if(aux == '*') grid[i][j] = 0;
        }
    }
    
    solve(0,0,0);
    cout << answ << '\n';
    return 0;
}