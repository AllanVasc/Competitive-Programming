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

    int n, w;
    cin >> n >> w;

    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    int left = 0;
    int right = w;
    int offset = 0;

    bool has_answ = true;
    for(int i = 0; i < n; i++){
        int y = v[i] + offset;
        // cout << "y = " << y << '\n';
        if(y >= 0){
            int curr = w - y;
            right = min(right, curr);
            // cout << "r = " << right << '\n';
        }
        else{
            int diff = -y;
            left = max(left, diff);
            // cout << "left = " << left << '\n';
        }
        if(left > right) has_answ = false;
        offset += v[i];
    }

    if(has_answ) cout << right - left + 1 << '\n';
    else cout << 0 << '\n';
    return 0;
}