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

        char last = ' ';
        map<string,bool> mp;
        bool has_answ = false;
        for(int i = 0; i < n - 1; i++){
            string check;
            check.push_back(s[i]);
            check.push_back(s[i + 1]);

            if(mp[check]){
                has_answ = true;
                break;
            }
            string add;
            add.push_back(last);
            add.push_back(s[i]);
            // cout << "botei " << add << '\n';
            last = s[i];
            mp[add] = true;
        }
        
        cout << (has_answ ? "YES" : "NO") << '\n'; 
    }
    
    return 0;
}