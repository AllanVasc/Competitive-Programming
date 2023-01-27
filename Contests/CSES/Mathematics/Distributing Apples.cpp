#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int fexpo(int x, int y){
    int answ = 1;
    x %= MOD;
    while(y){
        if(y & 1) answ = answ * x % MOD;
        x = x * x % MOD;
        y = y >> 1;
    }
    return answ;
}

vector<int> fact;
vector<int> inv_fact;

int comb_rep(int m, int k){
    return fact[m + k] * inv_fact[m] % MOD * inv_fact[k] % MOD;
}

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    fact.assign(m + n + 1, 1);
    inv_fact.assign(m + n + 1, 1);
    for(int i = 2; i <= m + n; i++){
        fact[i] = fact[i - 1] * i % MOD;
        inv_fact[i] = fexpo(fact[i], MOD - 2);
    }

    cout << comb_rep(m, n -1) << '\n';
    return 0;
}