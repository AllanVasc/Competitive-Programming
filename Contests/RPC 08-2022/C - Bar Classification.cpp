// 
#include <bits/stdc++.h>
using namespace std;
  
#define int long long
  
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18;
const int MOD = 1e9 + 7;

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<string> v(n);
    int total_ones = 0;

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(v[i][j] - '0')total_ones++;
        }
    }

    int best_row, qtd_row = 0;

    for(int i = 0; i < n; i++){
        int count = 0;
        for(int j = 0; j < n; j++){
            if(v[i][j] - '0') count++;
        }
        if(count > qtd_row){
            qtd_row = count;
            best_row = i;
        }
    }

    int best_column, qtd_column = 0;

    for(int i = 0; i < n; i++){
        int count = 0;
        for(int j = 0; j < n; j++){
            if(v[j][i] - '0') count++;
        }
        if(count > qtd_column){
            qtd_column = count;
            best_column = i;
        }
    }

    // cerr << "Best row = " << best_row << " qtd ones = " << qtd_row << '\n';
    // cerr << "Best column = " << best_column << " qtd ones = " << qtd_column << '\n';

    bool can_row = false;
    bool can_column = false;
    if(total_ones - qtd_row + (n-qtd_row) <= n) can_row = true;
    if(total_ones - qtd_column + (n-qtd_column) <= n) can_column = true;

    if(can_row && can_column) cout << "+" << '\n';
    else if(can_row) cout << "-" << '\n';
    else if(can_column) cout << "|" << '\n';

    return 0;
}