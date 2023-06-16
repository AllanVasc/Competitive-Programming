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

int32_t main() {
    optimize;
    
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<set<int>> pq(k);
        for(int i = 0; i < n; i++){
            int aux; cin >> aux;
            pq[i % k].insert(aux);
        }
        vector<int> order(n);
        int miss = 0;
        for(int i = 0; i < n; i++){
            if(pq[i % k].count(i + 1) == 0) miss++;
        }
        if(miss == 0) cout << 0 << '\n';
        else if(miss == 2) cout << 1 << '\n';
        else cout << -1 << '\n';
    }
    return 0;
}