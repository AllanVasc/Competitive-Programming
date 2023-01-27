#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int STATES = (1 << 18) + 10;
const int LAST = 20;
int dp[STATES][LAST];
int bonus[LAST][LAST];
vector<int> satisf;
vector<iii> rules;
int n, m, k;

int solve(int state, int last){
    if(__builtin_popcount(state) >= m) return 0;
    int & answ = dp[state][last];
    if(answ != -1) return answ;

    for(int i = 0; i < n; i++){
        if( (state & (1 << i)) == 0){
            answ = max(answ, satisf[i] + bonus[last][i] + solve(state | (1 << i), i));
        }
    }

    return answ;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> k;
    satisf.assign(n, 0);
    for(int i = 0; i < n; i++) cin >> satisf[i];

    for(int i = 0; i < k; i++){
        int x, y, c;
        cin >> x >> y >> c;
        x--, y--;
        bonus[x][y] = c;
    }

    memset(dp, -1, sizeof(dp));

    int answ = 0;
    for(int i = 0; i < n; i++){
        answ = max(answ, solve(1 << i, i) + satisf[i]);
    }
    cout << answ << '\n';
   
    return 0;
}