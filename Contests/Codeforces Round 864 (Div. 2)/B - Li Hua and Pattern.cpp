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
        int n, k;
        cin >> n >> k;
        vector<vector<int>> mat(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        
        vector<vector<int>> rotate;
        for(int i = n - 1; i >= 0; i--){
            vector<int> aux;
            for(int j = n - 1; j >= 0; j--){
                aux.push_back(mat[i][j]);
            }
            rotate.push_back(aux);
        }
        int diff = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] != rotate[i][j]) diff++;
            }
        }
        diff /= 2;
        // cout << "diff = " << diff << '\n';
        if(n % 2 == 1){
            if(k >= diff) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
        else{
            if(k < diff || ((k - diff) % 2)) cout << "NO" << '\n';
            else cout << "YES" << '\n';
        }
    }
    return 0;
}