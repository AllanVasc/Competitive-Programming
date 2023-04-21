#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int ms = 3000 + 100;
int dp[ms][ms];

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    string s;
    cin >> n >> s;
    
    dp[1][1] = 1;
    for(int i = 2; i <= n; i++){
        vector<int> ps(n + 1, 0);
        for(int j = 1; j <= n; j++){
            ps[j] = (ps[j - 1] + dp[i - 1][j]) % MOD;
        }

        for(int last = 1; last <= i; last++){
            if(s[i - 2] == '>'){
                dp[i][last] = (ps[last - 1] - ps[0] + MOD) % MOD;
            }
            else{
                dp[i][last] = (ps[i] - ps[last - 1] + MOD) % MOD;
            }
        }
    }

    int answ = 0;
    for(int i = 1; i <= n; i++){
        answ += dp[n][i];
        answ %= MOD;
    }

    cout << answ << '\n';
    return 0;
}