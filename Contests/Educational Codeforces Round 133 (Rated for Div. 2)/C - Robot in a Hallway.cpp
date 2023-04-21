#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> grid(2, vector<int>(n, 0));
        vector<int> clk(n), anti_clk(n);
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < n; j++){
                cin >> grid[i][j];
                grid[i][j]++;
            }
        }
        grid[0][0] = 0;
        clk[n - 1] = max(grid[0][n - 1] + 1, grid[1][n - 1]);
        anti_clk[n - 1] = max(grid[0][n - 1], grid[1][n - 1] + 1);
        int sq = 2;
        for(int i = n - 2; i >= 0; i--){
            sq += 2;
            clk[i] = max({clk[i + 1] + 1, grid[0][i] + sq - 1, grid[1][i]});
            anti_clk[i] = max({anti_clk[i + 1] + 1, grid[0][i], grid[1][i] + sq - 1});
        }

        int tm = -1;
        int answ = INF;
        for(int i = 0; i < n; i++, sq -= 2){
            if(i & 1){  // anti_clk
                answ = min(answ, max(tm + sq, anti_clk[i]));
                tm = max(tm + 1, grid[1][i]);
                tm = max(tm + 1, grid[0][i]);
            }
            else{   // clk
                answ = min(answ, max(tm + sq, clk[i]));
                tm = max(tm + 1, grid[0][i]);
                tm = max(tm + 1, grid[1][i]);
            }
        }
        cout << answ << '\n';
    }
    return 0;
}