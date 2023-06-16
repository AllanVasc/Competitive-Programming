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
const int MOD = 998244353;

int fexp(int x, int y, int m){
    int answ = 1;
    x = x % m;
    while(y){
        if(y & 1) answ = answ * x % m;
        x = x * x % m;
        y >>= 1;
    }
    return answ;
}

int32_t main() {
    optimize;
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int p = fexp(m - i, n, MOD);
        int q = fexp(m - 1, n, MOD);
        int answ = p * fexp(q, MOD - 2, MOD) % MOD;
        cout << answ << " ";
    }
    cout << '\n';
    return 0;
}