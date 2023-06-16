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

int dp[1 << 21][2];

int32_t main() {
    optimize;
    
    int n;
    cin >> n;
    vector<int> v(n);
    int mx = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v[i] = x;
        dp[x][0]++; // Counting the number of occurrences of x
        dp[x][1]++;
        mx = max(mx, x);
    }
    int x = 1;
    int nBit = 0;
    while(x < mx){
        x *= 2;
        nBit++;
    }

    // SOS DP with memory optimization
    for(int i = 0; i < nBit; i++){
        for(int mask = 0; mask < (1 << nBit); mask++){
            // x | y = x means y is subset of x, and we are counting # of x's subset
            if(mask & (1 << i)) dp[mask][0] += dp[mask ^ (1 << i)][0];

            // x & y = x means x is subset of y, and we are counting supersets
            if(!(mask & (1 << i))) dp[mask][1] += dp[mask ^ (1 << i)][1];

            // x & y != 0, means there is at least 1 overlap
            // which means y can not be the subset of ~x
            // so = N - (~x) | y, so we can use 1st result
        }
    }

    for(int i = 0; i < n; i++){
        int allOne = (1 << nBit) - 1;
        int negateX = v[i] ^ allOne;
        cout << dp[v[i]][0] << " " << dp[v[i]][1] << " " << n - dp[negateX][0] << '\n';
    }

    return 0;
}