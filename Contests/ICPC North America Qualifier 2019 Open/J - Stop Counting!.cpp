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

    cout << fixed << setprecision(10);
    
    vector<long double> v;
    for(int i = 0; i < n; i++){
        long double aux;
        cin >> aux;
        v.push_back(aux);
    }

    long double answ = 0;
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += v[i];
        answ = max(answ, sum/(long double)(i+1));
    }
    sum = 0;
    for(int i = n-1; i >= 0; i--){
        sum += v[i];
        answ = max(answ, sum/(long double)(n-i));
    }
    
    cout << answ << '\n';

    return 0;
}
