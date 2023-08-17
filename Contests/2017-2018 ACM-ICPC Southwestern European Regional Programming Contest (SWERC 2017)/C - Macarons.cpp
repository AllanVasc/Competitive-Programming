#include <bits/stdc++.h>
using namespace std;

#define int long long
#define optimize ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define iii tuple<int,int,int>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9;

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
    Matrix answ(a.r, a.c);
    for(int i = 0; i < answ.r; i++){
        for(int j = 0; j < answ.c; j++){
            if(i == j) answ.mat[i][j] = 1;
        }
    }
    while(y){
        if(y & 1) answ = answ * a;
        a = a * a;
        y >>= 1;
    }
    return answ;
}

signed main() {
    optimize;

    vector<int> fib(10);
    fib[0] = fib[1] = 1;
    for(int i = 2; i < fib.size(); i++){
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    int n, m;
    cin >> n >> m;
    vector<int> masks(1 << n);
    for(int i = 0; i < (1 << n); i++) masks[i] = i;

    vector<vector<int>> mat((1 << n), vector<int>(1 << n, 0));
    for(int i = 0; i < mat.size(); i++){
        int curr_mask = masks[i];
        for(int j = 0; j < mat[i].size(); j++){
            int next_mask = masks[j];
            if((curr_mask & next_mask) != 0){
                mat[i][j] = 0;
                continue;
            }
            int new_mask = curr_mask ^ next_mask;
            int answ = 1;
            int cnt = 0;
            for(int k = 0; k < n; k++){
                if((new_mask & (1 << k)) == 0) cnt++;
                else{
                    answ *= fib[cnt];
                    cnt = 0;
                }
            }
            answ *= fib[cnt];
            mat[i][j] = answ;
        }
    }
    Matrix<int> matrix(mat, mat.size(), mat[0].size());
    Matrix<int> answ = fexp(matrix, m);
    cout << answ.mat[0][0] << '\n';
    
    return 0;
}