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
    Matrix<int> ans(2, 2);
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
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
    
    vector<int> power2(30,1);
    for(int i = 1; i < 30; i++){
        power2[i] = power2[i-1] * 2;
    }

    int n, m;
    while(cin >> n >> m){
        MOD = power2[m];
        vector<vector<int>> v = { {1,1}, {1,0} };
        Matrix<int> m(v, 2, 2);
        if(n == 0){
            cout << 0 << '\n';
        }
        else if(n == 1){
            cout << 1 << '\n';
        }
        else{
            Matrix<int> result = fastModExp(m,n-1,MOD);
            cout << result[0][0] % MOD << '\n';
        }
    }
    return 0;
}