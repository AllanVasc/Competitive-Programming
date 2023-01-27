//  D - Time to go back
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18;

const int MOD = 1000000007;
const int MAXN = 200 + 20;
int fat[MAXN];

int fExpo(int x, int y, int p){
    int ans = 1;
    x = x % p;     
    if (x == 0) return 0;
    while(y){ 
        if (y & 1) ans = (ans*x) % p;
        y = y >> 1;
        x = (x*x) % p;
    }
    return ans;
}

int invMod(int n){
    return fExpo(n,MOD-2,MOD)%MOD;
}

int comb(int n, int k){
    if(k > n) return 0;
    return (((fat[n]*invMod(fat[k]))%MOD)*invMod(fat[n-k]))%MOD;
}

int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fat[0] = 1;
    for(int i = 1; i < MAXN; i++) fat[i] = (fat[i-1]*i)%MOD;

    int t;
    cin >> t;

    while(t--){
        int n,m,k,d;
        cin >> n >> m >> k >> d;

        int greaterD = 0;
        int lessD = 0;

        for(int i = 0; i < n; i++){
            int aux;
            cin >> aux;
            if(aux >= d) greaterD++;
            else lessD++;
        }

        int answ = 0;
        for(int i = k; i <= min(m,greaterD); i++){
            answ = (answ + (comb(greaterD,i)*comb(lessD,m-i))%MOD)%MOD; 
        }

        cout << answ << '\n';
    }

    return 0;
}
