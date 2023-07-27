#include <bits/stdc++.h>

using namespace std;
#define int long long

const int mod = 1e9 + 7;
const int ms = 2e5 + 5;

int fat[ms], inv[ms];

int fexp(int a, int b){
    int ret = 1;
    while(b){
        if(b&1) ret = (ret * a)%mod;
        a = (a * a)%mod;
        b>>=1;
    }
    return ret;
}

int comb(int n, int k){ // n escolhe k
    if(k > n) return 0;
    return (((fat[n] * inv[k])%mod)*inv[n-k])%mod;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    fat[0] = 1;
    inv[0] = fexp(1ll, mod-2);

    for(int i=1; i<ms; i++){
        fat[i] = (fat[i-1] * i) %mod;
        inv[i] = fexp(fat[i], mod-2);
    }

    while(t--){
        int A, B, C, K, c;

        cin >> A >> B >> C >> K >> c;
        
        if(A + B + C < K || (K-c) < 2){
            cout << "0\n";
            continue;
        }
        int ans = comb(C, c) * (comb(A+B, K-c) - comb(A, K-c) - comb(B, K-c) + mod + mod)%mod;

        cout << ans%mod << '\n';

    }


    return 0;
}