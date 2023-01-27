// 
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int INF = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;

const int MAXN = 3000 + 10;

vector<int> v;
int dp[MAXN][MAXN];

void clear(){
    for(int i = 0; i < MAXN; i++)
        for(int j = 0; j < MAXN; j++)
            dp[i][j] = -1;
}

int solve(int idx, int jump){
    if(idx >= v.size() || jump <= 0) return -1e8*3000;
    if(idx >= v.size()-1)
        return v.back();

    if(dp[idx][jump] != -1) return dp[idx][jump];

    int answ = max( v[idx] + solve(idx+jump, jump), solve(idx,jump-1));

    return dp[idx][jump] = answ;
}

int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int aux;
        cin >> aux;
        v.push_back(aux);
    }
    
    clear();
    cout << solve(0,n-1) << '\n';

    return 0;
}
