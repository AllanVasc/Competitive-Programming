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
        int negNeed = ((n * (n + 1)) / 2) - k;
        vector<int> v(n, 2);

        vector<int> changed(n, 0);
        int idx = 0;
        while(negNeed){
            if(changed[idx] != (n - idx)){
                if(changed[idx] == 0){
                    v[idx] = -1;
                }
                else{
                    v[idx] -= 2;
                }
                negNeed--;
                changed[idx]++;
            }
            else{
                idx++;
            }
        }

        for(int i = 0; i < n; i++){
            cout << v[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}