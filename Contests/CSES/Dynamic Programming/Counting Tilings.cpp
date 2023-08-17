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

signed main() {
    optimize;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> prevs(1 << n, vector<int>());
    for(int i = 0; i < (1 << n); i++){
        for(int j = 0; j < (1 << n); j++){
            if(i & j) continue;
            bool possible = true;
            for(int k = 0; k < n; k++){
                int bj = (j >> k) & 1;
                int bi = (i >> k) & 1;
                if(!bj && !bi){ // 0 - 0
                    if(k + 1 == n){
                        possible = false;
                        break;
                    }
                    int bjnxt = (j >> (k + 1)) & 1;
                    int binxt = (i >> (k + 1)) & 1;
                    if(bjnxt || binxt){
                        possible = false;
                        break;
                    }
                    k++;
                    continue;
                }
                if(bj) continue;
                if(!bj && bi) continue;
            }
            if(possible) prevs[i].push_back(j);
        }
    }
    // cout << "prevs:" << '\n';
    // for(int i = 0; i < (1 << n) ; i++){
    //     cout << "mask = " << i << " : ";
    //     for(auto x : prevs[i]) cout << x << " ";
    //     cout << '\n';
    // }
    vector<int> dp(1 << n, 0);
    dp[0] = 1; // base case
    for(int i = 1; i <= m; i++){
        vector<int> nxt(1 << n, 0);
        for(int j = 0; j < (1 << n); j++){
            for(auto x : prevs[j]){
                nxt[j] += dp[x];
                nxt[j] %= MOD;
            }
        }
        swap(dp, nxt);
    }
    cout << dp[0] << '\n';
    return 0;
}