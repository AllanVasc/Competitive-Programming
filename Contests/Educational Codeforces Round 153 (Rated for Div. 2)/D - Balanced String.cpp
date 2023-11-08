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

const int ms = 101;
int dp[2][ms][ms*ms];
string s;

signed main() {
    optimize;

    cin >> s;
    int n = s.size();

    int cnt0 = 0, cnt1 = 0;
    for(int i = 0; i < n; i++){
        cnt0 += (s[i] == '0');
        cnt1 += (s[i] == '1');
    }

    dp[0][0][0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i + 1; j++){
            for(int k = 0; k <= j * (i + 1 - j); k++){
                dp[1][j][k] = n;   
            }
        }
        
        for(int j = 0; j <= i; j++){
            for(int cnt = 0; cnt <= j * (i - j); cnt++){
                // boto "0" em "i"
                dp[1][j + 1][cnt] = min(dp[1][j + 1][cnt], dp[0][j][cnt] + (s[i] != '0'));
                // boto "1" em "i"
                dp[1][j][cnt + j] = min(dp[1][j][cnt + j], dp[0][j][cnt] + (s[i] != '1'));
            }
        }
        swap(dp[0], dp[1]);
    }
    cout << dp[0][cnt0][cnt0*cnt1/2] / 2 << '\n';
    return 0;
}