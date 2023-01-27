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

        if(n <= 9){
            cout << n << '\n';
        }
        else{
            int digits = log10(n) + 1;
            answ += (digits - 1) * 9;
            int curr = pow(10, digits - 1);
            answ += n / curr;
            cout << answ << '\n';
        }
    }
    
    return 0;
}