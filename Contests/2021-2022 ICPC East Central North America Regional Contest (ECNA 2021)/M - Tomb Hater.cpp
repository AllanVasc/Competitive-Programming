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

const int ms = 55 * 55 + 100;
const int sigma = 26;
int trie[ms][sigma], terminal[ms], z = 1;

void insert(string &s){
    int curr = 0;
    for(int i = 0; i < s.size(); i++){
        int id = s[i] - 'A';
        if(!trie[curr][id]){
            // cout << s[i] << " = " << z << '\n';
            trie[curr][id] = z++;
        }
        curr = trie[curr][id];
    }
    // cout << "terminal = " << curr << '\n';
    terminal[curr]++;
}

// DP[curr_r][curr_c][trie_id][last_dir]
int dp[55][55][ms][5];

int next_node(int r, int c, int trie_id){
    int n = grid.size();
    int m = grid[0].size();
    if(r < 0 || r >= n || c < 0 || c >= m) return 0;
    int id = grid[r][c] - 'A';
    return trie[trie_id][id];
}

int solve(int r, int c, int trie_id, int last_dir){
    int n = grid.size();
    int m = grid[0].size();
    if(r < 0 || r >= n || c < 0 || c >= m || trie_id == 0) return INF;
    if(r == n - 1 && terminal[trie_id]){
        return 1;
    }
    int& answ = dp[r][c][trie_id][last_dir];
    if(answ != -1) return answ;

    answ = INF;
    answ = min(answ, 1 + solve(r + 1, c, next_node(r + 1, c, trie_id), 0));
    if(last_dir != 2) answ = min(answ, 1 + solve(r, c - 1, next_node(r, c - 1, trie_id), 1));
    if(last_dir != 1) answ = min(answ, 1 + solve(r, c + 1, next_node(r, c + 1, trie_id), 2));
    if(terminal[trie_id]){
        answ = min(answ, 1 + solve(r + 1, c, next_node(r + 1, c, 0), 0));
        if(last_dir != 2) answ = min(answ, 1 + solve(r, c - 1, next_node(r, c - 1, 0), 1));
        if(last_dir != 1) answ = min(answ, 1 + solve(r, c + 1, next_node(r, c + 1, 0), 2));
    }


    return answ;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    grid.assign(n, vector<char>(m, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }

    while(k--){
        string s;
        cin >> s;
        insert(s);
    }

    memset(dp, -1, sizeof dp);
    int answ = INF;
    for(int i = 0; i < m; i++){
        int id = grid[0][i] - 'A';
        int next = trie[0][id];
        answ = min(answ, solve(0, i, next, 0));
    }

    if(answ == INF) cout << "impossible" << '\n';
    else cout << answ << '\n';

    return 0;
}