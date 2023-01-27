// 
#include <bits/stdc++.h>
using namespace std;
  
#define int long long
  
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18;

int MOD = 1e9;

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
  
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    

    int t;
    cin >> t;
    while(t--){

        int k;
        cin >> k;

        vector<int> base(k, 0);
        for(int i = 0; i < k; i++) cin >> base[i];

        vector<int> coef(k, 0);
        for(int i = 0; i < k; i++) cin >> coef[i];

        int n;
        cin >> n;

        vector<vector<int>> aux;
        aux.assign(k, vector<int>(k, 0));

        for(int i = 0; i < k; i++){
            for(int j = 0; j < k; j++){
                if(i == 0) aux[i][j] = coef[j];
                else{
                    if(j == i-1) aux[i][j] = 1;
                }
            }
        }

        Matrix<int> mat(aux, k, k);
        if(n <= k){
            cout << base[n-1] << '\n';
        }
        else{
            
            Matrix<int> M = fastModExp(mat, n-k, MOD);
            Matrix<int> A(k, 1);
            for(int i = 0; i < k; i++){
                for(int j = 0; j < 1; j++){
                    A.mat[i][j] = base[k-1-i] % MOD;
                }
            }
            
            cout << (M*A)[0][0] % MOD << '\n';
        }

    }
    return 0;
}