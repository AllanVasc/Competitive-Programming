#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int fexp(int x, int y){
    int answ = 1;
    x = x % MOD;
    while(y){
        if(y & 1) answ = answ*x %MOD;
        x = x*x % MOD;
        y >>= 1;
    }
    return answ;
}

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;

    int maxn = 1e6 + 10;
    vector<int> count_div(maxn, 0);
    for(int i = 1; i < maxn; i++){
        for(int j = i; j < maxn; j += i){
            count_div[j]++;
        }
    }

    while(t--){
        int n;
        cin >> n;

        cout << count_div[n] << '\n';
    }
    return 0;
}