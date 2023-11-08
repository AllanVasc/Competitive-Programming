#include <bits/stdc++.h>
using namespace std;

#define int long long
#define optimize ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define iii tuple<int,int,int>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

signed main() {
    optimize;
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<string> grid(n);
        for(int i = 0; i < n; i++) cin >> grid[i];
        
        vector<int> cntRow(n, 0);
        vector<int> cntCol(m, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 'L'){
                    cntRow[i] += 2;
                    j++;
                }
                else if(grid[i][j] != '.') cntRow[i]++;
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[j][i] == 'U'){
                    cntCol[i] += 2;
                    j++;
                }
                else if(grid[j][i] != '.') cntCol[i]++;
            }
        }
        // cout << "cntRow: ";
        // for(auto x : cntRow) cout << x << " ";
        // cout << '\n';
        // cout << "cntCol: ";
        // for(auto x : cntCol) cout << x << " ";
        // cout << '\n';

        bool flag = true;
        for(int x : cntRow) if(x & 1) flag = false;
        for(int x : cntCol) if(x & 1) flag = false;
        if(!flag){
            cout << -1 << '\n';
            continue;
        }
        // Build
        vector<vector<pair<pii, pii>>> hor(m), vert(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 'L'){
                    hor[j].push_back({{i, j}, {i, j + 1}});
                }
                if(grid[i][j] == 'U'){
                    vert[i].push_back({{i, j}, {i + 1, j}});
                }
            }
        }
        // cout << "hor" << '\n';
        // for(int i = 0; i < m; i++){
        //     cout << i << " e " << i + 1 << " : ";
        //     for(auto x : hor[i]) cout << x << " ";
        //     cout << '\n';
        // }
        // cout << "vert" << '\n';
        // for(int i = 0; i < n; i++){
        //     cout << i << " e " << i + 1 << " : ";
        //     for(auto x : vert[i]) cout << x << " ";
        //     cout << '\n';
        // }
        // flag = true;
        // for(int i = 0; i < n; i++){
        //     if(hor[i].size() % 2) flag = false;
        // }
        // for(int i = 0; i < m; i++){
        //     if(vert[i].size() % 2) flag = false;
        // }
        // if(!flag){
        //     cout << -1 << '\n';
        //     continue;
        // }

        bool turn = false;
        for(int i = 0; i < m; i++){
            for(auto [x, y] : hor[i]){
                auto [a, b] = x;
                auto[c, d] = y;
                if(turn){
                    grid[a][b] =  'B';
                    grid[c][d] = 'W';
                }
                else{
                    grid[a][b] =  'W';
                    grid[c][d] = 'B';
                }
                turn = !turn;
            }
        }
        for(int i = 0; i < n; i++){
            for(auto [x, y] : vert[i]){
                auto [a, b] = x;
                auto[c, d] = y;
                if(turn){
                    grid[a][b] =  'B';
                    grid[c][d] = 'W';
                }
                else{
                    grid[a][b] =  'W';
                    grid[c][d] = 'B';
                }
                turn = !turn;
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << grid[i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}