#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int ms = (1 << 16);
vector<int> dp;
int scoreMask[ms];

void backtrack(int i, int mask, int score_t, int group, vector<int>& not_taken){
    int n = not_taken.size();
    if(i >= n){
        dp[mask] = max(dp[mask], score_t + scoreMask[group]);
        return;
    }
    backtrack(i + 1, mask, score_t, group, not_taken);
    int new_mask = mask ^ (1 << not_taken[i]);
    backtrack(i + 1, new_mask, score_t, group ^ (1 << not_taken[i]), not_taken);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> mat[i][j];
        }
    }

    // O(2^n * n^2)
    for(int mask = 0; mask < (1 << n); mask++){
        for(int i = 0; i < n; i++){
            if(mask & (1 << i)){
                for(int j = i; j < n; j++){
                    if(mask & (1 << j)) scoreMask[mask] += mat[i][j];
                }
            }
        }
    }
    dp.assign((1 << n), -INF);
    dp[0] = 0;

    // O(3^n) -> Análise Amortizada
    for(int mask = 0; mask < (1 << n); mask++){
        vector<int> not_taken;
        for(int i = 0; i < n; i++){
            if(!(mask & (1 << i))){
                not_taken.push_back(i);
            }
        }
        backtrack(0, mask, dp[mask], 0, not_taken);
    }

    cout << dp[(1 << n) - 1] << "\n";
    return 0;
}