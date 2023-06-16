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

const int nBit = 22;
int dp[1 << nBit];

int32_t main() {
    optimize;

    int n; cin >> n;
    vector<int> v(n);
    int mx = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v[i] = x;
        mx = max(mx, x);
        dp[x] = x;
    }
    for(int i = 0; i < nBit; i++){
        for(int mask = 0; mask < (1 << nBit); mask++){
            if(mask & (1 << i)){
                dp[mask] = max(dp[mask], dp[mask ^ (1 << i)]);
            }
        }
    }
    for(int i = 0; i < n; i++){
        int allOnes = (1 << nBit) - 1;
        int neg = v[i] ^ allOnes;
        cout << (dp[neg] == 0 ? -1 : dp[neg]) << " ";
    }
    cout << '\n';

    return 0;
}