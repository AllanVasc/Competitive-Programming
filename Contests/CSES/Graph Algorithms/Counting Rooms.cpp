#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

vector<vector<int>> visited;
vector<vector<char>> v;

bool check(int r, int c){
    int n = v.size();
    int m = v[0].size();

    if(r < 0 || r >= n) return false;
    if(c < 0 || c >= m) return false;
    if(v[r][c] == '#') return false;

    return true;
}

void bfs(int i, int j){
    visited[i][j] = 1;
    queue<ii> q;
    q.push({i,j});
    
    vector<ii> dir = { {1,0}, {0,1}, {-1,0}, {0, -1} };
    while(!q.empty()){
        ii curr = q.front();
        q.pop();

        for(auto offset : dir){
            int cr = curr.first + offset.first;
            int cc = curr.second + offset.second;

            if(check(cr, cc) && visited[cr][cc] == 0){
                q.push({cr,cc});
                visited[cr][cc] = 1;
            }
        }
    }
}

void debug(vector<vector<int>> v){

    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[0].size(); j++){
            cout << v[i][j] << " ";
        }
        cout << '\n';
    }
}

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    v.assign(n, vector<char>(m, '*'));
    visited.assign(n, vector<int>(m, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> v[i][j];
        }
    }

    int answ = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(v[i][j] == '.' && visited[i][j] == 0){
                answ++;
                bfs(i,j);
                // debug(visited);
            }
        }
    }

    cout << answ << '\n';

    return 0;
}