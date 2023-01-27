// D - Blue-Red Permutation
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--){

        vector<ll> v;
        vector<char> l;
        vector<pair<char,ll>> pares;

        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            ll aux;
            cin >> aux;
            v.push_back(aux);
        }
        for(int i = 0; i < n; i++){
            char aux;
            cin >> aux;
            l.push_back(aux);
        }
        for(int i = 0; i < n; i++){
            pares.push_back({l[i],v[i]});
        }
        sort(pares.begin(), pares.end());

        int t = 1;

        bool answer = true;
        for(int i = 0; i < n; i++){
            if(pares[i].first == 'B'){
                if(pares[i].second >= t){
                    t++;
                }
                else{
                    answer = false;
                    break;
                }
            }
            else if(pares[i].first == 'R'){
                if(pares[i].second <= t){
                    t++;
                }
                else{
                    answer = false;
                    break;
                }
            }
        }

        if(answer){
            cout << "YES" << '\n';
        }
        else
            cout << "NO" << '\n';
    }
    return 0;
}