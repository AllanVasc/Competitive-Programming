// A - Arithmetic Array
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
int main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int qtdCasos;

    cin >> qtdCasos;

    while(qtdCasos--){

        int n;
        cin >> n;

        ll sum = 0;

        for(int i = 0; i < n; i++){
            int aux;
            cin >> aux;
            sum += aux;
        }

        if (sum < n){
            cout << 1 << '\n';
        }
        else{
            cout <<  abs(sum - n) << '\n';
        }
        
    }


    return 0;
}
 
/*

*/