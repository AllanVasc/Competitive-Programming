#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e9 + 5;
const int MOD = 1e9 + 7;

const int ms = 100 + 10;
vector<int> roads;
vector<vector<int>> edges;
vector<vector<int>> dist;
int dp[ms][ms];

int solve(int l, int r){
    if(l == r) return 0;
    int& answ = dp[l][r];
    if(answ != -1) return answ;
    int currDist = 0;
    for(int i = l; i < r; i++){
        currDist += edges[roads[i]][roads[i + 1]];
    }
    if(currDist == dist[roads[l]][roads[r]]) return (answ = 0);
    answ = INF;
    for(int i = l; i < r; i++){
        answ = min(answ, 1 + solve(l, i) + solve(i + 1, r));
    }
    return answ;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    int cnt = 1;
    while(cin >> n){
        if(n == 0) break;
        cout << "Case " << cnt++ << ": ";

        edges.assign(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> edges[i][j];
            }
        }

        int m;
        cin >> m;
        roads.assign(m, 0);
        for(int i = 0; i < m; i++) cin >> roads[i];

        dist.assign(n, vector<int>(n, INF));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                dist[i][j] = edges[i][j];
                if(i != j && edges[i][j] == 0) dist[i][j] = INF;
            }
        }
        // cout << "Dist = " << '\n';
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < n; j++){
        //         cout << dist[i][j] << " ";
        //     }
        //     cout << '\n';
        // }
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if (dist[i][k] < INF && dist[k][j] < INF)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); 
                }
            }
        }
        memset(dp, -1, sizeof dp);
        cout << solve(0, m - 1) << '\n';
    }
    return 0;
}