#include <bits/stdc++.h>
using namespace std;

using ii =  pair<int,int>;
const int MAXN = 105;
vector<vector<int>> grid;

const int INF = 1e8;
void build(){
    for(int i = 0; i < MAXN; i++){
        grid[0][i] = INF;
        grid[i][0] = INF;
        grid[i][i] = INF;
    }

    for(int i = 0; i < MAXN; i++){
        for(int j = 0; j < MAXN; j++){
            if(grid[i][j] != -1) continue;

            set<int> s;
            for(int k = j - 1; k >= 0; k--){
                s.insert(grid[i][k]);
            }
            for(int k = i - 1; k >= 0; k--){
                s.insert(grid[k][j]);
            }
            for(int k = i - 1, l = j - 1; k >= 0 && l >= 0; k--, l--){
                s.insert(grid[k][l]);
            }

            int cnt = 0;
            while(s.count(cnt) != 0) cnt++;
            grid[i][j] = cnt;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<ii> marbles;
    for(int i = 0; i < n; i++){
        int l, c;
        cin >> l >> c;
        marbles.push_back({l, c});
    }  
    grid.assign(MAXN, vector<int>(MAXN, -1));
    build();

    int answ = 0;
    for(int i = 0; i < n; i++){
        auto [r, c] = marbles[i];
        answ ^= grid[r][c];
    }

    if(answ == 0){
        cout << "N" << '\n';
    }
    else{
        cout << "Y" << '\n';
    }

    return 0;
}