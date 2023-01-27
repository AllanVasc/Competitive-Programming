// 
#include <bits/stdc++.h>
using namespace std;
  
#define int long long
  
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m,x;
    cin >> n >> m >> x;

    int answ = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int check;
            cin >> check;
            if(__gcd(check,x) != 1) answ++;
        }
    }

    cout << answ << '\n';

    return 0;
}