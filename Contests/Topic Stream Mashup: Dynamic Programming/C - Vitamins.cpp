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

const int ms = 1000 + 2;
int dp[ms][1 << 3];
vector<int> cost;
vector<string> vits;

int solve(int idx, int mask){
    int n = vits.size();
    if(idx >= n){
        if(__builtin_popcount(mask) == 3) return 0;
        else return INF;
    }
    int & answ = dp[idx][mask];
    if(answ != -1) return answ;
    answ = INF;
    answ = min(answ, solve(idx + 1, mask));
    int new_mask = mask;
    for(int i = 0; i < vits[idx].size(); i++){
        int curr = vits[idx][i] - 'A';
        new_mask |= (1 << curr);
    }
    answ = min(answ, cost[idx] + solve(idx + 1, new_mask));
    return answ;
}

signed main() {
    optimize;
    int n; cin >> n;
    cost.assign(n, INF);
    vits.assign(n, "");
    for(int i = 0; i < n; i++){
        cin >> cost[i] >> vits[i];
    }
    memset(dp, -1, sizeof dp);
    int answ = solve(0, 0);
    cout << (answ == INF ? -1 : answ) << '\n';
    return 0;
}