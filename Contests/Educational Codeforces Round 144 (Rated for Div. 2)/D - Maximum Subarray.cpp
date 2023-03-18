#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int ms = 2*1e5 + 100;
const int mk = 25;
int dp[ms][mk][3];

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n, qtd, x;
        cin >> n >> qtd >> x;
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];

        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= qtd; j++){
                for(int k = 0; k < 3; k++){
                    dp[i][j][k] = -INF;
                }
            }
        }

        dp[0][0][0] = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= qtd; j++){
                for(int state = 0; state < 3; state++){
                    if(dp[i][j][state] == -INF) continue;
                    
                    for(int new_qtd = j; new_qtd <= min(qtd, j + 1); new_qtd++){
                        int val = v[i] + (new_qtd == j ? -x : x);

                        for(int nextS = state; nextS < 3; nextS++){
                            dp[i + 1][new_qtd][nextS] = max(dp[i + 1][new_qtd][nextS],
                                                          dp[i][j][state] + (nextS == 1 ? val : 0));
                        }
                    }
                }
            }
        }

        cout << max(dp[n][qtd][1], dp[n][qtd][2]) << '\n';
    }
    return 0;
}