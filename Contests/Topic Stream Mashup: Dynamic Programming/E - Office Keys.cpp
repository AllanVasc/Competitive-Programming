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

const int ms = 2000 + 100;
int dp[ms][ms];
vector<int> pps, keys;
int solve(int people, int key, int pos){
    int n = pps.size();
    int k = keys.size();
    if(people >= n){ // todo mundo deu assignment
        return 0;
    }
    if(key >= k){
        return INF;
    }
    int & answ = dp[people][key];
    if(answ != -1) return answ;
    answ = 1e12;

    int dist = abs(pps[people] - keys[key]) + abs(keys[key] - pos);
    answ = min(answ, max(dist, solve(people + 1, key + 1, pos)));
    // or
    answ = min(answ, solve(people, key + 1, pos));
    return answ;
}

signed main() {
    optimize;
    int n, k, pos;
    cin >> n >> k >> pos;
    pps.assign(n, 0);
    keys.assign(k, 0);
    for(int i = 0; i < n; i++) cin >> pps[i];
    for(int i = 0; i < k; i++) cin >> keys[i];
    sort(ALL(pps));
    sort(ALL(keys));

    // int answ = 1e12;
    // for(int i = 0; i < k - n + 1; i++){
    //     int mx = 0;
    //     for(int j = 0; j < n; j++){
    //         int dist = abs(pps[j] - keys[i + j]) + abs(keys[i + j] - pos);
    //         mx = max(mx, dist);
    //     }
    //     answ = min(answ, mx);
    // }
    // cout << answ << '\n';
    memset(dp, -1, sizeof dp);
    cout << solve(0, 0, pos) << '\n';
    return 0;
}