#include <bits/stdc++.h>
using namespace std;

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

const int ms = sqrt(1e9 + 5) + 1;
signed main() {
    optimize;
    int t;
    cin >> t;
    vector<bool> isprime(ms + 1, true);
    isprime[0] = isprime[1] = false;
    for(int i = 2; i <= ms; i++){
        if(isprime[i]){
            for(int j = i * i; j <= ms; j += i){
                isprime[j] = false;
            }
        }
    }
    vector<int> primes;
    for(int i = 2; i <= ms; i++){
        if(isprime[i]) primes.push_back(i);
    }

    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        unordered_map<int,int> freq;
        bool found = false;
        for(int i = 0; i < n && !found; i++){
            int idx = 0;
            int sz = primes.size();
            while(v[i] > 1 && idx < sz && v[i] >= primes[idx] * primes[idx]){
                int x = primes[idx];
                if(v[i] % x == 0){
                    int val = ++freq[x];
                    if(val >= 2) found = true;
                }
                while(v[i] % x == 0){
                    v[i] /= x;
                }
                idx++;
            }
            if(v[i] > 1){
                int val = ++freq[v[i]];
                if(val >= 2) found = true;
            }
        }
        cout << (found ? "YES" : "NO") << '\n';
    }
    return 0;
}