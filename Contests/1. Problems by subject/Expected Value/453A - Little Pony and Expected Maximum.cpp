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
    
    long double ev = 0;
    long double curr = 0;
    long double prev = 0;
    for(int i = 1; i <= m; i++){
        curr = pow(i/(double)m, (double)n);
        ev += (curr - prev)*i;
        prev = curr;
    }

    cout << fixed << setprecision(6);
    cout << ev << '\n';

    return 0;
}
