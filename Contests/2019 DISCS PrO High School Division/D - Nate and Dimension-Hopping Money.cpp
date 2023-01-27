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

    double n, x, y;
    cin >> n >> x >> y;

    double n1 = ((10000)*n)/(10000.0 -100.0*y + x*y);
    double n2 = n1*(1 - x/100.0);

    // cout << n1 - n1*(x)/100.0 << '\n';
    
    cout << fixed << setprecision(5);
    cout << n << " ";
    cout << n + n2*y/100.0 << " ";
    cout << n1 - n1*x/100.0 << " ";
    cout << n2 - n2*y/100.0 << " ";
    cout << n2 - n2*y/100.0 << '\n';

    return 0;
}