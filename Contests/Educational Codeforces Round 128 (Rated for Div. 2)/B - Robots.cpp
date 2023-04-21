#include <bits/stdc++.h>
using namespace std;

#define int long long
#define optimize ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ALL(x) x.begin(), x.end()
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define iii tuple<int,int,int>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int32_t main() {
    optimize;
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<string> grid(n);
        for(int i = 0; i < n; i++) cin >> grid[i];
        pii fRobot = {-1, -1};
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 'R') {
                    fRobot = {i, j};
                    break;
                }
            }
            if(fRobot.first != -1) break;
        }
        bool possible = true;
        for(int i = fRobot.first + 1; i < n; i++){
            for(int j = 0; j < fRobot.second; j++){
                if(grid[i][j] == 'R') possible = false;
            }
        }
        cout << (possible ? "YES" : "NO") << '\n';
    }
    return 0;
}