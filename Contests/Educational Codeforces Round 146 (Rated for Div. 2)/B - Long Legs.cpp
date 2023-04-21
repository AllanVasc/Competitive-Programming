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
        int a, b;
        cin >> a >> b;
        
        int answ = INF;
        int m = 1;
        while(m <= 1e5){
            int curr = (m - 1) + (a + m - 1)/m + (b + m - 1)/m;
            answ = min(answ, curr);
            m++;
        }
        cout << answ << '\n';
    }
    return 0;
}