#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int MAXN = 1e5 + 100;
int dp[MAXN][5];
vector<int> a;
vector<int> b;
vector<int> c;

int solve(int idx, int last){
    int n = a.size();
    if(idx >= n) return 0;
    int & answ = dp[idx][last];
    if(answ != -1) return answ;

    if(last == 0){
        answ = max( b[idx] + solve(idx + 1, 1), 
                    c[idx] + solve(idx + 1, 2));
    }
    else if(last == 1){
        answ = max( a[idx] + solve(idx + 1, 0), 
                    c[idx] + solve(idx + 1, 2));
    }
    else{
        answ = max( a[idx] + solve(idx + 1, 0), 
                    b[idx] + solve(idx + 1, 1));
    }
    return answ;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    a.assign(n, 0);
    b.assign(n, 0);
    c.assign(n, 0);

    for(int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i];
    int answ = -1;
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < 3; i++){
        answ = max(answ, solve(0, i));
    }

    cout << answ << '\n';
    return 0;
}