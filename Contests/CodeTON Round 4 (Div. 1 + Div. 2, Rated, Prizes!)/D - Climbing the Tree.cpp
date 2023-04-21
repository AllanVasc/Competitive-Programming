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
        int q;
        cin >> q;
        ii possible = {0,  INF};
        
        while(q--){
            int cmd;
            cin >> cmd;
            // cout << "\npossible = " << possible.first << " " << possible.second << "\n";
            if(cmd == 1){
                int a, b, n;
                cin >> a >> b >> n;
                int maxH, minH;

                maxH = a * n - b * (n - 1);
                if(n == 1){
                    minH = 1;
                }
                else{
                    minH = a * (n - 1) - b * (n - 1) + b + 1;
                }

                if(maxH < possible.first || minH > possible.second){
                    cout << 0 << " ";
                }
                else{
                    cout << 1 << " ";
                    possible = {max(possible.first, minH), min(possible.second, maxH)};
                }
            }
            else{
                int a, b;
                cin >> a >> b;

                auto [minH, maxH] = possible;
                int first, second;

                if(a >= minH) first = 1;
                else first = (minH - b + (a - b - 1)) / (a - b);
                if(a >= maxH) second = 1;
                else second = (maxH - b + (a - b - 1)) / (a - b);

                // first = max(first, 1LL);
                // second = max(second, 1LL);
                // cout << "\nfirst = " << first << '\n';
                // cout << "\nsecond =" << second << "\n";
                if(first == second){
                    cout << first << " ";
                }
                else{
                    cout << -1 << " ";
                }
            }
        }
        cout << '\n';
    }
    return 0;
}