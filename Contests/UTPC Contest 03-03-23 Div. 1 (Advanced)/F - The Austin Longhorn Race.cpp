#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

vector<tuple<int,int,int,int>> points;
const int ms = 5e3 + 100;
int dp[ms][ms];

int sq(int x){
    return x * x;
}

int dist(int x1, int y1, int x2, int y2){
    return sq(x1 - x2) + sq(y1 - y2);
}

int solve(int curr, int last){
    int n = points.size();
    if(curr >= n) return 0;
    int& answ = dp[curr][last];
    if(answ != -1) return answ;

    answ = 0;
    auto [t_cur, v_cur, x_cur,y_cur] = points[curr];
    auto [t_last, v_last, x_last, y_last] = points[last];
    // nao pego esse ponto
    answ = max(answ, solve(curr + 1, last));

    // pego se cheguei a tempo
    if(sqrtl(dist(x_cur, y_cur, x_last, y_last)) + t_last <= t_cur){
        answ = max(answ, v_cur + solve(curr + 1, curr));
    }

    return answ;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    points.emplace_back(0,0,0,0);
    for(int i = 0; i < n; i++){
        int x, y, t, c;
        cin >> x >> y >> t >> c;
        points.emplace_back(t,c,x,y);
    }
    sort(points.begin(), points.end());

    memset(dp, -1, sizeof dp);
    cout << solve(1,0) << '\n';

    return 0;
}