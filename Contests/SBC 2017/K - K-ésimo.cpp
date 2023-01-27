// 
#include <bits/stdc++.h>
using namespace std;
  
#define int long long
  
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e4;

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

Matrix<int> fexpo(Matrix<int>& x, int y){
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

    int a,b,n,k;
    cin >> a >> b >> n >> k;

    vector<int> base = { {2}, {2*a} };

    int z;

    if(n < 2){
        z = base[n];
    }
    else{
        vector<vector<int>> v;
        v.assign(2, vector<int>(2, 0));
        v[0][0] = 2*a;
        v[0][1] = b - a*a;
        v[1][0] = 1;
        v[1][1] = 0;
        Matrix<int> mat(v, 2, 2);

        mat = fexpo(mat, n-1);

        z = (mat[0][0]*base[1]%MOD + mat[0][1]*base[0]%MOD)%MOD;
    }

    // Tem que saber se é o Z ou Z-1
    if( (((a*a) != b) && ((n%2) == 0)) || ((a*a) > b)){
        z = (z-1 + MOD) % MOD;
    }

    // cout << "z = " << z << '\n';

    // só pegar o k-ésimo digito
    int answ;
    while(k){
        answ = z % 10;
        z = z/10;
        k--;
    }

    cout << answ << '\n';
    return 0;
}