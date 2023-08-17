#include <bits/stdc++.h>

using namespace std;
#define int long long

int f(int x){
    if(x <= -3)
        return 8 - (x+4)*(x+4);
    
    if(x <= 2)
        return 1 - 2*x;
    
    return x*x*x - 14 * x + 17;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x;
    cin >> x;

    cout << f(x) << "\n";

    return 0;
}