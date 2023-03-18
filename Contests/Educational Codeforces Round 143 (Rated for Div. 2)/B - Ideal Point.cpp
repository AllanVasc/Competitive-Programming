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
        int n, k;
        cin >> n >> k;
        vector<ii> v(n);
        vector<int> freq(100, 0);
        for(int i = 0; i < n; i++){
            int l, r;
            cin >> l >> r;
            if(k >= l && k <= r){
                for(int j = l; j <= r; j++){
                    freq[j]++;
                }
            }
        }

        int val = freq[k];
        bool has_answ = true;
        for(int i = 0; i < freq.size(); i++){
            if(freq[i] == val && i != k){
                has_answ = false;
            }
        }
        if(has_answ) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}