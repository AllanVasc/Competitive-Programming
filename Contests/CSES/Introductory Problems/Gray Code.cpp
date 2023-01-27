#include <bits/stdc++.h>
using namespace std;
  
#define int long long
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
 
vector<string> solve(int n){
    if(n == 1){
        vector<string> answ = { "0", "1"};
        return answ;
    }
    else{
        vector<string> aux = solve(n-1);
 
        vector<string> answ;
        for(int i = 0; i < aux.size(); i++){
            answ.push_back('0' + aux[i]);
        }
        for(int i = aux.size() - 1; i >= 0; i--){
            answ.push_back('1' + aux[i]);
        }
 
        return answ;
    }
}
 
int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n;
    cin >> n;
 
    vector<string> answ = solve(n);
    for(int i = 0; i < answ.size(); i++){
        cout << answ[i] << '\n';
    }
 
    return 0;
}