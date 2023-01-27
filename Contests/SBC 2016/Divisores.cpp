// 
#include <bits/stdc++.h>
using namespace std;
  
#define int long long
  
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18;

int MOD = 1e9;

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    vector<int> factorize;
    for(int i = 2; i*i <= c; i++){
        while(c % i == 0){
            factorize.push_back(i);
            // factorize.push_back(c/i);
            c = c/i;
        }
    }
    
    if(c != 1){
        factorize.push_back(c);
    }

    sort(factorize.begin(), factorize.end());

    // cout << "divisores: ";
    // for(int i = 0; i < factorize.size(); i++){
    //     cout << factorize[i] << " ";
    // }
    // cout << '\n';

    int answ = LONG_LONG_MAX;

    for(int i = 0; i < factorize.size(); i++){
        int aux = 1;
        for(int j = i; j < factorize.size(); j++){
            aux *= factorize[j];
            if(aux % a == 0 && aux % b != 0 && d % aux != 0){
                answ = min(answ, aux);
            }
        }
    }

    if(answ == LONG_LONG_MAX){
        cout << -1 << '\n';
    }
    else{
        cout << answ << '\n';
    }
    return 0;
}