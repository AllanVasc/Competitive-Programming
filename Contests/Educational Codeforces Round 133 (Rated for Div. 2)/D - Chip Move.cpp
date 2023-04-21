#include <bits/stdc++.h>
using namespace std;

#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 998244353;

const int ms = 2*1e5;
const int mJmp = sqrt(ms) + 10;

// MLE!!!
// int solve(int x, int jmp, int k){
//     if(jmp == 0){
//         return (x == 0);
//     }
//     int& answ = dp[x][jmp];
//     if(answ != -1) return answ;
//     answ = 0;
//     for(int i = 1; (x - (i * (k + jmp - 1))) >= 0; i++){
//         answ += solve(x - (i * (k + jmp - 1)), jmp - 1, k);
//         answ %= MOD;
//     }
//     return answ;
// }

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n, k;
    cin >> n >> k;

    vector<int> answ(n + 1, 0);
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for(int start = 0, jmp = k; start + k <= n; start += jmp, jmp++){
        vector<int> posMod(jmp);
        for(int x = start; x <= n; x++){
            int last = dp[x];
            dp[x] = posMod[x % jmp];
            dp[x] %= MOD;
            posMod[x % jmp] += last;
            posMod[x % jmp] %= MOD;

            answ[x] += dp[x];
            answ[x] %= MOD;
        }
    }

    for(int i = 1; i <= n; i++){
        cout << answ[i] << " ";
    }
    cout << '\n';

    return 0;
}