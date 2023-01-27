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

    int t;
    cin >> t;

    while(t--){
        int a, b, c;
        cin >> a >> b >> c;

        int answ1 = abs(a - 1);
        int answ2 = abs(b - c) + abs(c - 1);

        if(answ1 == answ2){
            cout << 3 << '\n';
        }
        else if(answ1 < answ2){
            cout << 1 << '\n';
        }
        else{
            cout << 2 << '\n';
        }
    }
    return 0;
}