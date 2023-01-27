// A - Food for Animals
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int t;
    cin >> t;
 
    while(t--){
        
        ll a,b,c,x,y;

        cin >> a >> b >> c >> x >> y;

        x = x - a;
        y = y - b; 

        ll rest = 0;

        if(x > 0) rest += x;
        if(y > 0) rest += y;

        if(rest <= c) cout << "YES" << '\n';
        else cout << "NO" << '\n';

    }
 
    return 0;
}
