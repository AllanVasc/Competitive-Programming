// A - Raiser Mais
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int inf = 0x3f3f3f3f;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;

int32_t main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int r,c;
    cin >> r >> c;

    vector<string> v;

    ii posO;

    for(int i = 0; i < r; i++){
        string s;
        cin >> s;
        v.push_back(s);
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(v[i][j] == 'O')  posO = {i,j};
        }
    }

    char dir;
    if(posO.first == 0) dir = 'D';
    else if (posO.first == r-1) dir = 'U';
    else if (posO.second == 0) dir = 'R';
    else if (posO.second == c-1) dir = 'L';

    ii posAtual = posO;
    
    int ctn = 1;

    while(ctn){

        if(dir == 'D'){
            int j = posAtual.second;
            for(int i = posAtual.first + 1; i < r; i++){
                if(v[i][j] == '.') v[i][j] = '@';
                else if (v[i][j] == '/'){
                    dir = 'L';
                    posAtual = {i,j};
                    break;
                }
                else if(v[i][j] == '\\'){
                    dir = 'R';
                    posAtual = {i,j};
                    break;
                }
                else if(v[i][j] == '#'){
                    ctn = 0;
                    break;
                }
            }
        }

        if(dir == 'U'){
            int j = posAtual.second;
            for(int i = posAtual.first - 1; i >= 0; i--){
                if(v[i][j] == '.') v[i][j] = '@';
                else if (v[i][j] == '/'){
                    dir = 'R';
                    posAtual = {i,j};
                    break;
                }
                else if(v[i][j] == '\\'){
                    dir = 'L';
                    posAtual = {i,j};
                    break;
                }
                else if(v[i][j] == '#'){
                    ctn = 0;
                    break;
                }
            }
        }

        if(dir == 'R'){
            int i = posAtual.first;
            for(int j = posAtual.second + 1; j < c; j++){
                if(v[i][j] == '.') v[i][j] = '@';
                else if (v[i][j] == '/'){
                    dir = 'U';
                    posAtual = {i,j};
                    break;
                }
                else if(v[i][j] == '\\'){
                    dir = 'D';
                    posAtual = {i,j};
                    break;
                }
                else if(v[i][j] == '#'){
                    ctn = 0;
                    break;
                }
            }
        }

        if(dir == 'L'){
            int i = posAtual.first;
            for(int j = posAtual.second - 1; j >= 0 ; j--){
                if(v[i][j] == '.') v[i][j] = '@';
                else if (v[i][j] == '/'){
                    dir = 'D';
                    posAtual = {i,j};
                    break;
                }
                else if(v[i][j] == '\\'){
                    dir = 'U';
                    posAtual = {i,j};
                    break;
                }
                else if(v[i][j] == '#'){
                    ctn = 0;
                    break;
                }
            }
        }

    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cout << v[i][j];
        }
        cout << "\n";
    }


    return 0;
}
