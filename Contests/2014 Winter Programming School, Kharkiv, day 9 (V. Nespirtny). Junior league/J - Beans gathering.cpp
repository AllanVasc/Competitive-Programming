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
    
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for(int i = 0; i < n + 1; i++) cin >> v[i];

    bool possible = true;
    int offset = 0;
    for(int i = n; i > 0; i--){
        if((v[i] + offset) % i != 0){
            possible = false;
            break;
        }
        offset += (v[i] + offset) / i;
    }
    cout << (possible ? "Yes" : "No") << '\n';
    return 0;
}