#include <bits/stdc++.h>
using namespace std;

#define int long long
#define optimize ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define iii tuple<int,int,int>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

signed main() {
    optimize;
    int t;
    cin >> t;
    while(t--){
        vector<string> s(2);
        cin >> s[0] >> s[1];
        int n = s[0].size();
        int t, q;
        cin >> t >> q;
        int dif = 0;
        int difBlocked = 0;
        for(int i = 0; i < n; i++){
            dif += (s[0][i] != s[1][i]);
        }
        // cout << "dif = " << dif << '\n';
        vector<int> unblock(q + 100, 0);
        for(int i = 0; i < q; i++){
            // cout << "i = " << i << '\n';
            // cout << s[0] << '\n';
            // cout << s[1] << '\n';
            int cmd;
            cin >> cmd;
            difBlocked -= unblock[i];
            if(cmd == 1){
                // block
                int pos; 
                cin >> pos;
                pos--;
                if(s[0][pos] != s[1][pos]) difBlocked++;
                if(i + t <= q + 10){
                    if(s[0][pos] != s[1][pos]) unblock[i + t] = 1;
                }
            }
            if(cmd == 2){
                // Swap
                int t1, pos1, t2, pos2;
                cin >> t1 >> pos1 >> t2 >> pos2;
                t1--, t2--, pos1--, pos2--;
                if(s[t1][pos1] != s[!t1][pos1]) dif--;
                if(s[t2][pos2] != s[!t2][pos2]) dif--;
                swap(s[t1][pos1], s[t2][pos2]);
                if(s[t1][pos1] != s[!t1][pos1]) dif++;
                if(s[t2][pos2] != s[!t2][pos2]) dif++;
            }
            if(cmd == 3){
                // Query
                cout << (dif == difBlocked ? "YES" : "NO") << '\n';
            }
        }
    }
    return 0;
}