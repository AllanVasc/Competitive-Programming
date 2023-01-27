#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int fexp(int x, int y){
    int answ = 1;
    x = x % MOD;
    while(y){
        if(y & 1) answ = answ*x %MOD;
        x = x*x % MOD;
        y >>= 1;
    }
    return answ;
}

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;

    while(t--){
        int y, x;
        cin >> y >> x;

        int curr_l = max(y,x);

        if(x <= y){
            if(y % 2 == 1){ // Aumentando
                int curr = (curr_l-1)*(curr_l-1);
                cout << curr + x << '\n';
            }
            else{
                int curr = curr_l*curr_l;
                cout << curr - x + 1 << '\n';
            }
        }
        else{
            if(x % 2 == 0){ // Aumentando
                int curr = (curr_l-1)*(curr_l-1);
                cout << curr + y << '\n';
            }
            else{
                 int curr = curr_l*curr_l;
                cout << curr - y + 1 << '\n';
            }
        }
    }
}