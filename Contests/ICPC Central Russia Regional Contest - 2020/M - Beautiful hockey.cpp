#include <bits/stdc++.h>

using namespace std;

#define int long long


const int mod = 1e9 + 7;
const int ms = 5e4 + 5;


int pre[ms], fat[ms], inv[ms];

int fexp(int a, int b){
    int ret = 1;
    while(b){
        if(b&1) ret = (a * ret)%mod;
        a = (a*a)%mod;
        b>>=1;
    }
    return ret;
}



signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    fat[0] = 1, inv[0] = 1;
    for(int i=1; i<=n; i++){
        fat[i] = (i*fat[i-1])%mod;
        inv[i] = fexp(fat[i], mod-2);
    }


    for(int i=0; i<n; i++){
        pre[i] = (fat[n] * inv[i])%mod;
        pre[i] = (pre[i] *inv[n-i])%mod;
        if(i) pre[i] = (pre[i-1] + pre[i])%mod;
    }



    int ans =0;

    for(int i=1; i<=n; i++){
        int aux = (((fat[n] * inv[i])%mod)*inv[n-i])%mod;
        aux = (aux *pre[i-1])%mod;
        ans = (ans + aux)%mod;
    }
    cout << ans << endl;




    return 0;
}