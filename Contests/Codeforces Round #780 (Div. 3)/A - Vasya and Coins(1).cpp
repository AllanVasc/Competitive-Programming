// A - Vasya and Coins
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

        ll a,b;

        cin >> a >> b;

        if(a == 0){
            cout << 1 << '\n';
        }
        else {
            cout << (a + 2*b + 1) << '\n';
        }
        
    }

    return 0;
}