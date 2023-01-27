#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 998244353 ;

const int ms = 510;
int dp[ms][ms];
vector<vector<int>> v;

bool check(int end, int last){
    for(int i = 0; i < end; i++){
        if(v[i][end - 1] == 0) continue;
        if(v[i][end - 1] == 1 && last > i) return false;
        if(v[i][end - 1] == 2 && last <= i) return false;
    }
    return true;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;
    v.assign(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            cin >> v[i][j];
        }
    }

    if(v[0][0] != 2) dp[1][0] = 2;
    // dp[i][j] -> quantidade de maneiras de colocar "i" caracteres sendo o caracter "j"
    // diferente do caracter "i"
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < i; j++){
            // Continuo com o mesmo caracter, sem mudar o "j", se for válido adiciono a quantidade de respostas de dp[i - 1][j]
            if(check(i, j)) dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            // Mudo o caracter "i", entao o meu ultimo diferente vai ser agora "i - 1"
            if(check(i, i - 1)) dp[i][i - 1] = (dp[i][i - 1] + dp[i - 1][j]) % MOD;
        }
    }
    
    int answ = 0;
    for(int i = 0; i < n; i++){
        answ = (answ + dp[n][i]) % MOD;
    }
    cout << answ << '\n';
    return 0;
}