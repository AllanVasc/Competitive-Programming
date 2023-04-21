#include<bits/stdc++.h>
using namespace std;

#define int long long
using ii = pair<int,int>;
const int INF = 1e18;
const int MOD = 1e9 + 7;

const int ms = 1e5 + 100;
const int ms2 = 20;
int dp[ms][ms2];
string s, w;

int solve(int idx, int idx2){
    int n = s.size();
    int m = w.size();
    if(idx2 >= m){
        return 1;
    }
    if(idx >= n){
        if(idx2 >= m){
            return 1;
        }else return 0;
    }
    int& answ = dp[idx][idx2];
    if(answ != -1) return answ;

    answ = 0;
    if(s[idx] == w[idx2]){
        answ += solve(idx + 1, idx2 + 1);
        answ %= MOD;
    }
    answ += solve(idx + 1,  idx2);
    answ %= MOD;

    return answ;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> s >> w;
    memset(dp, -1, sizeof dp);
    cout << solve(0,0) << '\n';
    return 0;
}