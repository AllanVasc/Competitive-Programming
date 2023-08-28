#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MAXN = 1e6 + 5, mod = 1e9 + 7;
int fact[MAXN];

int fExp(int a, int b){
    int ans = 1;

    while(b){
        if(b & 1) ans = ans * a % mod;
        a = a*a % mod;
        b  >>= 1;
    }

    return ans;
}

int inv(int x){
    return fExp(x, mod - 2);
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    fact[0] = 1;
    for(int i = 1; i < 1e6 + 5; i++){
        fact[i] = i * fact[i - 1] % mod;
    }

    int n, k;
    cin >> n >> k;
    map <int, int> freq;
    int mul = 1;
    vector <int> v(n);

    for(int i = 0; i < n; i++){
        cin >> v[i];
        freq[v[i]]++;
    }

    for(auto i:freq){
        mul = (mul * fact[i.second] % mod) % mod;
    }

    cout << mul * inv(fact[n]) % mod << "\n";

    for(int i = 0; i < k; i++){
        int x, val;
        cin >> x >> val;
        x--;

        // mul = mul * inv(freq[v[x]]) % mod;
        mul = mul * inv(fact[freq[v[x]]]) % mod;
        // cout << mul << "\n";
        freq[v[x]]--;
        if(freq[v[x]]){
            // mul = mul * freq[v[x]] % mod;
            mul = mul * fact[freq[v[x]]] % mod;
        }
        // cout << mul << "\n";

        if(freq[val] > 0){
            // mul = mul * inv(freq[val]) % mod;
            mul = mul * inv(fact[freq[val]]) % mod;
        }
        // cout << mul << "\n";
        freq[val]++;
        // mul = mul * freq[val] % mod;
        mul = mul * fact[freq[val]] % mod;
        // cout << mul << "\n";

        v[x] = val;
        cout << mul * inv(fact[n]) % mod << "\n";
    }

    return 0;
}