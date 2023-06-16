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
    
    int n;
    cin >> n;
    vector<pii> v;
    for(int i = 0 ; i < n; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 > x2) swap(x1, x2);
        v.push_back({x1, x2});
    }
    sort(ALL(v));
    int mx = 0;
    int answ = 0;
    for(int i = 0 ; i < n; i++){
        auto [x1, x2] = v[i];
        // cout << "x1 = " << x1 << " x2 = " << x2 << '\n';
        if(mx >= x2){
            continue;
        }
        else if(mx >= x1 && mx <= x2){
            answ += x2 - mx;
        }
        else{
            answ += x2 - x1;
        }
        mx = max(mx, x2);
        // cout << "mx = " << mx << '\n';
        // cout << answ << '\n';
    }
    cout << answ << '\n';
    return 0;
}