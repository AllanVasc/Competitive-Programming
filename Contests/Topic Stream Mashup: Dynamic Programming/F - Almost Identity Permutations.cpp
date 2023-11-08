#include <bits/stdc++.h>
using namespace std;

#define int long long
#define optimize ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define iii tuple<int,int,int>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int nCk(int n, int k){
    int answ = 1;
    for(int i = n; i > n - k; i--){
        answ *= i;
    }
    int div = 1;
    for(int i = 1; i <= k; i++){
        div *= i;
    }
    return answ / div;
}

signed main() {
    optimize;
    int n, k;
    cin >> n >> k;
    vector<int> dp(5, 0);
    dp[0] = 1;
    dp[1] = 0;
    for(int i = 2; i < 5; i++){
        dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);
    }
    int answ = 0;
    for(int i = 2; i <= k; i++){
        answ += nCk(n, i) * dp[i];
    }
    cout << 1 + answ << '\n';
    return 0;
}