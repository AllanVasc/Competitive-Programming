// H - Special Palindrome
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18;

const int MAXN = 250 + 10;
int n;

int dp[MAXN][MAXN];

int solve(int sum, int last){

    if(sum < 0) return 0;
    if(sum == 0) return 1;

    if(dp[sum][last] != -1){
        return dp[sum][last];
    }

    int answ = 0;
    for(int i = last; i > 0; i--){
        answ += solve(sum-i,i);
    }

    return dp[sum][last] = answ;
}

int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 0; i < MAXN; i++){
        for(int j = 0; j < MAXN; j++){
            dp[i][j] = -1;
        }
    }

    cin >> n;
    while(n != 0){
        
        int answ = 0;
        if(n%2 == 1){
            for(int i = 1; i <= n; i+=2){
                answ += solve((n-i)/2,i);
            }
            cout << answ << '\n';
        }
        else{
            answ += solve(n/2, n);
            for(int i = 2; i <= n; i+=2){
                answ += solve((n-i)/2,i);
            }
            cout << answ << '\n';
        }

        cin >> n;
    }
    return 0;
}
