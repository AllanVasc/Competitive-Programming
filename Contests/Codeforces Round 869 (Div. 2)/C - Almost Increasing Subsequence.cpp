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

int32_t main() {
    optimize;
    
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    vector<int> ps(n - 1, 0);
    for(int i = 1; i < n - 1; i++){
        int decresing = (v[i - 1] >= v[i] && v[i] >= v[i + 1]);
        ps[i] = ps[i - 1] + decresing;
    }
    while(q--){
        int l, r;
        cin >> l >> r;
        l--, r--;
        if(l == r){
            cout << 1 << '\n';
        }
        else{
            cout << (r - l + 1) - (ps[r - 1] - ps[l]) << '\n';
        }
    }
    return 0;
}