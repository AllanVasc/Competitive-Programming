#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

struct Mat{
    vector<vector<int>> mat;
    int r, c;
    Mat(int r, int c) : r(r), c(c) {
        mat.assign(r, vector<int>(c, 0));
    }
    Mat(vector<vector<int>>& other){
        r = other.size();
        c = other[0].size();
        mat.assign(r, vector<int>(c, 0));
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                mat[i][j] = other[i][j];
            }
        }
    }
    Mat operator *(Mat& other){
        Mat aux(r, other.c);
        for(int i = 0; i < r; i++){
            for(int j = 0; j < other.c; j++){
                for(int k = 0; k < c; k++){
                    aux.mat[i][j] += mat[i][k] * other.mat[k][j] % MOD;
                    aux.mat[i][j] %= MOD;
                }
            }
        }
        return aux;
    }
};

Mat fexp(Mat a, int y){
    Mat answ(a.r, a.c);
    for(int i = 0; i < answ.r; i++) answ.mat[i][i] = 1;
    while(y){
        if(y & 1) answ = answ * a;
        a = a * a;
        y >>= 1;
    }
    return answ;
}

int fexp(int x, int y){
    int answ = 1;
    while(y){
        if(y & 1) answ = answ * x % MOD;
        x = x * x % MOD;
        y >>= 1;
    }
    return answ;
}

int32_t main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0), cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<vector<int>> v(n, vector<int>(n, 0));
    int inv = fexp(1000000, MOD - 2);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> v[i][j];
            v[i][j] *= inv;
            v[i][j] %= MOD;
        }
    }

    Mat prob(v);
    Mat probK = fexp(prob, k);
    int answ = 0;
    for(int i = 0; i < n; i++){
        answ += (i + 1) * probK.mat[0][i];
        answ %= MOD;
    }
    cout << answ << '\n';
    return 0;
}