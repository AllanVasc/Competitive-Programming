#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ull unsigned long long

ull dp[100][100];
int n, k;
int memo[100][100];

int count(int qtd, int onyx){
    if(onyx < 0) return 0;
    if(qtd == 0) return onyx == 0;

    int &ans = memo[qtd][onyx];
    if(~ans) return ans;
    ans = count(qtd-1, onyx) + count(qtd-1, onyx -2);
    return ans;

}


signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    memset(memo, -1, sizeof memo);

    cin >> n >> k;

    // dp[i][j] = d[i - 1][j -1] + dp[i - 1][j]
    // i escolhe j

    for(int i=0; i<100; i++) dp[i][0] = 1;

    for(int i=1; i<=50; i++){
        for(int j=1; j<=i; j++){
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }


    ull ans=0;
    for(int i=0; i<=n; i++){
        for(int j=i; j<=n; j++){
            if(j+ i == k){
                int ii, jj;
                // ver quais nao sao simetricas
                if(n&1){
                    // ii nao eh contado duas vezes
                    ii = count(n/2, i-1) + count(n/2, i);
                    ii = ii + (dp[n][i] - ii + 1)/2;

                    jj = count(n/2, j-1) + count(n/2, j);
                    jj = jj + (dp[n][j] - jj + 1)/2;
                }
                else{
                    ii = count(n/2, i);
                    ii = ii + (dp[n][i] - ii + 1)/2;

                    jj = count(n/2, j);
                    jj = jj+ (dp[n][j] - jj + 1)/2;
                }
                ans = ans + ii + jj;
            }
        }
    }

    cout << ans << endl;
}