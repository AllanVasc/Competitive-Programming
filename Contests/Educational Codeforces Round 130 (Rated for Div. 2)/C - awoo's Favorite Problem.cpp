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
    // ios::sync_with_stdio(false);
    // cin.tie(0), cout.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        bool has_answ = true;
        int r = 0;
        for(int i = 0; i < n; i++){
            r = max(i, r);
            if(s[i] != t[i]){
                if(s[i] == 'b' && t[i] == 'c'){
                    while(r < n && s[r] == 'b') r++;
                    //cout << "i = " << i << " r = " << r << '\n';
                    if(r == n || s[r] != 'c'){
                        has_answ = false;
                        break;
                    }
                    swap(s[i], s[r]);
                }
                else if(s[i] == 'a' && t[i] == 'b'){
                    while(r < n && s[r] == 'a') r++;
                    //cout << "i = " << i << " r = " << r << '\n';
                    if(r == n || s[r] != 'b'){
                        has_answ = false;
                        break;
                    }
                    swap(s[i], s[r]);
                }
                else{
                    has_answ = false;
                    break;
                }
            }
            else{
                continue;
            }
        }

        if(has_answ) cout << "YES" << '\n';
        else cout << "NO"  << '\n';
    }
    return 0;
}