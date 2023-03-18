#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int MAXK = 100000 + 100;
int dp[MAXK];
int n, k;
vector<int> v;

// Seg fault!!!
// int solve(int k){
//     if(k == 0) return 0;
//     int& ans = dp[k];
//     if(ans != -1) return ans;

//     set<int> mex;
//     for(int i = 0; i < n; i++){
//         if(v[i] <= k){
//             mex.insert(solve(k - v[i]));
//         }
//     }
//     int cnt = 0;
//     while(mex.count(cnt)) cnt++;
//     return ans = cnt;
// }

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;
    v.assign(n, 0);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    for(int i = 0; i <= k; i++){
        set<int> mex;
        for(int j = 0; j < n; j++){
            if(i - v[j] >= 0) mex.insert(dp[i - v[j]]);
            else break;
        }
        int cnt = 0;
        while(mex.count(cnt)) cnt++;
        dp[i] = cnt;
    }

    if(dp[k]){
        cout << "First" << '\n';
    }
    else{
        cout << "Second" << '\n';
    }

    return 0;
}