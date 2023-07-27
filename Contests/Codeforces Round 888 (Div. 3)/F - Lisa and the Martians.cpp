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
    int t;
    cin >> t;
    while(t--){
        int n, m, k, h;
        cin >> n >> m >> k >> h;
        vector<int> pH(n);
        for(int i = 0; i < n; i++){
            cin >> pH[i];
        }
        set<int> possible;
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= m; j++){
                if(j == i) continue;
                for(int pp = 0; pp < n; pp++){
                    if(abs(pH[pp] - h) == abs((j - i)*k)){
                        possible.insert(pp);
                    }
                }
            }
        }
        cout << possible.size() << '\n';
    }
    return 0;
}