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

signed main() {
    optimize;
    
    freopen("jumping.in", "r", stdin); // CHANGE
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> v(n);
        vector<vector<int>> g(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        for(int i = 0; i < n; i++){
            int d = v[i];
            if(i + d < n) g[i + d].push_back(i);
            if(i - d >= 0) g[i - d].push_back(i);
        }

        queue<int> q;
        vector<int> answ(n, INF);
        answ[n - 1] = 0;
        q.push(n - 1);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto v : g[u]){
                if(answ[u] + 1 < answ[v]){
                    answ[v] = answ[u] + 1;
                    q.push(v);
                }
            }
        }
        for(int i = 0; i < n; i++){
            cout << (answ[i] == INF ? -1 : answ[i]) << '\n';
        }
    }

    return 0;
}