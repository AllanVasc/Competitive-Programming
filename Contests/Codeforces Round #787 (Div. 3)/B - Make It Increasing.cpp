// B - Make It Increasing
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
        cin >> n;

        vector<ll> v;
        for(int i = 0; i < n; i++){
            ll aux;
            cin >> aux;
            v.push_back(aux);
        }

        ll answ = 0;

        for(int i = n-2; i >= 0; i--){
            
            if(v[i] == v[i+1] && v[i] == 0){
                answ = -1;
                break;
            }
            else if(v[i] >= v[i+1]){
                answ++;
                v[i] = v[i]/2;
                i++;
            }
        }

        cout << answ << '\n';
    }
 
    return 0;
}
