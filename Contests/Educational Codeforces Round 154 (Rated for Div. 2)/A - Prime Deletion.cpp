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
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        vector<int> pos(10, -1);
        for(int i = 0; i < s.size(); i++){
            pos[s[i] - '0'] = i;
        }
        if(pos[1] < pos [3]){
            cout << 13 << '\n';
        }
        else cout << 31 << '\n';
    }
    return 0;
}