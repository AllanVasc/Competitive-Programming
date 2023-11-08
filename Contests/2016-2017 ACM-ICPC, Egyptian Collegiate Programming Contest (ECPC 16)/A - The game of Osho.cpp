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

const int ms = 1e3;
int dp[ms][ms];

int solve(int n, int b){
    if(n == 0) return 0;
    int & answ = dp[n][b];
    if(answ != -1) return answ;

    set<int> mex;
    int curr = 1;
    while(curr <= n){
        mex.insert(solve(n - curr, b));
        curr *= b;
        if(b == 1) break;
    }
    int val = 0;
    while(mex.count(val)) val++;
    answ = val;
    return answ;
}

signed main() {
    optimize;
    
    freopen("powers.in", "r", stdin); // CHANGE
    
    // memset(dp, -1, sizeof dp);
    // for(int i = 1; i < ms; i++){
    //     // cout << "B = " << i << '\n';
    //     for(int j = 0; j < ms; j++){
    //         // cout << "N = " << j << " ";
    //         // cout << (solve(j, i) ? "WIN" : "LOOSE") << " " << solve(j, i) << '\n';
    //         int nim = 0;
    //         int n = j;
    //         int b = i;
    //         if(b & 1){
    //             nim = (n & 1);
    //         }
    //         else{
    //             // par
    //             if(n % (b + 1) == b){
    //                 nim = 2;
    //             }
    //             else{
    //                 n %= (b + 1);
    //                 nim = (n & 1);
    //             }
    //         }
    //         if(nim != solve(j, i)) cout << "error! " << j << " " << i << '\n';
    //     }
    //     // cout << '\n';
    // }


    int t; cin >> t;
    while(t--){
        int qtt; cin >> qtt;
        vector<pii> games(qtt); // (n, b)
        for(int i = 0; i < qtt; i++) cin >> games[i].second >> games[i].first;
        int answ = 0;
        for(int i = 0; i < qtt; i++){
            auto [n, b] = games[i];
            int nim = 0;
            if(b & 1){
                nim = (n & 1);
            }
            else{
                // par
                if(n % (b + 1) == b){
                    nim = 2;
                }
                else{
                    n %= (b + 1);
                    nim = (n & 1);
                }
            }
            // cout << "nim = " << nim << '\n';
            answ ^= nim;
        }

        cout << (answ ? 1 : 2) << '\n';
    }

    return 0;
}