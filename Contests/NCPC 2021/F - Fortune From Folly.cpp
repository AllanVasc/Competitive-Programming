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
                for(int k = 0; k < c; k++){ // MOD only if necessary
                    answ.mat[i][j] = (answ.mat[i][j] + mat[i][k] * other.mat[k][j]);
                }
            }
        }
        return answ;
    }

    vector<T> operator [](int r){
        return mat[r];
    }
};

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    double p;

    cin >> n >> k >> p;

    int transition = 1 << n;

    vector<vector<double>> v(transition, vector<double>(transition, 0));
    for(int mask = 0; mask < transition; mask++){
        if(__builtin_popcount(mask) >= k){
            continue;
        }
        else{
            int new_mask = (mask << 1) & ((1 << n) -1 );
            v[mask][new_mask] = (1-p);
            new_mask = new_mask | 1;
            if(__builtin_popcount(new_mask) != k)
                v[mask][new_mask] = p;
                
            v[mask][transition-1] = 1;
        }
    }

    v[transition-1][transition-1] = 1;

    Matrix<double> mat(v, transition, transition);

    // for(int i = 0; i < transition; i++){
    //     cout << i << " : ";
    //     for(int j = 0; j < transition; j++){
    //         cout << mat[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    for(int i = 0; i < 600; i++){
        mat = mat*mat;
    }

    // cout << "RESULTADO: " << '\n';
    // for(int i = 0; i < transition; i++){
    //     cout << i << " : ";
    //     for(int j = 0; j < transition; j++){
    //         cout << mat[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    cout << fixed << setprecision(10) <<  mat[0][transition-1] << '\n';
    return 0;
}