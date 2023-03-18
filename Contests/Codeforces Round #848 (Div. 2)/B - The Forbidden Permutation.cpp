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
        int n, m, d;
        cin >> n >> m >> d;
        vector<int> perm(n);
        for(int i = 0; i < n; i++) cin >> perm[i];
        map<int,int> pos;
        for(int i = 0; i < n; i++){
            pos[perm[i]] = i;
        }
        vector<int> arr(m);
        for(int i = 0; i < m; i++) cin >> arr[i];

        int answ = LONG_LONG_MAX;
        for(int i = 1; i < m; i++){
            if(pos[arr[i]] < pos[arr[i - 1]] || pos[arr[i - 1]] + d < pos[arr[i]]){
                answ = 0;
                break;
            }
            answ = min(answ, pos[arr[i]] - pos[arr[i - 1]]);

            int check2 = pos[arr[i - 1]] - (pos[arr[i]] - d) + 1;
            if(check2 <= pos[arr[i - 1]] + (n - 1 - pos[arr[i]]) ){
                answ = min(answ, check2);
            }
        }
        cout << answ << '\n';
    }
    return 0;
}