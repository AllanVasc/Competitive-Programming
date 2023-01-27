#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    // Derangement problem
    vector<int> answ(n + 2, 0);
    for(int i = 2; i <= n; i++){
        answ[i] = ((i * answ[i - 1]) % MOD + ((i % 2 == 0) ? 1 : -1)) % MOD;
    }

    cout << (answ[n] + MOD) % MOD << '\n';
    return 0;
}