// B - Odd Grasshopper
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

        ll x, n;
        cin >> x >> n;

        ll passos = n %4;
        ll count = n/4;

        for(int i = 0; i < passos; i++){
            if(x & 1){
                x += count*4 + i+1;
            }
            else{
                x -= count*4 + i+1;
            }
        }

        cout << x << '\n';
    }
    return 0;
}