//  R - Ramp Number
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18; 
 
const int MAXN = 100;
const int FLAG = 2;
int dp[MAXN][12][FLAG];
string s;
int n;
// Flag 1 = não tenho restrição
// Flag 0 = tenho restrição
int solve(int idx, int last,int flag){
    if(idx == n){
        return 1;
    }
    if(dp[idx][last][flag] != -1){
        return dp[idx][last][flag];
    }

    int answ = 0;
    int limit = flag ? 9 : s[idx]-'0';
    for(int i = last; i <= limit; i++){
        answ += solve(idx+1,i,flag|(i < limit));
    }

   return dp[idx][last][flag] = answ;
}
 
int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        
        cin >> s;
        n = s.size();
        bool check = true;

        int last = s[0] - '0';
        for(int i = 0; i < n; i++){
            if(last > s[i]-'0') check = false;
            last = s[i]-'0';
        }

        for(int i = 0; i < MAXN; i++){
            for(int j = 0; j < 12; j++){
                for(int k = 0; k < FLAG; k++){
                    dp[i][j][k] = -1;
                }
            }
        }

        if(check){
            cout << solve(0,0,0)-1 << '\n';
        }
        else{
            cout << -1 << '\n';
        }
    }
    return 0;
}