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
        int n, m;
        cin >> n >> m;
        string s; cin >> s;
        vector<int> closer1(n, n);
        for(int i = n - 1; i >= 0; i--){
            if(i == n - 1) closer1[i] = (s[i] == '1' ? i : n);
            else{
                if(s[i] == '1') closer1[i] = i;
                else closer1[i] = closer1[i + 1];
            }
        }
        vector<int> closer0(n, -1);
        for(int i = 0; i < n; i++){
            if(i == 0) closer0[0] = (s[0] == '0' ? 0 : -1);
            else{
                if(s[i] == '0') closer0[i] = i;
                else closer0[i] = closer0[i - 1];
            }
        }
        // cout << "closer 1: ";
        // for(auto x : closer1) cout << x << " ";
        // cout << '\n';
        // cout << "closer 0: ";
        // for(auto x : closer0) cout << x << " ";
        // cout << '\n';
        set<pii> answ;
        while(m--){
            int l, r;
            cin >> l >> r;
            l--, r--;
            int nl = closer1[l];
            int nr = closer0[r];
            if(nl >= nr) answ.insert({-1, -1});
            else answ.insert({nl, nr});
        }
        cout << answ.size() << '\n';
    }
    return 0;
}