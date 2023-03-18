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

    freopen("wigz.in", "r", stdin);
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> mat;
        mat.assign(n, vector<int>(m, 0));
        for(int i = 0; i< n; i++)
            for(int j = 0; j < m; j++) cin >> mat[i][j];
        if(m < n){
            vector<vector<int>> aux;
            aux.assign(m, vector<int>(n, 0));
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    aux[i][j] = mat[j][i];
                }
            }
            mat = aux;
            swap(n, m);
        }
        vector<int> sumRow, sumCol;
        sumRow.assign(n, 0);
        sumCol.assign(m, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                sumRow[i] += mat[i][j];
                sumCol[j] += mat[i][j];
            }
        }

        int answ = 0;
        for(int mask = 0; mask < (1 << n); mask++){
            if(__builtin_popcount(mask) > k) continue;
            int cur = 0;
            vector<int> aux = sumCol;
            for(int i = 0; i < n; i++){
                if(mask & (1 << i)){
                    cur += sumRow[i];
                    for(int j = 0; j < m; j++){
                        aux[j] -= mat[i][j];
                    }
                }
            }
            int miss = k - __builtin_popcount(mask);
            sort(aux.begin(), aux.end());
            for(int j = m -1; j >= 0 && miss; j--, miss--){
                cur += aux[j];
            }
            answ = max(answ, cur);
        }
        cout << answ << '\n';
    }
    return 0;
}