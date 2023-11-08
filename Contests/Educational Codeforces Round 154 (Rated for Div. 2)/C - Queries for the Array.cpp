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
        int sz = 0, sorted = 0, unsorted = INF;
        bool f = true;
        for(int i = 0; i < s.size(); i++){
            switch(s[i]){
                case '+': sz++; break;
                case '-': sz--; break;
                case '1': sorted = sz; break;
                case '0': if(unsorted == INF) unsorted = sz; break;
            }
            if(sorted > sz) sorted = sz;
            if(sz < unsorted) unsorted = INF;
            if((s[i] == '0' && sz < 2) || (s[i] == '1' && unsorted <= sz) || (s[i] == '0' && sorted == sz)){
                f = false;
                break;
            }
        }
        cout << (f ? "YES" : "NO") << '\n';
    }
    return 0;
}