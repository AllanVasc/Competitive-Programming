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
    vector<int> odd;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x & 1) odd.push_back(i);
    }
    if(odd.size() & 1){
        cout << -1 << '\n';
        return 0;
    }
    if(odd.size()) odd.push_back(n + odd[0]);
    int a, b;
    cin >> a >> b;
    int op1 = 0, op2 = 0;
    for(int i = 0; i + 1 < odd.size(); i += 2){
        op1 += odd[i + 1] - odd[i];
    }
    for(int i = 1; i + 1 < odd.size(); i += 2){
        op2 += odd[i + 1] - odd[i];
    }
    // cout << op1 << " " << op2 << '\n';
    cout << min(op1, op2) * min(a, b) << '\n';
    return 0;
}