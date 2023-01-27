// B - Equal Candies
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

        int n;

        cin >>n;
        vector<ll> v;
        for(int i = 0; i < n; i++){
            ll aux;
            cin >> aux;
            v.push_back(aux);
        }

        sort(v.begin(), v.end());

        ll min = v[0];
        ll answ = 0;

        for(int i = 1; i < v.size(); i++){
            answ += (v[i] - min);
        }

        cout << answ << '\n';
    }
 
    return 0;
}
