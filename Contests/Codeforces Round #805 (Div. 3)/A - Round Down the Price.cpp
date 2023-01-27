//  A - Round Down the Price
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18; 
 
int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
 
    while(t--){
 
        int m;
        cin >> m;
        int answ = LONG_LONG_MAX;
        for(int factor = 1; factor <= m; factor*=10){
            answ = min(answ, m-factor);
        }
 
        cout << answ << '\n';
    }
    return 0;
}