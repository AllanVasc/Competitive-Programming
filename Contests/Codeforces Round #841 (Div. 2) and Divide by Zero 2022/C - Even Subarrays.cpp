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

        vector<int> perfect_sq;
        for(int i = 0; i * i <= 2*n; i++){
            perfect_sq.push_back(i*i);
        }

        vector<int> freq(4*n + 10, 0);
        freq[0] = 1;
        int count = 0;
        int curr_xor = 0;
        for(int i = 0; i < n; i++){
            curr_xor ^= v[i];
            for(int j = 0; j < perfect_sq.size(); j++){
                count += freq[curr_xor ^ perfect_sq[j]];
            }
            freq[curr_xor]++;
        }

        int answ = n * (n + 1) / 2 - count;
        cout << answ << '\n';
    }
    return 0;
}