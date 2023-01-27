// G - Fall Down
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
 
        int n, m;
        cin >> n >> m;
        vector<string> mapa;
 
        for(int i = 0; i < n; i ++){
            string aux;
            cin >> aux;
            mapa.push_back(aux);
        }
 
        vector<pair<int,int>> stones_loc;
    
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
 
                if(mapa[i][j] == '*'){
                    stones_loc.push_back({i,j});
                }
            }
        }
 
        // cout << "qtd pedras = " << stones_loc.size() << '\n';
 
        bool possible = true;
        
        while(possible){
            possible = false;
            for(int i = stones_loc.size() - 1; i >= 0; i--){
                pair<int,int> stone = stones_loc[i];
                if(stone.first + 1 < n){
                    
                    if(mapa[stone.first+1][stone.second] == '.'){
                        mapa[stone.first][stone.second] = '.';
                        mapa[stone.first+1][stone.second] = '*';
                        stones_loc[i] = {stone.first+1, stone.second};
                        possible = true;
                    }
                }
            }
        }
        
 
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << mapa[i][j];
            }
            cout << '\n';
        }
 
        //cout << '\n';
    }
 
    return 0;
}