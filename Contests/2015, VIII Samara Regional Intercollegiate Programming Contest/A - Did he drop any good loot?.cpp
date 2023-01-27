#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int maxn = 1e4 + 10;
const int maxw = 750;
vector<iii> v;
int dp[maxn][maxw][3];

int solve(int idx, int w, int activated){

    if(idx < 0) return 0;
    if(dp[idx][w][activated] != -1) return dp[idx][w][activated];

    int extraw = get<0>(v[idx]);
    int price = get<1>(v[idx]);
    int weigth = get<2>(v[idx]);

    int answ = solve(idx - 1, w, activated);

    if(w - weigth >= 0){
        answ = max(answ, price + solve(idx - 1, w - weigth, activated) );
    }
    if(activated < 2 && w - weigth + extraw >= 0){
        answ = max(answ, price + solve(idx - 1, w - weigth + extraw, activated + 1));
    }

    return dp[idx][w][activated] = answ;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i ++){
        int p, w, d;
        cin >> p >> w >> d;
        v.push_back({d, p, w});
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < maxn; i++){
        for(int j = 0; j < maxw; j++){
            for(int k = 0; k < 3; k++){
                dp[i][j][k] = -1;
            }
        }
    }

    cout << solve(n - 1, m, 0) << '\n';
}