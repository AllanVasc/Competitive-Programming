#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<vector<int>> mat(n, vector<int>(n, 0));
        int first = 1;
        int last = n * n;
        for(int i = 0; i < n; i++){
            if(i % 2 == 0){
                for(int j = 0; j < n; j++){
                    if(j % 2 == 0){
                        mat[i][j] = last;
                        last--;
                    }
                    else{
                        mat[i][j] = first;
                        first++;
                    }
                }
            }
            else{
                for(int j = n - 1; j >= 0; j--){
                    if(j % 2 == 1){
                        mat[i][j] = last;
                        last--;
                    }
                    else{
                        mat[i][j] = first;
                        first++;
                    }
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << mat[i][j] << " ";
            }
            cout << '\n';
        }
    }
    return 0;
}