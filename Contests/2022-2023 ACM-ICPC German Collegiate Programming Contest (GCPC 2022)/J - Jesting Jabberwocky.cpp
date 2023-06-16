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

const int ms = 1e5 + 100;
const int mlast = 5;
int dp[ms][1 << mlast][mlast];
string s;
map<char, int> mp;
// last:
// h = 0, 
// d = 1,
// c = 2,
// s = 3
int solve(int idx, int mask, int last){
    int n = s.size();
    if(idx >= n) return 0;
    int & answ = dp[idx][mask][last];
    if(answ != -1) return answ;
    answ = INF;
    int curr = mp[s[idx]];
    if(last == curr) answ = min(answ, solve(idx + 1, mask, last));
    else{
        answ = min(answ, 1 + solve(idx + 1, mask, last));
        if((mask & (1 << curr)) == 0) answ = min(answ, solve(idx + 1, mask | (1 << curr), curr));
    }
    return answ;
}

int32_t main() {
    optimize;
    
    cin >> s;
    memset(dp, -1, sizeof dp);
    mp['h'] = 1;
    mp['d'] = 2;
    mp['c'] = 3;
    mp['s'] = 4;
    cout << solve(0, 0, 0) << '\n';
    return 0;
}