#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int MAXN = 1e5 + 100;
int dp[MAXN];
vector<int> v;

int solve(int idx){
    int n = v.size();

    if(idx >= n - 1){
        if(idx == n - 1) return 0;
        else return INF;
    }

    int& answ = dp[idx];
    if(answ != INF) return answ;

    answ = min(abs(v[idx + 1] - v[idx]) + solve(idx + 1),
               abs(v[idx + 2] - v[idx]) + solve(idx + 2));

    return answ;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    v.assign(n, INF);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    for(int i = 0; i < MAXN; i++) dp[i] = INF;
    cout << solve(0) << '\n';
    return 0;
}