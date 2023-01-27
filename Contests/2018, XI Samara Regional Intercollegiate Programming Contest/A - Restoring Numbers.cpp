#include<bits/stdc++.h>
using namespace std;

#define int long long
using ll = long long;

const int INF = 1e18;

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int s,g;
    cin >> s >> g;

    if(g >= s){
        cout << -1 << '\n';
        return 0;
    }
    
    int a = g;
    int b = s - g;

    int check = __gcd(a,b);
    if(check != g) cout << -1 << '\n';
    else{
        cout << a << " " << b << '\n';
    }
    
}