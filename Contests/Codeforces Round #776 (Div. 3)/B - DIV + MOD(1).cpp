// B - DIV + MOD
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;


int main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    ll t;
 
    cin >> t;
 
    while(t--){

        ll l,r,a;

        cin >> l >> r >> a;
        
        ll answ;
        if(r - r%a - 1 >= l) answ = max((r/a) + r%a, ((r - r%a - 1)/a) + a-1);
        else answ = (r/a) + r%a;
        cout << answ << '\n'; 
    }
 
    return 0;
}