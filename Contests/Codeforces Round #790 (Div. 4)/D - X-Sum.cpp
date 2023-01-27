// D - X-Sum
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int t;
    cin >> t;
 
    while(t--){
        
        int n,m;

        cin >> n >> m;
        vector<vector<ll>> v;

        for(int i = 0; i < n; i++){
            vector<ll> aux;
            for(int j = 0; j < m; j++){
                ll aux1;
                cin >> aux1;
                aux.push_back(aux1);
            }
            v.push_back(aux);
        }

        ll answ = 0;

        for(int i = 0; i < n; i++){

            for(int j = 0; j < m; j++){

                ll sum = v[i][j];

                for(int x = j+1, y = i-1; x < m && y >= 0; x++, y--){ // Sup dir
                    sum += v[y][x];
                }

                for(int x = j-1, y = i-1; x >= 0 && y >= 0; x--, y--){ // Sup esq
                    sum += v[y][x];
                }

                for(int x = j+1, y = i+1; x < m && y < n; x++, y++){ // Inf dir
                    sum += v[y][x];
                }

                for(int x = j-1, y = i+1; x >= 0 && y < n; x--, y++){ // Inf esq
                    sum += v[y][x];
                }

                answ = max(answ, sum);
            }
        }

        cout << answ << '\n';
    }
 
    return 0;
}
