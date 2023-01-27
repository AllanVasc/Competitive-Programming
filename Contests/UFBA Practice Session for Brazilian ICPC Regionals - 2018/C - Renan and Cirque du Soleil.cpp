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

int fastModExp(int x, int y, int p){
    int ans = 1;
    x = x % p;      // Update 'x' if it is more than or equal to 'p'
    if (x == 0) return 0;   // In case 'x' is divisible by 'p';
    while(y){ // We walk through the bits of power "y"
        if (y & 1) ans = (ans*x) % p; // If the least significant bit is set, we multiply the answer by "x"
        y = y >> 1; // We walk to the next bit
        x = (x*x) % p;
    }
    return ans;
}

int32_t main(){ 
  
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    // vector<int> pot2;
    // pot2.assign(60,1);
    // for(int i = 1; i < 60; i++){
    //     pot2[i] = 2*pot2[i-1]%MOD;
    // }

    while(t--){
        int n;
        cin >> n;

        // int somatorio1 = 0;
        // int somatorio2 = 0;

        // for(int i = 1, j = n - i; i <= n; i++, j--){
        //     somatorio1 += ((pot2[i-1])*i)%MOD;
        //     somatorio2 += ((pot2[j])*i)%MOD;
        // }

        // cout << "brute sum1 = " << somatorio1 << '\n';
        // cout << "brute sum2 = " << somatorio2 << '\n';

        vector<vector<int>> v;
        v.assign(3, vector<int>(3, 0));
        v[0][0] = 2;
        v[0][1] = 2;
        v[1][1] = 2;
        v[2][0] = 2;
        v[2][1] = 2; 
        v[2][2] = 1;
        Matrix<int> mat1(v, 3, 3);
        
        v[0][0] = 500000004;
        v[0][1] = 500000004;    // inverso modular (1/2)
        v[1][1] = 500000004;    // Inverso modular (1/2)
        v[2][0] = 500000004;    // Sum
        v[2][1] = 500000004;    // Sum
        v[2][2] = 1;            // Sum
        Matrix<int> mat2(v, 3, 3);

        mat1 = fexpo(mat1, n-1);
        mat2 = fexpo(mat2, n-1);

        // cout << "MAT2 = " << '\n';
        // for(int i = 0; i < 3; i ++){
        //     for(int j = 0; j < 3; j++){
        //         cout << mat2[i][j] << " "; 
        //     }
        //     cout << '\n';
        // }

        int base1 = 1;
        int base2 = fastModExp(2, n-1, MOD);

        int answ1 = ((mat1[2][0]*base1%MOD + mat1[2][1]*base1%MOD)%MOD + mat1[2][2]*base1%MOD)%MOD;
        // cout << "primeiro somatorio = " << answ1 << '\n';

        int answ2 = ((mat2[2][0]*base2%MOD + mat2[2][1]*base2%MOD)%MOD + mat2[2][2]*base2%MOD)%MOD;
        // cout << "segundo somatorio = " << answ2 << '\n';

        int final = answ1 - answ2;
        cout << (final + MOD)%MOD << '\n';
    }
    return 0;
}