#include <bits/stdc++.h>
using namespace std;

#define int long long
#define optimize ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define iii tuple<int,int,int>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int ms = 11;
int hotel[ms][ms][ms];
int dp[ms][ms][ms];

int solve(int f, int y, int x){
    if(f < 0 || y >= 10 || x >= 10) return 0;
    int & answ = dp[f][y][x];
    if(answ != -1) return answ;
    answ = hotel[f][y][x];
    answ = max({answ + solve(f, y, x + 1),
                answ + solve(f, y + 1, x),
                answ + solve(f - 1, y, x)});
    return answ;
}

signed main() {
    optimize;
    
    freopen("commandos.in", "r", stdin); // CHANGE
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        memset(hotel, 0, sizeof hotel);
        for(int i = 0; i < n; i++){
            int f, y, x, h;
            cin >> f >> y >> x >> h;
            f--, y--, x--;
            hotel[f][y][x] = max(hotel[f][y][x], h);
        }
        memset(dp, -1, sizeof dp);
        cout << solve(9, 0, 0) << '\n';
    }

    return 0;
}