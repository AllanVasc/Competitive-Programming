//  O - Diamonds
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18; 
 
int const MAXN = 200+20;
int dp[MAXN][MAXN];
vector<pair<double,double>> v;
int n;
 
int solve(int idx, int last){
    if(idx == n){
        return 0;
    }
    if(last != -1 && dp[idx][last] != -1){
        return dp[idx][last];
    }

    int answ = 0;
    if(last == -1)
        answ = max(1 + solve(idx+1,idx), solve(idx+1,last));
    else{
 
        if(v[idx].first > v[last].first && v[idx].second < v[last].second)
            answ = max(1 + solve(idx+1,idx),
                    solve(idx+1,last));
        else 
            answ = solve(idx+1,last);
            
    }
 
    // cout << "idx = " << idx << " answ = " << answ << '\n';
 
    return dp[idx][last] = answ;
}
 
int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        
        cin >> n; 
 
        for(int i = 0; i < n ; i++){
            double w,c;
            cin >> w >> c;
            v.push_back({w,c});
        }
 
        for(int i = 0; i <= n+5; i++) 
            for(int j = 0; j <= n+5; j++) 
                dp[i][j] = -1;
 
        cout << solve(0,-1) << '\n';

        v.clear();
    }
    return 0;
}