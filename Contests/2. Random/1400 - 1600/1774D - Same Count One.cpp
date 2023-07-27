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
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, 0));
        vector<int> onePerRow(n, 0);
        int total = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> grid[i][j];
                if(grid[i][j]){
                    onePerRow[i]++;
                    total++;
                }
            }
        }
        if(total % n){
            cout << -1 << '\n';
        }
        else{
            vector<tuple<int,int,int>> op;
            for(int i = 0; i < m; i++){
                vector<pii> donate;
                vector<pii> need;
                for(int j = 0; j < n; j++){
                    if(grid[j][i] && onePerRow[j] > total/n){
                        donate.push_back({onePerRow[j], j});
                    }
                    if(!grid[j][i] && onePerRow[j] < total/n){
                        need.push_back({onePerRow[j], j});
                    }
                }
                sort(donate.begin(), donate.end());
                sort(need.rbegin(), need.rend());
                while(!donate.empty() && !need.empty()){
                    auto [don, rdon] = donate.back();
                    auto [nd, rnd] = need.back();
                    op.push_back({rdon + 1, rnd + 1, i + 1});
                    onePerRow[rdon]--;
                    onePerRow[rnd]++;
                    donate.pop_back();
                    need.pop_back();
                }
            }

            cout << op.size() << '\n';
            for(auto [x, y, z] : op){
                cout << x << " " << y << " " << z << '\n';
            }
        }

    }
    return 0;
}