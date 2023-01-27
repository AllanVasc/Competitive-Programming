// 
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int INF = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;

const int MAXN = 2*1e5 + 100;

vector<int> fact;
vector<int> inv_fact;
vector<int> answ;
int n,p;

int fexpo(int x, int y, int MOD){
    int answ = 1;
    x = x%MOD;
    if(x == 0) return 0;
    while(y){
        if(y&1) answ = (answ*x)%MOD;
        y = y >> 1;
        x = (x*x)%MOD;
    }
    return answ;
}

int ModMultInv(int n, int MOD){
    return fexpo(n, MOD-2, MOD);
}

void backtrack(int produto, int soma, int size, int last, int freq, int curr){

    int need1 = produto - soma;

    if(size + need1 > n){
        return;
    }

    // cout << "prod = " << produto << " sum = " << soma << '\n';

    backtrack(produto*last, soma+last, size+1, last, freq+1, curr);

    for(int i = last+1; i <= n && (produto*i - (soma+i)) <= n; i++){
        backtrack(produto*i, soma+i,size+1, i, 1, (curr*inv_fact[freq])%p);
    }

    answ[size + need1] = (answ[size + need1] + curr*inv_fact[freq]%p * inv_fact[need1]%p )%p;
}

int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> p;

    fact.assign(MAXN, 0);
    inv_fact.assign(MAXN, 0);
    fact[0] = 1;
    inv_fact[0] = 1;
    for(int i = 1; i < MAXN; i++){
        fact[i] = (fact[i-1]*i)%p;
        inv_fact[i] = ModMultInv(fact[i], p);
    }

    answ.assign(n+5, 0);
    backtrack(1, 0, 0, 2, 0, 1);

    for(int i = 2; i <= n; i++){
        cout << (answ[i]*fact[i])%p << " ";
    }
    cout << '\n';

    return 0;
}