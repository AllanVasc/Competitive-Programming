#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 998244353;

const int MAXN = 1e3 + 100;
int dp[MAXN][MAXN];
vector<int> freq;

int solve(int idx, int selected, int k){
    int n = freq.size();
    if(idx == n){
        if(selected == k) return 1;
        else return 0;
    }
    int & answ = dp[idx][selected];
    if(answ != -1) return answ;

    answ = freq[idx] * solve(idx + 1, selected + 1, k) % MOD;
    answ %= MOD;
    answ += solve(idx + 1, selected, k);
    answ %= MOD;

    return answ;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, k;
    cin >> n >> k;
    map<int,int> aux;
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        aux[val]++;
    }
    for(auto i : aux){
        freq.push_back(i.second);
    }
    memset(dp, -1, sizeof dp);
    cout << solve(0, 0, k) << '\n';
    return 0;
}