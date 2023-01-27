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

        vector<string> v(2);
        for(int i = 0; i < 2; i++) cin >> v[i];

        int total = 0;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < n; j++){
                if(v[i][j] == 'B') total++;
            }
        }

        bool has_answ = false;
        if(v[0][0] == 'B'){

            int r = 0;
            int c = 0;
            int step = 0;
            vector<vector<bool>> visited(2, vector<bool>(n, false));
            int curr = 1;
            visited[r][c] = true;

            while(c < n){
                if(v[!r][c] == 'B' && !visited[!r][c]){
                    visited[!r][c] = true;
                    curr++;
                    r = !r;
                    step = 0;
                }
                if(c < n - 1 && v[r][c + 1] == 'B' && !visited[r][c + 1]){
                    visited[r][c + 1] = true;
                    curr++;
                    c++;
                    step = 0;
                }
                if(step == 3) break;
                step++;
            }
            if(curr == total) has_answ = true;
        }
        if(v[1][0] == 'B'){

            int r = 1;
            int c = 0;
            int step = 0;
            vector<vector<bool>> visited(2, vector<bool>(n, false));
            int curr = 1;
            visited[r][c] = true;

            while(c < n){
                if(v[!r][c] == 'B' && !visited[!r][c]){
                    visited[!r][c] = true;
                    curr++;
                    r = !r;
                    step = 0;
                }
                if(c < n - 1 && v[r][c + 1] == 'B' && !visited[r][c + 1]){
                    visited[r][c + 1] = true;
                    curr++;
                    c++;
                    step = 0;
                }
                if(step == 3) break;
                step++;
            }
            if(curr == total) has_answ = true;
        }

        cout << (has_answ ? "YES" : "NO") << '\n';
    }
    
    return 0;
}