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
    // ios::sync_with_stdio(false);
    // cin.tie(0), cout.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> grid(2, vector<int>(n, 0));
        grid[0][0] = 2*n;
        grid[1][n - 1] = 2*n - 1;
        int start = 1;
        int last = 2*n - 2;
        for(int i = 0; i < n - 1; i++){
            if(i % 2 == 0){
                grid[1][i] = start;
                start++;
                grid[0][i + 1] = start;
                start++;
            }
            else{
                grid[0][i + 1] = last;
                grid[1][i] = last - 1;
                last -= 2;
            }
        }

        for(int i = 0; i < 2; i++){
            for(int j = 0; j < n; j++){
                cout << grid[i][j] << " ";
            }
            cout << '\n';
        }
    } 
    return 0;
}