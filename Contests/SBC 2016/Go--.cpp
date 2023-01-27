// 
#include <bits/stdc++.h>
using namespace std;
  
#define int long long

using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18;
const int MAXN = 510;
int n;
int dpW[MAXN][MAXN], dpB[MAXN][MAXN];
vector<vector<int>> mat;    

int solveB(int i, int j){
    if(i >= n || j >= n) return 0;
    if(dpB[i][j] != -1) return dpB[i][j];

    if(mat[i][j] == 1) return dpB[i][j] = 0;

    int answ = LONG_LONG_MAX;
    answ = min(answ, solveB(i+1,j) + 1);
    answ = min(answ, solveB(i, j+1) + 1);
    answ = min(answ, solveB(i+1, j+1) + 1);

    return dpB[i][j] = answ;
}

int solveW(int i, int j){
    if(i >= n || j >= n) return 0;
    if(dpW[i][j] != -1) return dpW[i][j];

    if(mat[i][j] == 2) return dpW[i][j] = 0;

    int answ = LONG_LONG_MAX;
    answ = min(answ, solveW(i+1,j) + 1);
    answ = min(answ, solveW(i, j+1) + 1);
    answ = min(answ, solveW(i+1, j+1) + 1);

    return dpW[i][j] = answ;
}

void build(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            dpW[i][j] = -1;
            dpB[i][j] = -1;
        }
    }
}

int32_t main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int p;
    cin >> n >> p;
    
    mat.assign(n, vector<int>(n, 0));

    for(int i = 0; i < p ; i ++){   // Pretas
        int r, c;
        cin >> r >> c;
        mat[r-1][c-1] = 1;
    }

    for(int i = 0; i < p ; i ++){   // Brancas
        int r, c;
        cin >> r >> c;
        mat[r-1][c-1] = 2;
    }
    
    build();
    solveB(0, 0);
    solveW(0, 0);

    int answW = 0, answB = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            answW += max((int)0, solveB(i,j) - solveW(i,j));
            answB += max((int)0, solveW(i,j) - solveB(i,j));
        }
    }

    cout << answB << " " << answW << '\n';
    return 0;
}