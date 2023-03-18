#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 998244353;

const int MAXN = 3e5 + 100;
int fat[MAXN], invfat[MAXN];

int fexp(int x, int y){
    int answ = 1;
    x %= MOD;
    while(y){
        if(y & 1) answ = answ * x % MOD;
        x = x * x % MOD;
        y >>= 1;
    }
    return answ;
}

int comb(int x, int y){
    return (fat[x] * invfat[y] % MOD * invfat[x - y] % MOD);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    fat[0] = invfat[0] = 1;
    for(int i = 1; i < MAXN ; i++){
        fat[i] = fat[i - 1] * i % MOD;
        invfat[i] = fexp(fat[i], MOD - 2) % MOD;
    }

    int answ = 1;
    int n;
    cin >> n;
    for(int i = 0; i < n / 3; i++){
        vector<int> v(3);
        for(int j = 0; j < 3; j++) cin >> v[j];
        sort(v.begin(), v.end());
        if(v[0] == v[1] && v[1] == v[2]) answ *= 3;
        else if(v[0] == v[1]) answ *= 2;
        answ %= MOD;
    }

    cout << answ * comb(n/3, n/6) % MOD << '\n';
    return 0;
}