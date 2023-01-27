#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    cout << n << " ";
    while(n != 1){
        if(n % 2 == 0){
            n = n/2;
            cout << n << " ";
        }else{
            n = 3*n + 1;
            cout << n << " ";
        }
    }
    cout << '\n';
    return 0;
}