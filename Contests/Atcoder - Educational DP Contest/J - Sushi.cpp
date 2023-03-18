#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int MAXN = 305;
long double dp[MAXN][MAXN][MAXN];
int n;

long double solve(int i, int j, int k){
    if(i + j + k == 0) return 0.0;
    long double & ans = dp[i][j][k];
    if(ans > 0.0) return ans;
    ans = 0;
    if(i){
        ans += (double) i / (i + j + k) * solve(i - 1, j, k);
    }
    if(j){
        ans += (double) j / (i + j + k) * solve(i + 1, j - 1, k);
    }
    if(k){
        ans += (double) k / (i + j + k) * solve(i, j + 1, k - 1);
    }
    ans += (double) n / (i + j + k);
    return ans;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    vector<int> freq(4, 0);
    for(int i = 0; i < n; i++){
        int aux;
        cin >> aux;
        freq[aux]++;
    }
    for(int i = 0; i < MAXN; i++){
        for(int j = 0; j < MAXN; j++){
            for(int k = 0; k < MAXN; k++){
                dp[i][j][k] = -1;
            }
        }
    }
    cout << fixed << setprecision(10);
    cout << solve(freq[1], freq[2], freq[3]) << '\n';
    return 0;
}