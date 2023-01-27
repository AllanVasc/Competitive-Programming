// B - Vlad and Candies
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
        
        ll n;
        vector<ll> v;
        
        cin >> n;

        for(int i = 0; i < n; i++){
            ll aux;
            cin >> aux;
            v.push_back(aux);
        }

        sort(v.begin(), v.end());

        if(n == 1){
            if(v[0] == 1){
                cout << "YES" << '\n';
            }
            else{
                cout << "NO" << '\n';
            }
        }
        else{

            if( (n == 1 && v[0] == 1) || v[n-2] == v[n-1] || v[n-2] + 1 == v[n-1]){
            cout << "YES" << '\n';
            }
            else{
                cout << "NO" << '\n';
            }
        }
    }

    return 0;
}