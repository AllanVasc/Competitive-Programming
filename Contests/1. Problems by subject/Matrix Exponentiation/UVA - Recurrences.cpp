// 
#include <bits/stdc++.h>
using namespace std;
  
#define int long long
  
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18;

int MOD;

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
                for(int k = 0; k < c; k++){
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

Matrix<int> fastModExp(Matrix<int>& x, int y, int p){
    Matrix<int> ans(x.r, x.c);
    for(int i = 0; i < x.r; i++){
        for(int j = 0; j < x.c; j++){
            if(i == j) ans.mat[i][j] = 1;
        }
    }

    while(y){
        if (y & 1) ans = (ans*x);
        y = y >> 1;
        x = (x*x);
    }
    return ans;
}

int32_t main(){
  
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    

    int d, n, m;
    while(cin >> d >> n >> m){
        if(d == 0 && n == 0 && m == 0) break;

        vector<int> coef(d, 0);
        for(int i = 0; i < d; i++) cin >> coef[i];
        
        vector<int> base(d, 0);
        for(int i = 0; i < d; i++) cin >> base[i];

        vector<vector<int>> aux;
        aux.assign(d, vector<int>(d, 0));

        for(int i = 0; i < d; i++){
            for(int j = 0; j < d; j++){
                if(i == 0) aux[i][j] = coef[j];
                else{
                    if(j == i-1) aux[i][j] = 1;
                }
            }
        }

        MOD = m;
        
        Matrix<int> mat(aux, d, d);
        if(n <= d){
            cout << base[n-1] << '\n';
        }
        else{
            
            Matrix<int> M = fastModExp(mat, n-d, MOD);
            Matrix<int> A(d, 1);
            for(int i = 0; i < d; i++){
                for(int j = 0; j < 1; j++){
                    A.mat[i][j] = base[d-1-i] % MOD;
                }
            }
            
            cout << (M*A)[0][0] % MOD << '\n';
        }
    }
    return 0;
}