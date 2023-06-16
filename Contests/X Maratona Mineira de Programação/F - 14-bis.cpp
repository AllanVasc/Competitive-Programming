#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int mat[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }

    int ans1 = 1, ans2 = 1, aux = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(j){
                if(abs(mat[i][j] - mat[i][j-1]) <= 1){
                    aux++;
                    continue;
                }
            }

            ans1 = max(ans1, aux);
            aux = 1;
        }
        ans1 = max(ans1, aux);
    }

    for(int j = 0; j < m; j++){
        for(int i = 0; i < n; i++){
            if(i){
                if(abs(mat[i][j] - mat[i-1][j]) <= 1){
                    aux++;
                    continue;
                }
            }

            ans2 = max(ans2, aux);
            aux = 1;
        }
        ans2 = max(ans2, aux);
    }

    cout << max(ans1, ans2) << "\n";
}