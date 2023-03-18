#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int MAXN = 3000 + 200;
int dp[MAXN][MAXN];

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string s, t;
    cin >> s >> t;

    for(int i = 0; i < MAXN; i++){
        dp[0][i] = 0;
        dp[i][0] = 0;
    }

    for(int i = 1; i <= s.size(); i++){
        for(int j = 1; j <= t.size(); j++){
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if(s[i - 1] == t[j - 1]){
                dp[i][j] = max(dp[i][j], 1 + dp[i - 1][j - 1]);
            }
        }
    }
    
    // cout << dp[s.size()][t.size()] << '\n';
    string answ;
    int i = s.size(), j = t.size();
    while(i != 0 && j != 0){
        if(s[i - 1] == t[j - 1]){
            answ.push_back(s[i - 1]);
            i--;
            j--;
        }
        else{
            if(dp[i][j - 1] > dp[i - 1][j]){
                j--;
            }
            else{
                i--;
            }
        }
    }
    reverse(answ.begin(), answ.end());
    cout << answ << '\n';
    return 0;
}