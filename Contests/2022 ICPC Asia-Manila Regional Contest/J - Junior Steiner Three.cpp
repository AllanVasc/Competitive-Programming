#include <bits/stdc++.h>
using namespace std;


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int r, c;
    cin >> r >> c;
    vector<string> grid;
    for(int i = 0; i < r; i++){
        string s; cin >> s;
        grid.push_back(s);
    }
    vector<pair<int,int>> islands;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(grid[i][j] == '#'){
                islands.push_back({i, j});
            }
        }
    }
    sort(islands.rbegin(), islands.rend());
    // islands[0] eh o cara mais embaixo

    pair<int,int> embaixo = islands[0];
    pair<int,int> meio = islands[1];
    while(embaixo.first != meio.first){
        grid[embaixo.first - 1][embaixo.second] = '#';
        embaixo.first= embaixo.first - 1;
    }
    while(embaixo.second < meio.second){
        grid[embaixo.first][embaixo.second + 1] = '#';
        embaixo.second = embaixo.second + 1;
    }
    while(embaixo.second > meio.second){
        grid[embaixo.first][embaixo.second - 1] = '#';
        embaixo.second = embaixo.second - 1;
    }
    // conectado embaixo e meio
    embaixo = islands[0];
    pair<int,int> emcima = islands[2];
    if(emcima.second <= max(embaixo.second, meio.second) && emcima.second >= min(embaixo.second, meio.second)){
        // to no meio, eh so descer
        while(emcima.first < meio.first){
            grid[emcima.first + 1][emcima.second] = '#';
            emcima.first = emcima.first + 1;
        }
    }
    else{
        while(emcima.second > max(embaixo.second, meio.second)){
            grid[emcima.first][emcima.second - 1] = '#';
            emcima.second = emcima.second - 1;
        }
        while(emcima.second < min(embaixo.second, meio.second)){
            grid[emcima.first][emcima.second + 1] = '#';
            emcima.second = emcima.second + 1;
        }
        
        while(emcima.first < meio.first){
            grid[emcima.first + 1][emcima.second] = '#';
            emcima.first = emcima.first + 1;
        }

    }
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cout << grid[i][j];
        }
        cout << '\n';
    }
    return 0;
}