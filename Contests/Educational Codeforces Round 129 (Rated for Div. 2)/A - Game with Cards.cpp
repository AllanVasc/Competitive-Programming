#include <bits/stdc++.h>
using namespace std;

#define int long long
#define optimize ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ALL(x) x.begin(), x.end()
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
        int n, m;
        cin >> n;
        vi alice(n);
        int maxAlice = 0;
        int maxBob = 0;
        for(int i = 0; i < n; i++){
            cin >> alice[i];
            maxAlice = max(maxAlice, alice[i]);
        }
        cin >> m;
        vi bob(m);
        for(int i = 0; i < m; i++){
            cin >> bob[i];
            maxBob = max(maxBob, bob[i]);
        }

        if(maxAlice > maxBob){
            cout << "Alice" << '\n';
            cout << "Alice" << '\n';
        }
        else if(maxAlice < maxBob){
            cout << "Bob" << '\n';
            cout << "Bob" << '\n';
        }
        else{
            cout << "Alice" << '\n';
            cout << "Bob" << '\n';
        }
    }
    return 0;
}