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

        int n,m;
        cin >> n >> m;

        int answ = 0;

        if(n == 1 && m == 1) cout << answ << '\n';
        else{
            answ += (n-1 + m-1);
            answ += 1 + min(n,m) - 1;
            cout << answ << '\n';
        } 
    }


    return 0;
}