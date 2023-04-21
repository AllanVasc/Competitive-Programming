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
        vector<int> freq(10, 0);
        for(int i = 0; i < s.size(); i++){
            freq[s[i] - '0']++;
        }

        bool allequal = false;
        bool has3 = false;
        for(int i = 0; i < 10; i++){
            if(freq[i] == 4) allequal = true;
            if(freq[i] == 3) has3 = true;
        }

        if(allequal){
            cout << -1 << '\n';
        }
        else if(has3){
            cout << 6 << '\n';
        }
        else{
            cout << 4 << '\n';
        }
    }

    return 0;
}