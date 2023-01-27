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
        mat.assign(r, vector<T>(c, 0));
    }

    Matrix(vector<vector<T>> m, int r, int c): r(r), c(c){
        mat.assign(r, vector<T>(c, 0));
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                this->mat[i][j] = m[i][j];
    }

    Matrix operator *(Matrix &other){
        Matrix answ(this->r, other.c);
        for(int i = 0; i < r; i++){
            for(int j = 0; j < other.c; j++){
                for(int k = 0; k < c; k++){ // MOD only if necessary
                    answ.mat[i][j] = (answ.mat[i][j] + mat[i][k] * other.mat[k][j]%MOD)%MOD;
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
    while(y){
        if(y & 1) answ = answ * x;
        x = x * x;
        y = y >> 1;
    }
    return answ;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;

    vector<int> base(7);
    base[0] = 1;
    base[1] = 1;
    base[2] = 2;
    base[3] = 4;
    base[4] = 8;
    base[5] = 16;
    base[6] = 32;

    if(n <= 6){
        cout << base[n] << '\n';
    }
    else{
        vector<vector<int>> m = { {1, 1, 1, 1, 1, 1},
                                  {1, 0, 0, 0, 0, 0},
                                  {0, 1, 0, 0, 0, 0},
                                  {0, 0, 1, 0, 0, 0},
                                  {0, 0, 0, 1, 0, 0},
                                  {0, 0, 0, 0, 1, 0}};
        Matrix aux(m, 6, 6);
        Matrix answ = fexpo(aux, n - 6);
        
        int resp = 0;
        for(int i = 0; i < 6; i++){
            resp += answ[0][i] * base[6 - i] % MOD;
            resp %= MOD;
        }
        cout << resp << '\n';
    }
    
    return 0;
}