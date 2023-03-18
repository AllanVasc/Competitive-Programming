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
        map<char, int> minPos;
        bool has_answ = true;
        bool foundM, foundE, foundO, foundW;
        foundM = foundE = foundO = foundW = false;
        int pointer = 0;
        while(pointer < n && tolower(s[pointer]) == 'm'){
            pointer++;
            foundM = true;
        }
        if(pointer == n) has_answ = false;
        while(pointer < n && tolower(s[pointer]) == 'e'){
            pointer++;
            foundE = true;
        }
        if(pointer == n) has_answ = false;
        while(pointer < n && tolower(s[pointer]) == 'o'){
            pointer++;
            foundO = true;
        }
        if(pointer == n) has_answ = false;
        while(pointer < n && tolower(s[pointer]) == 'w'){
            pointer++;
            foundW = true;
        }

        if(has_answ && foundM && foundE && foundO && foundW && pointer == n) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}