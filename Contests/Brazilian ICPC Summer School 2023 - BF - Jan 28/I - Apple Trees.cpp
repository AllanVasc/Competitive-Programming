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

Matrix<int> fexp(Matrix<int> a, int y){
    Matrix answ(a.mat.size(), a.mat[0].size());
    for(int i = 0; i < a.mat.size(); i++) answ.mat[i][i] = 1;
    while(y){
        if(y & 1) answ = answ * a;
        a = a * a;
        y >>= 1;
    }
    return answ;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;


    vector<vector<int>> v = { {16, 9, 4, 1, 0},
                              {1, 0, 0, 0, 0},
                              {0, 1, 0, 0, 0},
                              {0, 0, 1, 0, 0},
                              {0, 0, 0, 1, 0},
                            };

    Matrix a(v, 5, 5);
    int exp = n/ 10;
    Matrix mat1 = fexp(a, exp);

    vector<vector<int>> v2 = { {1},
                               {0},
                               {0},
                               {0},
                               {0},
                             };
    Matrix mat2(v2, 5, 1);
    Matrix answ = mat1 * mat2;
            
    
    int ans = 0;
    for(int i = 0; i < 5; i++){
        if(i == 4 && n % 10 >= 5) continue;
        ans += answ.mat[i][0];
        ans %= MOD;
    }
    
    cout << ans << '\n';

    return 0;
}