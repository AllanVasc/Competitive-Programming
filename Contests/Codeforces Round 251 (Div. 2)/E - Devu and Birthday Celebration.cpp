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

const int ms = 1e5 + 5;
vector<int> divs[ms];
int fat[ms], invfat[ms];
map<pii, int> dp;

int fexp(int x, int y){
    int answ = 1;
    while(y){
        if(y & 1) answ = answ * x % MOD;
        y >>= 1;
        x = x * x % MOD;
    }
    return answ;
}

int comb(int n, int k){
    return fat[n] * invfat[k] % MOD * invfat[n - k] % MOD;
}

int solve(int n, int f){
    if(n < f) return 0;
    if(n == f) return 1;
    if(dp.count({n,f})) return dp[{n,f}];
    int answ = comb(n - 1, f - 1);
    for(auto g : divs[n]){
        answ = (answ - solve(n / g, f) + MOD) % MOD;
    }
    return dp[{n, f}] = answ;
}

signed main() {
    optimize;
    
    fat[0] = invfat[0] = 1;
    for(int i = 1; i < ms; i++){
        fat[i] = fat[i - 1] * i % MOD;
        invfat[i] = fexp(fat[i], MOD - 2);
    }
    for(int i = 1; i < ms; i++){
        for(int j = 2; j * j <= i; j++){
            if(i % j == 0){
                divs[i].push_back(j);
                if (j * j < i) divs[i].push_back(i/j);
            }
        }
        divs[i].push_back(i);
    }
    int q; cin >> q;
    while(q--){
        int n, f; cin >> n >> f;
        cout << solve(n, f) << '\n';
    }
    return 0;
}