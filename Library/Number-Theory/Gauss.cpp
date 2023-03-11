#include <bits/stdc++.h>
using namespace std;

#define int long long

const double eps = 1e-9;

// "a" is the system matrix. The last column of this matrix is vector b
// 0    -> 0 solutions
// 1    -> 1 solution
// 2    -> INF solutions
int gauss(vector<vector<double>> a, vector<double>& answ){
    int n = (int) a.size();         // # equations
    int m = (int) a[0].size() - 1;  // # variables

    vector<int> where(m, -1);
    for(int col = 0, row = 0; col < m && row < n; col++){
        int sel = row;
        for(int i = row; i < n; i++){
            if(abs(a[i][col]) > abs(a[sel][col])) sel = i;
        }
        if(abs(a[sel][col]) < eps) continue;
        for(int i = col; i <= m; i++){
            swap(a[sel][i], a[row][i]);
        }
        where[col] = row;

        for(int i = 0; i < n; i++){
            if(i != row){
                double c = a[i][col] / a[row][col];
                for(int j = col; j <= m; j++){
                    a[i][j] -= a[row][j] * c;
                }
            }
        }
        row++;
    }

    answ.assign(m, 0);
    for(int i = 0; i < m; i++){
        if(where[i] != -1)
            answ[i] = a[where[i]][m] / a[where[i]][i];
    }
    for(int i = 0; i < n; i++){
        double sum = 0;
        for(int j = 0; j < m; j++){
            sum += answ[j] * a[i][j];
        }
        if(abs(sum - a[i][m]) > eps) return 0;
    }
    for(int i = 0; i < m; i++){
        if(where[i] == -1) return 2;
    }
    return 1;
}


/*

Time Complexity:

gauss   -> O(n^3)

Links:

https://cp-algorithms.com/linear_algebra/linear-system-gauss.html
https://codeforces.com/blog/entry/60003

*/