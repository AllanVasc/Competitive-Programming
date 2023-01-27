#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int ms = 1e6 + 10;

int fexpo(int x, int y){
    int answ = 1;
    x = x % MOD;
    while(y){
        if(y & 1) answ = answ * x % MOD;
        x = x * x % MOD;
        y >>= 1;
    }
    return answ;
}

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    vector<int> freq(26,0);

    for(int i = 0; i < s.size(); i++) freq[s[i] - 'a']++;
    
    vector<int> fact(ms, 1);
    vector<int> inv_fact(ms, 1);

    for(int i = 1; i < ms; i++){
        fact[i] = fact[i-1] * i % MOD;
        inv_fact[i] = fexpo(fact[i], MOD - 2);
    }

    int answ = fact[s.size()];
    for(int i = 0; i < freq.size(); i++){
        answ = answ * inv_fact[freq[i]] % MOD;
    }

    cout << (answ + MOD) % MOD << '\n';

    return 0;
}