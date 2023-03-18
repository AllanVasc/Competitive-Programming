#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int MAXN = 100 + 100;
const int MAXW = 1e4 + 100;
int dp[MAXN][MAXW];

int solve(int idx, int w, vector<ii>& v){
    if(w < 0) return LONG_LONG_MIN;
    int n = v.size();
    if(idx >= n) return 0;
    int& answ = dp[idx][w];
    if(answ != -1) return answ;
    auto [wi, vi] = v[idx];
    answ = max(solve(idx + 1, w, v), vi + solve(idx + 1, w - wi, v));
    return answ;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, k, l;
    cin >> n >> k >> l;
    vector<ii> people(n);
    for(int i = 0; i < n; i++){
        cin >> people[i].first >> people[i].second;
    }
    vector<ii> itens(k);
    for(int i = 0; i < k; i++){
        cin >> itens[i].first >> itens[i].second;
    }
    memset(dp, -1, sizeof dp);
    vector<ii> best(n);
    for(int i = 0; i < n; i++){
        best[i] = {people[i].second, solve(0, people[i].first, itens)};
    }
    memset(dp, -1, sizeof dp);
    
    cout << solve(0, l, best) << '\n';
    return 0;
}