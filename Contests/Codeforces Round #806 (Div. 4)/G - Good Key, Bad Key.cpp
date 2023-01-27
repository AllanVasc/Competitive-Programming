// G - Good Key, Bad Key
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18;

const int MAXN = 1e5 + 10;
int dp[MAXN][34];
vector<int> v;

int solve(int idx, int halves, int n, int k){

    if(idx == n) return 0;
    if(halves >= 32) return 0;

    if(dp[idx][halves] != -1) return dp[idx][halves];

    int curr_val = v[idx];
    for(int i = 0; i < halves; i++) curr_val /= 2;

    int answ = max(curr_val - k + solve(idx+1, halves, n, k),
                    curr_val/2 + solve(idx+1, halves+1, n, k));
    
    return dp[idx][halves] = answ;
}

int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n,k;
        cin >> n >> k;

        for(int i = 0; i < n; i++){
            int aux;
            cin >> aux;
            v.push_back(aux);
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < 34; j++){
                dp[i][j] = -1;
            }
        }

        cout << solve(0,0,n,k) << '\n';
        v.clear();
    }
    
    return 0;
}
