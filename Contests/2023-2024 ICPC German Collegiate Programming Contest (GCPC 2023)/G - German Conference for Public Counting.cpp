#include <bits/stdc++.h>

using namespace std;
#define int long long


int cntDig(int x){
    int ret =0;
    while(x >=1){
        ret++;
        x/=10;
    }
    return ret;
}

int gen(int qtd, int num){
    int ret =0;
    for(int i=0; i<qtd; i++){
        ret*=10;
        ret += num;
    }
    return ret;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;

    int qtd = cntDig(n);
    int ans = 10*(qtd -1);
    if(qtd == 1) ans++;
    
    for(int i=1; i<=9; i++){
        if(gen(qtd, i) <= n) ans++;
    }
    cout << ans << '\n';



}