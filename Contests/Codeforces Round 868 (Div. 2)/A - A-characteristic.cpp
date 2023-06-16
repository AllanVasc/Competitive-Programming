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

        bool found = false;
        for(int i = 0; i <= n; i++){
            int answ = (n*(n - 1)/2) - i * (n - i);
            if(answ == k){
                cout << "YES" << '\n';
                for(int j = 0; j < i; j++){
                    cout << -1 << " ";
                }
                for(int j = 0; j < (n - i); j++){
                    cout << 1 << " ";
                }
                cout << '\n';
                found = true;
                break;
            }
        }
        if(!found) cout << "NO" << '\n';
    }
    return 0;
}