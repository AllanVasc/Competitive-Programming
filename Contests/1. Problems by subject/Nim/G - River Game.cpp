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
vector<vector<int>> wetArea;
vector<vector<ii>> shores;

vector<vector<int>> dir = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };

bool check(int r, int c){
    int n = grid.size();
    if(r < 0 || r >= n) return false;
    if(c < 0 || c >= n) return false;
    if(wetArea[r][c] != -1) return false;
    if(grid[r][c] != '*') return false;

    return true;
}

bool is_ground(int r, int c){
    int n = grid.size();
    if(r < 0 || r >= n) return false;
    if(c < 0 || c >= n) return false;
    if(grid[r][c] == '*') return false;
    if(grid[r][c] == 'x') return false;

    return true;
}

void bfsWet(ii start, int id){
    queue<ii> q;
    q.push(start);
    wetArea[start.first][start.second] = id;
    set<ii> adj_list;

    while(!q.empty()){
        auto [cur_x, cur_y] = q.front();
        q.pop();

        for(auto offset : dir){
            int rr = cur_x + offset[0];
            int cc = cur_y + offset[1];

            if(is_ground(rr, cc)) adj_list.insert({rr, cc});

            if(check(rr, cc)){
                q.push({rr, cc});
                wetArea[rr][cc] = wetArea[cur_x][cur_y];
            }
        }
    }
    map<ii, bool> visited;
    for(auto i : adj_list){
        if(visited[i] == false){
            vector<ii> component;
            q.push(i);
            visited[i] = true;
            while(!q.empty()){
                auto [cur_x, cur_y] = q.front();
                q.pop();
                component.push_back({cur_x, cur_y});
                for(auto offset : dir){
                    int rr = cur_x + offset[0];
                    int cc = cur_y + offset[1];

                    if(adj_list.count({rr, cc}) != 0 && visited[{rr,cc}] == false){
                        q.push({rr, cc});
                        visited[{rr,cc}] = true;
                    }
                }
            }
            shores.push_back(component);
        }
    }
}

const int MAXN = 21;
int dp[1 << MAXN];

int solve(int mask, vector<ii> & shore){
    int n = shore.size();
    map<ii, bool> used;
    for(int i = 0; i < n; i++){
        if((1 << i) & mask) used[shore[i]] = true;
    }

    vector<int> possibles;
    for(int i = 0; i < n; i++){
        auto [cur_x, cur_y] = shore[i];
        if(((1 << i) & mask) == 0){
            int qtd_adj = 0;
            for(auto offset : dir){
                int rr = cur_x + offset[0];
                int cc = cur_y + offset[1];
                if(used[{rr,cc}]) qtd_adj++;
            }
            if(qtd_adj == 0) possibles.push_back(i);
        }
    }
    // cout << "mask = " << mask << '\n';
    if(possibles.size() == 0){
        return dp[mask] = 0;
    }

    int & answ = dp[mask];
    if(answ != -1) return answ;
    set<int> grundy;

    for(auto i : possibles){
        grundy.insert(solve(mask | (1 << i), shore));
    }

    int cnt = 0;
    while(grundy.count(cnt) != 0) cnt++;
    return answ = cnt;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    grid.assign(n, vector<char>(n, '!'));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }

    wetArea.assign(n, vector<int>(n, -1));
    int qtd_wetArea = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == '*' && wetArea[i][j] == -1){
                bfsWet({i,j}, qtd_wetArea);
                qtd_wetArea++;
            }
        }
    }

    // cout << "wetArea = " << '\n';
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         if(wetArea[i][j] != -1) cout << wetArea[i][j] << " ";
    //         else cout << "X" << " ";
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';
    // cout << "shores: " << '\n';
    // for(int i = 0; i < shores.size(); i++){
    //     cout << i + 1 << ": ";
    //     for(auto [r,c] : shores[i]){
    //         cout << "{" << r << "," << c << "}, ";
    //     }
    //     cout << '\n';
    // }

    vector<int> nimber(shores.size());
    for(int i = 0; i < shores.size(); i++){
        memset(dp, -1, sizeof dp);
        nimber[i] = solve(0, shores[i]);
    }

    int ans = 0;
    // cout << "nimbers: ";
    for(auto i : nimber){
        //cout << i << " ";
        ans ^= i;
    }
    //cout << '\n';

    if(ans) cout << "First player will win" << '\n';
    else cout << "Second player will win" << '\n';

    return 0;
}