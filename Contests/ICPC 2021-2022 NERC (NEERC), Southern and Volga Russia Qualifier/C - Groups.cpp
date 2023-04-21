#include<bits/stdc++.h>
using namespace std;

#define int long long
using ii = pair<int,int>;
const int INF = 1e18;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(5));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 5; j++){
            cin >> v[i][j];
        }
    }

    bool answ = false;
    for(int i = 0; i < 5; i++){
        for(int j = i + 1; j < 5; j++){
            
            int qtd00 = 0;
            int qtd10 = 0;
            int qtd11 = 0;
            int qtd01 = 0;

            for(int k = 0; k < n; k++){
                if(v[k][i] == 1 && v[k][j] == 0){
                    qtd10++;
                }
                else if(v[k][i] == 1 && v[k][j] == 1){
                    qtd11++;
                }
                else if(v[k][i] == 0 && v[k][j] == 1) qtd01++;
            }
            // cout << "i = " << i << " j = " << j << '\n';
            // cout << "qtdi10 " << qtdi10 << '\n';
            // cout << "qtdi11 " << qtdi11 << '\n';
            // cout << "qtdj1 " << qtdj1 << '\n';
            if(qtd10 + qtd11 >= n/2){
                int used = max(0LL, n/2 - qtd10);
                // cout << "i = " << i << " j = " << j << '\n';
                if(qtd01 + qtd11 - used >= n/2){
                    answ = true;
                }
            }
            // cout << "answ = " << answ << '\n';
        }
    }

    if(answ) cout << "YES" << '\n';
    else cout << "NO" << '\n';

    return 0;
}