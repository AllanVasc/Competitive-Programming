#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, k;

    cin >> n >> k;

    vector<vector<int> > mat(2*n + 10, vector<int> (2*n + 10, -1));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> mat[i][j];
        }
    }
    int ans =0;
    for(int x = 0; x<=9; x++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int a, b, c, d;
                a = mat[i][j];
                b = mat[i + k -1][j];
                c = mat[i + k - 1][j + k - 1];
                d = mat[i][j + k - 1];

                if(a == x && b == x && c == x && d == x) ans++;
            }
        }
    }

    cout << ans << '\n';
}