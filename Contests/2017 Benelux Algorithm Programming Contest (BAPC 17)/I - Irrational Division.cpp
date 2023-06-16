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

const int ms = 105;
int dp[ms][ms][2];
int p, q;

int calc(int row, int col, bool black){
    if((row % 2 == 0) || (col % 2 == 0)) return 0;
    return (black ? 1 : -1);
}

int solve(int westPos, int southPos, bool player){
    if(westPos >= q || southPos < 0){
        return 0;
    }
    int & answ = dp[westPos][southPos][player];
    if(answ != -INF) return answ;
    if(!player){
        int sum = 0;
        for(int i = westPos; i < q; i++){
            sum += calc(southPos + 1, 1, !(i & 1));
            answ = max(answ, sum + (calc(southPos + 1, q - i - 1, i & 1) - 
                                    solve(i + 1, southPos, !player)));
        }
        return answ;
    }
    else{
        int sum = 0;
        for(int i = southPos; i >= 0; i--){
            if(westPos % 2 == 0){
                if(i % 2 == 0) sum += calc(1, q - westPos, true);
                else sum += calc(1, q - westPos, false);
            }
            else{
                if(i % 2 == 0) sum += calc(1, q - westPos, false);
                else sum += calc(1, q - westPos, true);
            }
            answ = max(answ, sum + (calc(i, q - westPos, !(westPos & 1)) 
                                    - solve(westPos, i - 1, !player)));
        }
        return answ;
    }
}

int32_t main() {
    optimize;
    
    cin >> p >> q;
    for(int i = 0; i < ms; i++){
        for(int j = 0; j < ms; j++){
            for(int k = 0; k < 2; k++){
                dp[i][j][k] = -INF;
            }
        }
    }
    cout << 2 * solve(0, p - 1, false) - calc(p, q, true) << '\n';
    return 0;
}