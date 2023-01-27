// E - Eating Queries
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;


int main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    ll t;
 
    cin >> t;
 
    while(t--){

        int n, q;
        cin >> n >> q;
        vector<ll> v;
        
        for(int i = 0; i < n; i++){
            ll aux;
            cin >> aux;
            v.push_back(aux);
        }

        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());

        vector<ll> prefixSum(n+1);

        for(int i = 0; i < n; i++){
            prefixSum[i+1] += prefixSum[i] + v[i];
        }

        for(int i = 0; i < q; i++){
            ll qtd;
            cin >> qtd;
            vector<ll>:: iterator answ;

            answ = lower_bound(prefixSum.begin(), prefixSum.end(),qtd);

            if(answ == prefixSum.begin()) cout << "-1\n";
            else if(answ == prefixSum.end()) cout << "-1\n";
            else cout << answ - prefixSum.begin() << '\n';
        }
    }
 
    return 0;
}