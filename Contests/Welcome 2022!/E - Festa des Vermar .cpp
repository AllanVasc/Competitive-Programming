// E - Festa des Vermar 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<ll> v;

    ll total = 0;

    for(int i = 0; i < n; i++){
        ll aux;
        cin >> aux;
        total += aux;
        v.push_back(aux);
    }

    sort(v.begin(), v.end());

    ll answ = 0;

    for(int i = n-1; i >= 0; i-=2){
        answ += v[i];
    }

    cout << total - answ << '\n';

    return 0;
}
