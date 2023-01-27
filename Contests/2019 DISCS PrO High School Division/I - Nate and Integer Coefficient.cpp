// 
#include <bits/stdc++.h>
using namespace std;
  
#define int long long
  
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
                for(int k = 0; k < c; k++){
                    answ.mat[i][j] = (answ.mat[i][j]%MOD + ((mat[i][k] * other.mat[k][j]%MOD)+MOD)%MOD)%MOD;
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
    
    int t;
    cin >> t;

    while(t--){
        int a, n;
        cin >> a >> n;
        
        a = a % MOD;

        vector<vector<int>> v = { { {a}, {-1}},
                                { {1}, {0} } };

        vector<int> base = {2, a};

        n = abs(n);

        if(n == 0 || n == 1){
            cout << base[n] << '\n';
        }
        else{
            Matrix<int> mat(v, 2, 2);

            Matrix<int> answ = fexpo(mat, n-1);

            cout << ( ( ((answ[0][0]*base[1]%MOD)+MOD)%MOD + ((answ[0][1]*base[0]%MOD)+MOD)%MOD ) + MOD)%MOD << '\n';
        }
    }

    return 0;
}