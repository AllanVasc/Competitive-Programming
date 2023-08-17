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

// a^x % m = b % m
// gcd(a, m) != 1
int discreteLog(int a, int b, int m){
    a %= m, b %= m;
    int k = 1, add = 0, g;
    while((g = __gcd(a, m)) > 1){
        if(b == k) return add;
        if(b % g) return INF;
        b /= g, m /= g, add++;
        k = (k * a / g) % m;
    }
    int block = sqrt(m) + 1, an = 1;
    for(int i = 0; i < block; i++) an = an * a % m;
    map<int,int> vals;
    for(int q = 0, cur = b; q <= block; q++){
        vals[cur] = q;
        cur = cur * a % m;
    }
    int answ = INF;
    for(int p = 1, cur = k; p <= block; p++){
        cur = cur * an % m;
        if(vals.count(cur)){
            answ = min(answ, block*p - vals[cur] + add);
            return answ; // (This value is already the minimum)
        }
    }
    return answ;
}

signed main() {
    optimize;
    int x, z, k;
    while(cin >> x >> z >> k){
        if(!x && !z && !k) break;

        // k % z = x^y % z
        int answ = discreteLog(x, k, z);
        cout << (answ == INF ? "No Solution" : to_string(answ)) << '\n';
    }
    return 0;
}