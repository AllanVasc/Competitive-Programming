#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int maxn = 1e5 + 1;
const int max_number = 100 + 2;
int dp[maxn][max_number];
int n, m;
vector<int> v;

int solve(int idx, int last){
    // cout << "idx = " << idx << " last = " << last << '\n';
    if(last > m || last <= 0) return 0;
    if(idx >= n) return 1;
    if(v[idx] != 0 && abs(v[idx] - last) > 1) return 0;

    if(dp[idx][last] != -1) return dp[idx][last];

    int answ = 0;
    if(v[idx] == 0){
        for(int i = -1; i < 2; i++){
            answ = (answ + solve(idx + 1, last + i)) % MOD;
        }
    }
    else{
        answ = solve(idx + 1, v[idx]) % MOD;
    }

    return dp[idx][last] = answ;
}

void solve_recursive(){
    for(int i = 0; i < maxn; i++){
        for(int j = 0; j < max_number; j++){
            dp[i][j] = -1;
        }
    }
    
    int answ = 0;
    if(v[0] == 0){
        for(int i = 1; i <= m; i++)
            answ = (answ + solve(1, i)) % MOD;
        
    }else{
        answ = solve(0, v[0]) % MOD;
    }

    cout << answ << '\n';
}

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    v.assign(n, 0);
    for(int i = 0; i < n; i++) cin >> v[i];

    // solve_recursive();

    for(int i = 0; i < n; i++){
        for(int x = 1; x <= m; x++){
            if(i == 0){
                if(v[i] == 0 || v[i] == x) dp[i][x] = 1;
                else dp[i][x] = 0;
            }
            else{
                if(v[i] == 0 || v[i] == x)
                    dp[i][x] = ((dp[i - 1][x - 1] + dp[i - 1][x]) % MOD + dp[i - 1][x + 1]) % MOD;
                else
                    dp[i][x] = 0;
            }
        }
    }

    int answ = 0;
    for(int i = 1; i <= m; i++){
        answ = (answ + dp[n - 1][i]) % MOD;
    }

    cout << answ << '\n';

    return 0;
}