// D - Grape Field 
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

vector<vector<int>> v;
vector<ll> answ;

void spiral(int m, int n){

    int i, k = 0, l = 0;
 
    /* k - starting row index
        m - ending row index
        l - starting column index
        n - ending column index
        i - iterator
    */
 
    while (k < m && l < n) {
        /* Print the first row from
               the remaining rows */
        for (i = l; i < n; ++i) {
            answ.push_back(v[k][i]);
        }
        k++;
 
        /* Print the last column
         from the remaining columns */
        for (i = k; i < m; ++i) {
            answ.push_back(v[i][n-1]);
        }
        n--;
 
        /* Print the last row from
                the remaining rows */
        if (k < m) {
            for (i = n - 1; i >= l; --i) {
                answ.push_back(v[m-1][i]);
            }
            m--;
        }
 
        /* Print the first column from
                   the remaining columns */
        if (l < n) {
            for (i = m - 1; i >= k; --i) {
                answ.push_back(v[i][l]);
            }
            l++;
        }
    }
}

int main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int r,c,k;
    cin >> r >> c >> k;

    for(int i = 0; i < r; i++){
        vector<int> row;
        for(int j=0; j < c; j++){
            int aux;
            cin >> aux;
            row.push_back(aux);
        }
        v.push_back(row);
    }

    spiral(r,c);

    ll sum = 0;

    for(int i = 0; i < answ.size(); i+=k){
        sum += answ[i];
    }

    cout << sum << '\n';

    return 0;
}
