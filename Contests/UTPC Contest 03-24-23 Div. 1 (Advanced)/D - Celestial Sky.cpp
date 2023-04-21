#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int ms = 1e3 + 100;
int sky[ms][ms];
int ps[ms + 1][ms + 1];

vector<int> dir_x = {-1, -1, 0, +1, +1, +1, 0, -1, 0};
vector<int> dir_y = {0, -1, -1, -1, 0, +1, +1, +1, 0};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        sky[x][y]++;
    }

    // cout << "sky antes" << '\n';
    // for(int i = 0; i <= 10; i++){
    //     for(int j = 0; j <= 10; j++){
    //         cout << sky[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        for(int j = 0; j < dir_x.size(); j++){
            int xx = x + dir_x[j];
            int yy = y + dir_y[j];
            if(xx < 0 || yy < 0) continue;
            sky[xx][yy] = 0;
        }
    }

    // cout << "sky dps" << '\n';
    // for(int i = 0; i <= 10; i++){
    //     for(int j = 0; j <= 10; j++){
    //         cout << sky[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    
    ps[1][1] = sky[0][0];
    for(int i = 2; i <= ms; i++){
        ps[i][1] = ps[i - 1][1] + sky[i - 1][0];
    }
    for(int i = 2; i <= ms; i++){
        ps[1][i] = ps[1][i - 1] + sky[0][i - 1];
    }

    for(int i = 2; i <= ms; i++){
        for(int j = 2; j <= ms; j++){
            ps[i][j] = ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1] + sky[i - 1][j - 1];
        }
    }
    while(q--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1++, y1++, x2++, y2++;
        int answ = ps[x2][y2] - ps[x2][y1 - 1] - ps[x1 - 1][y2] + ps[x1 - 1][y1 - 1];
        cout << answ << '\n';
    }

    return 0;
}