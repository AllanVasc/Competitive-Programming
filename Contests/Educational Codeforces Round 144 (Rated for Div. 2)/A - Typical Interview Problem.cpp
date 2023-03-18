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
        string s;
        cin >> s;

        string pattern = "FBFFBFFB";
        bool has_answ = false;
        for(int i = 0; i < pattern.size(); i++){
            bool check = true;
            for(int j = 0; j < n; j++){
                if(s[j] != pattern[(i + j) % pattern.size()]) check = false;
            }
            if(check) has_answ = true;
        }

        if(has_answ) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}