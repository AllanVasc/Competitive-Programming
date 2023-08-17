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

const int maskSz = 3;
vector<pii> v;
vector<vector<int>> dp;

void print_mask(int mask){
    for(int i = maskSz - 1; i >= 0; i--){
        cout << ((mask & (1 << i)) ? 1 : 0);
    }
}

int solve(int idx, int mask){
    // cout << "idx = " << idx << " mask = ";
    // print_mask(mask);
    // cout << '\n';
    int n = v.size();
    if(idx >= n){
        return (__builtin_popcount(mask) == maskSz ? 0 : INF);
    }
    
    int & answ = dp[idx][mask];
    if(answ != INF) return answ;

    int b3 = mask & (1 << (maskSz - 1));
    if(!b3){
        // Preciso dar match agora!
        auto [c1, i1] = v[idx];
        auto [c2, i2] = v[idx - maskSz];
        int cost = ((i1 ^ 1) == i2 ? INF : abs(c1 - c2));
        if(cost == INF) return answ;
        int new_mask = mask << 1;
        new_mask = new_mask | 1;
        answ = min(answ, cost + solve(idx + 1, new_mask));
    }
    else{
        // Posso dar match com algum ou deixar pra dps
        // cout << "b3 = 1" << '\n';
        for(int i = 0; i < maskSz; i++){
            if(mask & (1 << i)) continue;
            // cout << "tentando com " << i << '\n';
            auto [c1, i1] = v[idx];
            auto [c2, i2] = v[idx - (i + 1)];
            int cost = ((i1 ^ 1) == i2 ? INF : abs(c1 - c2));
            if(cost == INF) continue;
            int new_mask = mask | (1 << i);
            new_mask = new_mask << 1;
            new_mask = new_mask & ((1 << maskSz) - 1);
            new_mask = new_mask | 1;
            // cout << "new = ";
            // print_mask(new_mask);
            // cout << '\n';
            answ = min(answ, cost + solve(idx + 1, new_mask));
        }
        int new_mask = mask << 1;
        new_mask = new_mask & ((1 << maskSz) - 1);
        answ = min(answ, solve(idx + 1, new_mask));
    }

    return answ;
}

signed main() {
    optimize;
    
    int n; cin >> n;
    for(int i = 0; i < 2*n; i++){
        int x; cin >> x;
        v.push_back({x, i});
    }
    sort(ALL(v));
    dp.assign(v.size(), vector<int>(1 << maskSz, INF));
    cout << solve(0, (1 << maskSz) - 1) << '\n';
    return 0;
}