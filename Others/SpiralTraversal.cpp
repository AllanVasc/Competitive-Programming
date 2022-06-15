#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> answ;

// Spiral Traversal (m = number of rows && n = number of columns)
// "v" is our matrix
void SpiralTraversal(int m, int n){

    int i, k = 0, l = 0;
 
    /* 
        k - starting row index
        m - ending row index    (exclusive)
        l - starting column index
        n - ending column index (exclusive)
        i - iterator
    */
 
    while (k < m && l < n) {

        // Left to right
        for (i = l; i < n; ++i) {
            answ.push_back(v[k][i]);
        }
        k++;
 
        // From top to bottom
        for (i = k; i < m; ++i) {
            answ.push_back(v[i][n-1]);
        }
        n--;
 
        // Right to Left
        if (k < m) {
            for (i = n - 1; i >= l; --i) {
                answ.push_back(v[m-1][i]);
            }
            m--;
        }
 
        // From bottom to top
        if (l < n) {
            for (i = m - 1; i >= k; --i) {
                answ.push_back(v[i][l]);
            }
            l++;
        }
    }
}

/*

Time Complexity

SpiralTraversal -> O(m*n)

Links:

https://www.geeksforgeeks.org/print-a-given-matrix-in-spiral-form/

*/
