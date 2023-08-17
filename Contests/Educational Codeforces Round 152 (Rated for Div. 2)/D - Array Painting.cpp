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
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    vector<int> compressed;
    for(int l = 0; l < n;){
        int mx = 0;
        while(l < n && v[l]){
            mx = max(mx, v[l]);
            l++;
        }
        if(mx) compressed.push_back(mx);
        if(l < n){
            compressed.push_back(0);
            l++;
        }
    }
    // for(auto x : compressed) cout << x << " ";
    // cout << '\n';
    vector<vector<int>> pos(3);
    n = compressed.size();
    for(int i = 0; i < n; i++){
        pos[compressed[i]].push_back(i);
    }
    vector<bool> painted(n, false);
    int answ = 0;
    for(auto x : pos[2]){
        answ++;
        if(x > 0) painted[x - 1] = true;
        if(x + 1< n) painted[x + 1] = true;
    }
    for(auto x : pos[1]){
        answ++;
        if(x > 0 && !painted[x - 1]) painted[x - 1] = true;
        else if(x + 1 < n && !painted[x + 1]) painted[x + 1] = true;
    }
    for(auto x : pos[0]){
        if(!painted[x]) answ++;
    }
    cout << answ << '\n';
    return 0;
}