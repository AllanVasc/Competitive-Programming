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
        vector<vector<int>> mp(2, vector<int>(2, 0));

        int cnt = 0;
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 2; j++){
                cin >> mp[i][j];
                cnt += mp[i][j];
            }

        if(cnt == 0){
            cout << 0 << '\n';
        }
        else if(cnt == 4){
            cout << 2 << '\n';
        }
        else{
            cout << 1 << '\n';
        }
    }

    return 0;
}