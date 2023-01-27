// 
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int INF = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;

int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<long double> v;
    for(int i = 0; i < n; i++){
        long double aux;
        cin >> aux;
        v.push_back(aux);
    }
    sort(v.begin(), v.end(), greater<long double>());
    cout << fixed << setprecision(10);

    if(v[0] >= 1.0){
        cout << v[0] << '\n';
    }
    else{
        long double answ = 0;
        for(int i = 0; i < n; i++){ // qtd pessoas que peguei
            long double p = 1;
            long double curr = 0;

            for(int j = 0; j <= i; j++){
                p *= (1 - v[j]);
            }

            for(int j = 0; j <= i; j++){
                curr += (v[j]/(1-v[j]))*p;
            }
            answ = max(answ, curr);
        }
        cout << answ << '\n';
    }

    return 0;
}
