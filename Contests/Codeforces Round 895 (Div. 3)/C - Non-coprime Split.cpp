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
    int t; cin >> t;
    while(t--){
        int l, r;
        cin >> l >> r;

        if(r < 4){
            cout << -1 << '\n';
            continue;
        }

        if(l != r){
            int a = 2;
            int b;
            if(l <= 2){
                b = 2;
            }
            else{
                if(l & 1){
                    b = l - 2 + 1;
                }
                else b = l - 2;
            }
            cout << a << " " << b << '\n';
        }
        else{
            int b = -1;
            for(int i = 2; i * i <= l; i++){
                if(l % i == 0){
                    b = i;
                    break;
                }
            }

            if(b == -1) cout << -1 << '\n';
            else cout << b << " " << l - b << '\n';
        }
    }
    return 0;
}