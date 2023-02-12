#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    const int MAXN = 1e5 + 10;
    int fat[MAXN];
    fat[0] = 1;
    for(int i = 1; i < MAXN; i++){
        fat[i] = fat[i - 1] * i % MOD;
    }

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int cnt = (1 + n-1) * (n -1) % MOD;
        int answ = cnt * fat[n] % MOD;
        cout << answ << '\n';
    }

    return 0;
}