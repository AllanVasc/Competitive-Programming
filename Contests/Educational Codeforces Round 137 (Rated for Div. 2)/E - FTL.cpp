#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int p1, t1;
    int p2, t2;
    int h, s;
    cin >> p1 >> t1 >> p2 >> t2 >> h >> s;

    vector<int> dp(h + 5, INF);
    dp[0] = 0;
    for(int i = 1; i <= h; i++){
        for(int j = 0; j < 2; j++){
            int T = (j == 0 ? i * t1 : i * t2); // intervalo ate o proximo tiro duplo
            int shoots1 = T/t1 - 1;
            int shoots2 = T/t2 - 1;
            int dmg = 0;
            if(shoots1 >= 0 && shoots2 >= 0) dmg = shoots1 * (p1 - s) + shoots2 * (p2 - s) + p1 + p2 - s;
            else if(shoots1 >= 0) dmg = (shoots1 + 1) * (p1 - s);
            else if(shoots2 >= 0) dmg = (shoots2 + 1) * (p2 - s);

            for(int k = 0; k <= h; k++){
                if(k + dmg > h) dp[h] = min(dp[h], dp[k] + T);
                else dp[k + dmg] = min(dp[k + dmg], dp[k] + T);
            }
        }
    }

    cout << dp[h] << '\n';
    return 0;
}