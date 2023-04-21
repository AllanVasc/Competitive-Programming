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
int hor[ms][ms];
int ver[ms][ms];
bool flipped[ms][ms];

vector<int> dx = {0, 1, 0, -1}; // r, d, l, u
vector<int> dy = {1, 0, -1, 0};

bool inGrid(int r, int c, int n, int m){
    if(r < 0 || c < 0 || r >= n || c >= m) return false;
    return true;
}

int query(int x, int y, int n, int m){
    int nx = x, ny = y;
    int db = 1;
    for(int i = 0; i < 2; i ^= 1){
        nx = nx + dx[i];
        ny = ny + dy[i];
        if(!inGrid(nx,ny,n,m) || flipped[nx][ny]) break;
        db++;
    }

    nx = x, ny = y;
    int bd = 1;
    for(int i = 1; i < 2; i ^= 1){
        nx = nx + dx[i];
        ny = ny + dy[i];
        if(!inGrid(nx,ny,n,m) || flipped[nx][ny]) break;
        bd++;
    }

    nx = x, ny = y;
    int ce = 1;
    for(int i = 1; i < 2; i ^= 1){
        nx = nx + dx[i + 2];
        ny = ny + dy[i + 2];
        if(!inGrid(nx,ny,n,m) || flipped[nx][ny]) break;
        ce++;
    }

    nx = x, ny = y;
    int ec = 1;
    for(int i = 0; i < 2; i ^= 1){
        nx = nx + dx[i + 2];
        ny = ny + dy[i + 2];
        if(!inGrid(nx,ny,n,m) || flipped[nx][ny]) break;
        ec++;
    }

    return ec * bd + ce * db - 1;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n, m, q;
    cin >> n >> m >> q;

    int answ = n * m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(j > 1) hor[i][j] = 1;
            hor[i][j] += hor[i - 1][j - 1];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(i > 1) ver[i][j] = 1;
            ver[i][j] += ver[i - 1][j - 1];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            answ += hor[i][j] + ver[i][j] + hor[i - 1][j] + ver[i][j - 1];
        }
    }
    // cout << "answ = " << answ << '\n';

    while(q--){
        int x, y;
        cin >> x >> y;
        x--,y--;
        if(flipped[x][y]){
            answ += query(x,y,n,m);
        }
        else{
            answ -= query(x,y,n,m);
        }
        flipped[x][y] ^= 1;
        cout << answ << '\n';
    }
    return 0;
}