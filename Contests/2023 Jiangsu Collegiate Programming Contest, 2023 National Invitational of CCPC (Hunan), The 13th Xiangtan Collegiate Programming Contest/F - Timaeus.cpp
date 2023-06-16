#include <bits/stdc++.h>
using namespace std;


#define int long long
#define ld long double
const int ms = 2e6 + 100;


bool memo[ms];
ld dp[ms];
int A, B, P, Q;
ld p, q;
ld solve(int a){
    if(a < B) return 0;

    if(memo[a]) return dp[a];
    memo[a] = true;
    if(B == 1){
        ld aux = ((1-q)*(1 + solve(a-1)) + q)/(1-q);
        dp[a] = max(aux, p*(2 + solve(a-B)) + (1-p)*(1 + solve(a-B)));
    }
    else dp[a] = max(p*(2 + solve(a-B)) + (1-p)*(1 + solve(a-B)), q*(1 + solve(a-B+1)) + (1-q)*(1 + solve(a-B)));

    return dp[a];

} 

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << setprecision(10) << fixed;
    cin >> A >> B >> P >> Q;
    p = P/100.0l, q = Q/100.0l;
    cout << solve(A) << endl;

    return 0;
}
