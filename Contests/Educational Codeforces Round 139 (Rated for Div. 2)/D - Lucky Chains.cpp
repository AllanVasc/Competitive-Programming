#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    const int ms = 1e7 + 10;
    vector<int> sieve(ms, 0);
    for(int i = 0; i < ms; i++) sieve[i] = i;
    for(int i = 2; i < ms; i++){
        if(sieve[i] == i){
            for(int j = i * i; j < ms; j += i){
                sieve[j] = i;
            }
        }
    }

    while(t--){
        int x, y;
        cin >> x >> y;
        if(x > y) swap(x, y);

        int dif = y - x;
        if(__gcd(x,y) != 1){
            cout << 0 << '\n';
        }
        else if(dif == 1){
            cout << -1 << '\n';
        }
        else{
            int answ = LONG_LONG_MAX;
            while(dif > 1){
                int p = sieve[dif];
                answ = min(answ, p - x % p);
                while(dif % p == 0) dif /= p;
            }
            cout << answ << '\n';
        }
    }
    return 0;
}