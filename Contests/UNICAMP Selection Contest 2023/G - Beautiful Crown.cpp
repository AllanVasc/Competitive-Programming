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

const int ms = 1e6 + 10;

int fexp(int x, int y){
    int answ = 1;
    while(y){
        if(y & 1) answ = answ * x % MOD;
        x = x * x % MOD;
        y >>= 1;
    }
    return answ;
}

signed main() {
    optimize;

    vector<vector<int>> divisors(ms);
    for(int i = 1; i < ms; i++){ // O(nlogn)
        for(int j = i; j < ms; j += i){
            divisors[j].push_back(i);
        }
    }

    vector<int> phi(ms);
    for(int i = 0; i < ms; i++) phi[i] = i;
    for(int i = 2; i < ms; i++){    // O(nlogn)
        if(phi[i] == i){
            for(int j = i; j < ms; j += i){
                phi[j] -= phi[j] / i;
            }
        }
    }

    int n, m; cin >> n >> m;
    int answ = 0;
    for(int i = 1; i <= n; i++){
        int cnt = 0;
        for(auto d : divisors[i]){
            cnt += fexp(m, d) * phi[i / d] % MOD;
            cnt %= MOD;
        }
        cnt = cnt * fexp(i, MOD - 2) % MOD;
        answ += cnt;
        answ %= MOD;
    }

    cout << answ << '\n';
    return 0;
}