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

    int n, k;
    cin >> n >> k;
    vector<int> p(n), c(n);
    for(int i = 0; i < n; i++) cin >> p[i];
    for(int i = 0; i < n; i++) cin >> c[i];

    vector<bool> marked(n, false);
    bool has_ans = true;
    for(int i = 0; i < n; i++){
        int festival = (p[i] + c[i]) % k;
        if(festival >= n){
            has_ans = false;
            break;
        }
        if(marked[festival]){
            has_ans = false;
            break;
        }
        marked[festival] = true;
    }

    if(has_ans){
        cout << "S" << '\n';
    }
    else cout << "N" << '\n';
    return 0;
}