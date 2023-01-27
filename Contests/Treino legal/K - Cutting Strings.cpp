//  
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18;
 
long double distance(int x, int y){
    return sqrt((x-0)*(x-0) + (y-0)*(y-0));
}
 
int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int k;
    cin >> k;
 
    int dp[50];
    dp[0] = 1;
    dp[1] = 3;
 
    for(int i = 2; i <= 30; i++){
        dp[i] = (dp[i-1]-1)*2 + 3;
    }
 
    cout << dp[k] << '\n';
 
    return 0;
}