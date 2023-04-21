#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        int answ = 0;
        int l = 1;
        int r = 1e10;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(mid * mid < n){
                answ = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }

        cout << answ << '\n';
    }

    return 0;
}