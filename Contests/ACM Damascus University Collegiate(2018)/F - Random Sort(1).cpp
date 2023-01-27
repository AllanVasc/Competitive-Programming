// F - Random Sort
#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;

const int MOD1 = 7901;

int main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<ll> fact(1010);

    fact[0] = 1;
    fact[1] = 1;

    for(int i = 2; i <= 1001; i++){
        fact[i] = (i*fact[i-1]) %MOD1;
    }

    int qtdCasos;
    
    cin >> qtdCasos;

    while(qtdCasos--){

        int n;
        cin >> n;
        
        map<int,int> frequency;

        for(int i = 0; i < n; i++){
            int aux;
            cin >> aux;
            frequency[aux]++;
        }

        ll answer = 1;

        for(auto itr : frequency){
            answer = (answer*fact[itr.second]) % MOD1;
        }

        cout << answer << '\n';
    }
    return 0;
}
 
/*
 
1 3 3 3 4 4 4

= 1! * 3! * 3!
= 1 * 3*2*1 * 3*2*1
 
*/