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
    map<string, double> mp;
    mp["pink"] = log(1.0);
    for(int i = 0; i < n; i++){
        string win, lose;
        double r;
        cin >> win >> lose >> r;
        if(mp.count(lose) == 0) continue;
        if(mp.count(win) == 0) mp[win] = log(r) + mp[lose];
        else mp[win] = max(mp[win], log(r) + mp[lose]);
    }
    cout << setprecision(8) << fixed;
    if(mp.count("blue") == 0){
        cout << 0.0 << '\n';
    }
    else if(mp["blue"] > 20){
        cout << 10.0 << '\n';
    }
    else{
        cout << min(10.0, exp(mp["blue"])) << '\n';
    }
    return 0;
}