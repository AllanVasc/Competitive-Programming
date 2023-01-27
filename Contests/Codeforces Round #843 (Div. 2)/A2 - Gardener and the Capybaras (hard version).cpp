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
        string s;
        cin >> s;
        
        int idx = 0;
        bool has_a = false;
        for(int i = 1; i < s.size() - 1; i++){
            if(s[i] == 'a'){
                has_a = true;
                idx = i;
                break;
            }
        }

        if(has_a){
            for(int i = 0; i < idx; i++){
                cout << s[i];
            }
            cout << " a ";
            for(int i = idx + 1; i < s.size(); i++){
                cout << s[i];
            }
            cout << '\n';
        }
        else{
            cout << s[0] << " ";
            for(int i = 1; i < s.size() - 1; i++){
                cout << s[i];
            }
            cout << " " << s.back() << '\n';
        }
    }
    return 0;
}