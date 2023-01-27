// A - Martadella Strikes Again
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

long double pi = 2*acos(0.0);

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;

    double rzao, rzinho;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> rzao >> rzinho;

        if(pi*rzao*rzao > 2*pi*rzinho*rzinho){
            cout << 1 << '\n';
        }
        else{
            cout << 2 << '\n';
        }
    }

    return 0;
}

/*

*/