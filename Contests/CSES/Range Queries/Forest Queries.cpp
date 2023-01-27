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
    
    int n, q;
    cin >> n >> q;

    vector<vector<int>> v(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char aux;
            cin >> aux;
            if(aux == '.') v[i][j] = 0;
            else v[i][j] = 1;
        }
    }

    vector<vector<int>> ps2d(n+1, vector<int>(n + 1, 0));
    for(int i = 1; i <= n; i++){
        ps2d[1][i] = v[0][i - 1] + ps2d[1][i - 1];
        ps2d[i][1] = v[i - 1][0] + ps2d[i - 1][1];
    }

    for(int i = 2; i <= n; i++){
        for(int j = 2; j <= n; j++){
            ps2d[i][j] = v[i - 1][j-1] + ps2d[i - 1][j] + ps2d[i][j - 1] - ps2d[i - 1][j - 1];
        }
    }
    
    for(int i = 0; i < q; i++){
        ii p1, p2; // y x
        cin >> p1.first >> p1.second  >> p2.first >> p2.second;
        if(p1 > p2) swap(p1, p2);

        cout << ps2d[p2.first][p2.second] 
                - ps2d[p2.first][p1.second - 1] 
                - ps2d[p1.first - 1][p2.second] 
                + ps2d[p1.first - 1][p1.second - 1] << '\n';
    }
    return 0;
}