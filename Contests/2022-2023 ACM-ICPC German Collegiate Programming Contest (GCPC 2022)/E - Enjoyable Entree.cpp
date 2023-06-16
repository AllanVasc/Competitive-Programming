#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define optimize ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define iii tuple<int,int,int>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

template<typename T = int>
struct Matrix{
    int r, c;
    vector<vector<T>> mat;

    Matrix(int r, int c): r(r), c(c){
        mat.assign(r, vector<T>(c, 0.0));
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
                    answ.mat[i][j] = answ.mat[i][j] + mat[i][k] * other.mat[k][j];
                }
            }
        }
        return answ;
    }

    vector<T> operator [](int r){
        return mat[r];
    }
};

Matrix<double> fexp(Matrix<double> mat, int y){
    Matrix<double> answ(2, 2);
    for(int i = 0; i < 2; i++) answ.mat[i][i] = 1.0;
    while(y){
        if(y & 1) answ = answ * mat;
        mat = mat * mat;
        y >>= 1;
    }
    return answ;
}

int32_t main() {
    optimize;
    
    int n;
    cin >> n;
    double piBase[2], talBase[2];
    piBase[0] = 100.0;
    piBase[1] = 0;
    talBase[0] = 0;
    talBase[1] = 100.0;

    cout << fixed << setprecision(8);
    if(n <= 2){
        cout << piBase[n - 1] << " " << talBase[n - 1] << '\n';
    }
    else if(n >= 500){
        cout << 33.33333333 << " " << 66.66666667 << '\n';
    }
    else{
        vector<vector<double>> aux = {{0.5, 0.5}, {1.0, 0.0}};
        Matrix<double> m1(aux, 2, 2);
        Matrix<double> answ = fexp(m1, n - 2);

        double p1 = answ[0][0] * piBase[1] + answ[0][1] * piBase[0];
        // double p2 = answ[0][0] * talBase[1] + answ[0][1] * talBase[0];
        double p2 = 100.0 - p1;
        cout << p1 << " " << p2 << '\n';
    }
    return 0;
}