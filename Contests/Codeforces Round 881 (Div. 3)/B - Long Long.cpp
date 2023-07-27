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
        int n;
        cin >> n;
        int total = 0;
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
            total += abs(v[i]);
        }
        int op = 0;
        for(int i = 0; i < n; i++){
            if(v[i] >= 0) continue;
            op++;
            for(int j = i + 1; j < n; j++){
                if(v[j] > 0) break;
                i = j;
            }
        }
        cout << total << " " << op << '\n';
    }
    return 0;
}