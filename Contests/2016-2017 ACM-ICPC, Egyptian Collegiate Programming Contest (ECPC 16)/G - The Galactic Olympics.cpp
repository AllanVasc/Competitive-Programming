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

int fexp(int x, int y){
    int answ = 1;
    while(y){
        if(y & 1) answ = answ * x % MOD;
        x = x * x % MOD;
        y >>= 1;
    }
    return answ;
}

const int ms = 1e3 + 10;
int fat[ms], invfat[ms], dp[ms][ms];

int comb(int n, int k){
    return fat[n] * invfat[n - k] % MOD * invfat[k] % MOD;
}

int solve(int i, int j){
    if(i == 0) return j == 0;
    if(j < i) return 0;
    int & answ = dp[i][j];
    if(answ != -1) return answ;
    answ = 0;
    for(int k = 1; k <= j; k++){
        answ += comb(j, k) * solve(i - 1, j - k);
        answ %= MOD;
    }
    return answ;
}

signed main() {
    optimize;
    
    freopen("galactic.in", "r", stdin); // CHANGE
    fat[0] = invfat[0] = 1;
    for(int i = 1; i < ms; i++){
        fat[i] = fat[i - 1] * i % MOD;
        invfat[i] = fexp(fat[i], MOD - 2);
    }
    memset(dp, -1, sizeof dp);
    solve(ms -1, ms - 1);
    int t; cin >> t;
    while(t--){
        int n, k; // children / games
        cin >> k >> n; 
        if(n > k) cout << 0 << '\n';
        else{
            cout << solve(n, k) << '\n';
        }
    }

    return 0;
}