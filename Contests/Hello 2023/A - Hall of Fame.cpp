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

        bool foundRL = false;
        bool foundLR = false;
        int answ = -1;
        for(int i = 0; i < n - 1; i++){
            if(s[i] == 'R' && s[i + 1] == 'L') foundRL = true;
            if(s[i] == 'L' && s[i + 1] == 'R'){
                foundLR = true;
                answ = i;
            }
        }

        if(foundRL){
            cout << 0 << '\n';
        }
        else if(foundLR){
            cout << answ + 1 << '\n';
        }
        else{
            cout << -1 << '\n';
        }
    }
    return 0;
}