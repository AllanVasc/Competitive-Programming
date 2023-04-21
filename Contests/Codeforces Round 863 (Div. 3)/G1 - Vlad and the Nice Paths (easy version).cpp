#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int ms = 105;
int dp[ms][ms][ms];
vector<int> v;
int k;

int solve1(int idx, int sum, int last){
    int n = v.size();
    if(idx >= n){
        if(sum % k == 0) return sum;
        else return 0;
    }
    int& answ = dp[idx][sum][last];
    if(answ != -1) return answ;

    answ = 0;
    if(sum % k == 0){
        answ = max(solve1(idx + 1, sum + 1, v[idx]), solve1(idx + 1, sum, last));
    }
    // if(last == 0){
    //     answ = max({answ, solve1(idx + 1, sum + 1, v[idx]), solve1(idx + 1, sum, last)});
    // }
    else if(v[idx] != last){
        answ = max({answ, solve1(idx + 1, 1, v[idx]), solve1(idx + 1, sum, last)});
    }
    else if(v[idx] == last){
        answ = max({answ, solve1(idx + 1, sum + 1, last), solve1(idx + 1, sum, last)});
    }

    return answ;
}

int solve2(int idx, int sum, int last, int sz){
    int n = v.size();
    if(idx >= n){
        if(sum == sz) return 1;
        else return 0;
    }
    int& answ = dp[idx][sum][last];
    if(answ != -1) return answ;

    answ = 0;
    answ += solve2(idx + 1, sum, last, sz);
    answ %= MOD;
    if(sum % k == 0){
        answ += solve2(idx + 1, sum + 1, v[idx], sz);
    }
    else if(v[idx] != last){
        // answ += solve2(idx + 1, 1, v[idx], sz);
    }
    else if(v[idx] == last){
        answ += solve2(idx + 1, sum + 1, last, sz);
    }
    answ %= MOD;
    return answ;
}

void clean(int n){
    for(int i = 0; i <= n; i++){
        for(int j = 0; j < ms; j++){
            for(int l = 0; l < ms; l++){
                dp[i][j][l] = -1;
            }
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n >> k;
        v.assign(n, 0);
        for(int i = 0; i < n; i++) cin >> v[i];

        clean(n);
        int mx = solve1(0,0,0);

        //cout << "Max lenght = " << mx << '\n';

        clean(n);
        cout << solve2(0,0,0,mx) << '\n';
    }
    return 0;
}