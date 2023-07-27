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

// dp[i][j] = pos * pos + 
//            dp[i - 1][j - 1] + 
//            dp[i - 1][j] - 
//            dp[i - 2][j - 1] 

bool check(int row, int n){
    int total = (1 + row) * row / 2;
    return total >= n;
}

signed main() {
    optimize;
    vector<vector<int>> dp;
    dp.push_back({0, 0, 0});
    int cnt = 1;
    int lim = 1;
    for(int i = 1; i <= 2025; i++){
        vector<int> aux(lim + 3, 0);
        for(int j = 1; j <= lim; j++){
            aux[j] = cnt * cnt + 
                     dp[i - 1][j - 1] + 
                     dp[i - 1][j];
            if(i - 2 >= 0) aux[j] -= dp[i - 2][j - 1];
            cnt++;
        }
        dp.push_back(aux);
        lim++;
    }
    // for(int i = 0; i <= 5; i++){
    //     cout << "row = " << i << '\n';
    //     for(auto x : dp[2024]){
    //         cout << x << " ";
    //     }
    //     cout << '\n';
    // }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int l = 1; 
        int r = 2024;
        int row = r;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(check(mid, n)){
                row = min(row, mid);
                r = mid - 1;
            }
            else l = mid + 1;
        }
        int pos = n - ((1 + (row - 1)) * (row - 1) / 2);
        // cout << "row = " << row << '\n';
        // cout << "pos = " << pos << '\n';
        cout << dp[row][pos] << '\n';
    }
    return 0;
}