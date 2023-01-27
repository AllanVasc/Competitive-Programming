// C - Get an Even String
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int MAXN = 2e5 + 5;
const int ALF = 26 + 5;
 
ll dp[MAXN][ALF];
string s;
 
ll solve(int pos, int last){
 
    if(pos >= s.size()){
        return 0;
    }
    else if(dp[pos][last] != -1){
        return dp[pos][last];
    }
    else{
 
        ll not_choose = solve(pos+1, last) + 1;
 
        ll choose = LONG_LONG_MAX;
 
        int idx_atual = (s[pos] - 'a') + 1;
 
        if(last == 0){
            choose = solve(pos+1, idx_atual);
        }
        else if(last == idx_atual){
            choose = solve(pos+1, 0);
        }
 
        return dp[pos][last] = min(choose, not_choose);
 
    }
}
 
int main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    ll t;
 
    cin >> t;
 
    while(t--){
 
        cin >> s;

        for(int i = 0; i <= s.size(); i++){
            for(int j = 0; j < ALF;j++){
                dp[i][j] = -1;
            }
        }
 
        ll answ = solve(0, 0);
 
        if((s.size() - answ)%2 != 0){
            answ++;
        }
        
        cout << answ << '\n';
 
    }
 
    return 0;
}