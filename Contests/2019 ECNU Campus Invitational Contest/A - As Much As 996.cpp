// A. As Much As 996
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int s,t,d;
    char aux;

    cin >> aux;

    if(aux == '1'){
        cin >> aux;
        if(aux == '0'){
            s = 10;
        }
        else{
            s = 11;
        }
    }
    else{
        s = aux - '0';
    }

    cin >> aux;
    if(aux == '1'){
        cin >> aux;
        if(aux == '0'){
            t = 10;
        }
        else{
            t = 11;
        }
    }
    else{
        t = aux - '0';
    }

    cin >> aux;
    d = aux - '0';
    //cout << "s = " << s << " t = " << t << " d = " << d << '\n';
    cout << (12+(t) - s)*d << '\n';

    return 0;
}

/*
 
 
*/