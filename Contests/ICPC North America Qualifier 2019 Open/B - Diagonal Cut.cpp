// 
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int INF = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;

int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int m, n;
    cin >> m >> n;

    if(m/__gcd(m,n)%2 == 0 || n/__gcd(m,n)%2 == 0) cout << 0 << '\n';
    else cout << __gcd(m,n) << '\n';

    return 0;
}
