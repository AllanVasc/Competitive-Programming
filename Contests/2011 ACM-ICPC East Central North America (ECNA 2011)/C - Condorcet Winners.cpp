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

    int b, c;
    int cnt = 1;
    while(cin >> b >> c){
        if(b == c && c == 0) break;
        cout << "Case " << cnt++ << ": ";
        vector<vector<int>> rank(b, vector<int>(c, 0));
        for(int i = 0; i < b; i++){
            vector<int> list(c);
            for(int j = 0; j < c; j++) cin >> list[j];
            reverse(list.begin(), list.end());
            for(int j = 0; j < c; j++){
                rank[i][list[j]] = j;
            }
        }

        int winner = -1;
        for(int i = 0; i < c; i++){
            bool possible = true;
            for(int j = 0; j < c; j++){
                if(i == j) continue;
                int wins = 0;
                for(int k = 0; k < b; k++){
                    if(rank[k][i] > rank[k][j]) wins++;
                }
                if(wins <= b / 2){
                    possible = false;
                    break;
                }
            }
            if(possible){
                winner = i;
                break;
            }
        }

        if(winner != -1){
            cout << winner << '\n';
        }
        else{
            cout << "No Condorcet winner" << '\n';
        }
    }
    return 0;
}