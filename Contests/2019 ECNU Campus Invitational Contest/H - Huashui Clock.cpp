// H. Huashui Clock
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll hora,minuto;
    cin >> hora >> minuto;

    ll answer = 0;

    if(hora >= minuto){

        ll a1 = minuto;
        ll an = a1 + (minuto-1)*(-1);
        ll somaPa = ((a1 + an)*minuto)/2;

        answer = somaPa;
    }
    else{

        ll a1 = minuto;
        ll an = a1 + (hora-1)*(-1);
        ll somaPa = ((a1 + an)*hora)/2;

        answer = somaPa;
    }

    ll totalHoras = hora*minuto;

    cout << answer/__gcd(answer,totalHoras) << "/" << totalHoras/__gcd(answer,totalHoras) << '\n';
    return 0;
}

/*


*/