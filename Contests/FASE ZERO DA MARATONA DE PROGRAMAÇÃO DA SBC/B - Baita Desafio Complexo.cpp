// 
#include <bits/stdc++.h>
using namespace std;
  
#define int long long
  
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 9;

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

    int t, m;
    cin >> t >> m;

    vector<int> inputs;
    inputs.assign(m,0);
    for(int i = 0; i < m; i++) cin >> inputs[i];
    sort(inputs.begin(), inputs.end());

    vector<int> base = { {0}, {1} };

    vector<vector<int>> aux = { { {1}, {-t}, {0}},
                                { {1}, {0}, {0} },
                                { {1}, {-t}, {1}} };
    
    Matrix<int> x(aux, 3, 3);

    Matrix<int> answ = fexpo(x, inputs.back() - 1);

    int sum = ((answ[2][0]*base[1]%MOD + answ[2][1]*base[0]%MOD)%MOD + answ[2][2]*1%MOD)%MOD;
    
    // cout << "SUM = " << sum << '\n';

    for(int i = 0; i < m; i++){
        if(inputs[i] == 1){
            int result = 1;

            // cout << "F(1) = " << result << '\n';
            sum = (sum - result + MOD)%MOD;
        }
        else{
            answ = fexpo(x, inputs[i] - 1);
            int result = (answ[0][0]*base[1]%MOD + answ[0][1]*base[0]%MOD);

            // cout << "F(" << inputs[i] << ") = " << result << '\n';
            sum = (sum - result + MOD)%MOD;
        } 
    }

    cout << sum << '\n';

    return 0;
}