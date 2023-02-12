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
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];

        int answ = 0;
        bool is_even = (v[0] % 2 == 0);
        int curr = 0;
        for(int i = 0; i < n; i++){
            if(v[i] % 2 == 0){
                if(is_even){
                    curr++;
                }
                else{
                    answ += curr - 1;
                    curr = 1;
                    is_even = !is_even;
                }
            }
            else{
                if(!is_even){
                    curr++;
                }
                else{
                    answ += curr - 1;
                    curr = 1;
                    is_even = !is_even;
                }
            }
        }

        answ += max(0LL, curr - 1);
        cout << answ << '\n';
    }

    return 0;
}