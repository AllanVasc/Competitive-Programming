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

        vector<int> odd, even;
        for(int i = 0; i < n; i++){
            if(v[i] % 2 == 0) even.push_back(i + 1);
            else odd.push_back(i + 1);
        }

        if(even.size() >= 2 && odd.size() >= 1){
            cout << "YES" << '\n';
            cout << even[0] << " " << even[1] << " " << odd[0] << '\n';
        }
        else if(odd.size() >= 3){
            cout << "YES" << '\n';
            cout << odd[0] << " " << odd[1] << " " << odd[2] << '\n';
        }
        else{
            cout << "NO" << '\n';
        }
    }
    return 0;
}