#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 998244353;

int filter(int m, int prev, int num){

    int c = prev/num;
    vector<int> useless_factors;
    if(c % 2 == 0){
        useless_factors.push_back(2);
        while(c % 2 == 0) c /= 2;
    }

    for(int i = 3; i*i <= c; i+=2){
        if(c % i == 0) useless_factors.push_back(i);
        while(c % i == 0) c /= i;
    }

    if(c > 1) useless_factors.push_back(c);

    int answ = m/num;

    for(int i = 1; i < (1 << useless_factors.size()); i++){ // Qtd de fatores distintos vai ser ~10
        int parity = __builtin_popcount(i) & 1;
        int currTerm = 1;
        for(int j = 0; j < useless_factors.size(); j++){
            if( (i >> j) & 1){
                currTerm *= useless_factors[j];
            }
        }

        if(parity) answ -= (m/num)/currTerm;
        else answ += (m/num)/currTerm;
    }

    return answ;
}

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;

        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];

        bool possible = true;
        for(int i = 1; i < n; i++){
            if(v[i-1] % v[i] != 0){ // Não é divisível
                possible = false;
            }
        }

        if(!possible){
            cout << 0 << '\n';
        }
        else{

            int answ = 1;

            for(int i = 1; i < n; i++){
                if(v[i-1] == v[i]){
                    answ *= (m/v[i]);
                    answ %= MOD;
                }
                else{ // inclusion / exclusion
                    answ *= filter(m, v[i-1], v[i]);
                    answ %= MOD;
                }
            }

            cout << answ << '\n';
        }
    }
    return 0;
}