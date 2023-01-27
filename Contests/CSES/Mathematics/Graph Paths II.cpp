#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

template<typename T = int>
struct Matrix{
    int r, c;
    vector<vector<T>> mat;

    Matrix(int r, int c): r(r), c(c){
        mat.assign(r, vector<T>(c, INF));
    }

    Matrix(vector<vector<T>> m, int r, int c): r(r), c(c){
        mat.assign(r, vector<T>(c, INF));
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                this->mat[i][j] = m[i][j];
    }

    Matrix operator *(Matrix &other){
        Matrix answ(this->r, other.c);
        for(int i = 0; i < r; i++){
            for(int j = 0; j < other.c; j++){
                for(int k = 0; k < c; k++){ // MOD only if necessary
                    if(mat[i][k] == INF || other.mat[k][j] == INF) continue;
                    answ.mat[i][j] = min(answ.mat[i][j], mat[i][k] + other.mat[k][j]);
                }
            }
        }
        return answ;
    }

    vector<T> operator [](int r){
        return mat[r];
    }
};

Matrix<int> fexpo(Matrix<int> x, int y){
    Matrix answ(x.r, x.c);
    for(int i = 0; i < x.r; i++) answ.mat[i][i] = 1;
    int count = 1;
    while(y){
        if(y & 1){
            if(count){
                count--;
                answ = x;
            }
            else answ = answ * x;
        }
        x = x * x;
        y = y >> 1;
    }
    return answ;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    
    Matrix g(n, n);
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        g.mat[u][v] = min(g.mat[u][v], w);
    }
    Matrix answ = fexpo(g, k);
    cout << (answ[0][n - 1] == INF ? -1 : answ[0][n - 1]) << '\n';

    return 0;
}