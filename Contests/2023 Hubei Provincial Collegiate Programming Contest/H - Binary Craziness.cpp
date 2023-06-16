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

int32_t main() {
    optimize;
    
    int n, m;
    cin >> n >> m;
    vector<int> degree(n, 0);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        degree[u]++;
        degree[v]++;
    }
    map<int,int> freq;
    vector<int> uniqueDegree;
    for(int i = 0; i < n; i++){
        if(freq[degree[i]] == 0){
            uniqueDegree.push_back(degree[i]);
        }
        freq[degree[i]]++;
    }

    int answ = 0;
    for(int i = 0; i < uniqueDegree.size(); i++){
        for(int j = i + 1; j < uniqueDegree.size(); j++){
            answ += freq[uniqueDegree[i]] * freq[uniqueDegree[j]] % MOD 
            * ((uniqueDegree[i] ^ uniqueDegree[j]) % MOD) % MOD 
            * ((uniqueDegree[i] | uniqueDegree[j]) % MOD) % MOD
            * ((uniqueDegree[i] & uniqueDegree[j]) % MOD) % MOD;
            answ %= MOD;
        }
    }
    cout << answ << '\n';
    return 0;
}