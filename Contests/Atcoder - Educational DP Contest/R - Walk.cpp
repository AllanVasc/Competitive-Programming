#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

struct Mat{
    int r, c;
    vector<vector<int>> mat;
    Mat(int r, int c) : r(r), c(c){
        mat.assign(r, vector<int>(c, 0));
    }
    
    Mat(vector<vector<int>> t){
        r = t.size();
        c = t[0].size();
        mat.assign(r, vector<int>(c, 0));
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                mat[i][j] = t[i][j];
    }
    Mat operator *(Mat& other){
        Mat answ(r, other.c);
        for(int i = 0; i < r; i++){
            for(int j = 0; j < other.c; j++){
                for(int k = 0; k < c; k++){
                    answ.mat[i][j] = (answ.mat[i][j] + mat[i][k] * other.mat[k][j] % MOD) % MOD;
                }
            }
        }
        return answ;
    }
};

Mat fexp(Mat x, int y){
    Mat answ(x.r, x.c);
    for(int i = 0; i < x.c; i++){
        answ.mat[i][i] = 1;
    }
    while(y){
        if(y & 1) answ = answ * x;
        x = x * x;
        y >>= 1;
    }
    return answ;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<vector<int>> g(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> g[i][j];
        }
    }

    Mat graph(g);
    Mat result = fexp(g, k);

    int answ = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            answ += result.mat[i][j];
            answ %= MOD;
        }
    }

    cout << answ << '\n';
    return 0;
}