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
        int x;
        cin >> x;
        vector<int> v(3);
        for(int i = 0; i < 3; i++) cin >> v[i];

        x--;
        int cnt = 0;
        while(x != -1){
            x = v[x];
            x--;
            cnt++;
        }

        if(cnt == 3){
            cout << "YES" << '\n';
        }
        else{
            cout << "NO" << "\n";
        }
    }

    return 0;
}