#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mod = 1000000007;

ll fExp(ll a, ll b){
    ll ans = 1;

    while(b){
        if(b & 1) ans = ans * a % mod;
        a = a*a % mod;

        b >>= 1;
    }

    return ans;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        ll n, k;
        cin >> n >> k;
        n++; k++;

        cout << (k * (n * (n+1) % mod) % mod) * fExp(2, mod - 2) % mod << "\n"; 
    }

}