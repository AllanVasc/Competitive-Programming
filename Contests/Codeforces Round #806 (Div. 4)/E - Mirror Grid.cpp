// E - Mirror Grid
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18;
 
int32_t main(){
 
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);
    
    int t;
    cin >> t;
 
    while(t--){
        int n;
        cin >> n;
        int ones = 0, zeros = 0;
 
        vector<vector<int>> v;
        v.assign(n, vector<int>());
 
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            for(int j = 0; j < n; j++){
                if(s[j] == '0'){
                    zeros++;
                    v[i].push_back(s[j] - '0');
                }
                else{
                    ones++;
                    v[i].push_back(s[j] - '0');
                }
            }
        }
        
        if(n == 1){
            cout << 0 << '\n';
        }
        else if(n%2 == 0){ // Matriz par
            // cout << min(zeros, ones) << '\n';
 
            int answ = 0;
            for(int i = 0,j = 0; i < n/2 && j < n/2; i++, j++){ // Diagonal
                int qtd_zeros = 0;
                int qtd_ones = 0;
 
                if(v[i][j] == 1) qtd_ones++;
                else qtd_zeros++;
 
                if(v[n-i-1][j]) qtd_ones++;
                else qtd_zeros++;
 
                if(v[i][n-j-1]) qtd_ones++;
                else qtd_zeros++;
 
                if(v[n-i-1][n-j-1]) qtd_ones++;
                else qtd_zeros++;
                //cout << "Top = " << v[i][j] << " Top Dir = " << v[i][n-j-1] << '\n';
                //cout << "Inf = " << v[n-i-1][j] << " Inf dir = " << v[n-i-1][n-j-1] << '\n';
                answ += min(4-qtd_ones,4 - qtd_zeros);
            }
            int count = 1;
            int mid = (n-2)/2;
 
            for(int i = 1; i < n-1; i++){ // Entre as diagonais
 
                for(int j = 0; j < count; j++){
                    int qtd_zeros = 0;
                    int qtd_ones = 0;
 
                    if(v[i][j] == 1) qtd_ones++;
                    else qtd_zeros++;
 
                    if(v[n-j-1][i]) qtd_ones++;
                    else qtd_zeros++;
 
                    if(v[n-i-1][n-j-1]) qtd_ones++;
                    else qtd_zeros++;
 
                    if(v[j][n-i-1]) qtd_ones++;
                    else qtd_zeros++;
 
                    answ += min(4-qtd_ones,4-qtd_zeros);
                }
 
                if(i == mid) continue;
                
                if(i < mid) count++;
                else count--;
            }
 
            cout << answ << '\n';
 
        }
        else{   // Matriz impar
            
            int answ = 0;
            for(int i = 0,j = 0; i < n/2 && j < n/2; i++, j++){ // Diagonal
                int qtd_zeros = 0;
                int qtd_ones = 0;
 
                if(v[i][j] == 1) qtd_ones++;
                else qtd_zeros++;
 
                if(v[n-i-1][j]) qtd_ones++;
                else qtd_zeros++;
 
                if(v[i][n-j-1]) qtd_ones++;
                else qtd_zeros++;
 
                if(v[n-i-1][n-j-1]) qtd_ones++;
                else qtd_zeros++;
                //cout << "Top = " << v[i][j] << " Top Dir = " << v[i][n-j-1] << '\n';
                //cout << "Inf = " << v[n-i-1][j] << " Inf dir = " << v[n-i-1][n-j-1] << '\n';
                answ += min(4-qtd_ones,4 - qtd_zeros);
            }
 
            //cout << "DIAGONAIS = " << answ << '\n';
 
            int count = 1;
            int mid = (n-2)/2 + 1;
 
            for(int i = 1; i < n-1; i++){ // Entre as diagonais
 
                for(int j = 0; j < count; j++){
                    int qtd_zeros = 0;
                    int qtd_ones = 0;
 
                    if(v[i][j] == 1) qtd_ones++;
                    else qtd_zeros++;
 
                    if(v[n-j-1][i]) qtd_ones++;
                    else qtd_zeros++;
 
                    if(v[n-i-1][n-j-1]) qtd_ones++;
                    else qtd_zeros++;
 
                    if(v[j][n-i-1]) qtd_ones++;
                    else qtd_zeros++;
 
                    answ += min(4-qtd_ones,4-qtd_zeros);
                }
 
                if(i < mid) count++;
                else count--;
            }
 
            cout << answ << '\n';
        
        }
 
    }
 
    return 0;
}