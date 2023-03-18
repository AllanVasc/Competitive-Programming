#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int ms = 65;
int comb[ms][ms];
int dp[ms][ms];
vector<int> weights;
vector<int> qtd;
int solve(int idx, int sum, int check, int q){
    int n = weights.size();
    if(idx >= n){
        if(sum >= q && sum - weights[check] < q) return 1;
        else return 0;
    }
    int& answ = dp[idx][sum];
    if(answ != -1) return answ;
    
    answ = 0;
    if(idx != check){
        for(int i = 0; i <= qtd[idx]; i++){
            answ += comb[qtd[idx]][i] * solve(idx + 1, sum + i * weights[idx], check, q);
        }
    }
    else{
        for(int i = 1; i <= qtd[idx]; i++){
            answ += comb[qtd[idx] - 1][i - 1] * solve(idx + 1, sum + i * weights[idx], check, q);
        }
    }

    return answ;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    for(int i = 0; i < ms; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0) comb[i][j] = 1;
            else comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
        }
    }

    int n, q;
    int cnt = 1;
    while(cin >> n >> q){
        if(n == q && q == 0) break;

        cout << "Case " << cnt++ << ": ";

        weights.assign(n, 0);
        qtd.assign(n, 0);
        for(int i = 0; i < n; i++){
            cin >> weights[i] >> qtd[i];
        }
        
        for(int i = 0; i < n; i++){
            memset(dp, -1, sizeof dp);
            cout << solve(0, 0, i, q) << (i == n - 1 ? "\n" : " ");
        }
    }
    return 0;
}