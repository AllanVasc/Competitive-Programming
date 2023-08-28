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
    int n, v; cin >> n >> v;
    set<int> can;
    for(int i = 0; i < n; i++){
        int qtt; cin >> qtt;
        for(int j = 0; j < qtt; j++){
            int x; cin >> x;
            if(x < v) can.insert(i + 1);
        }
    }
    cout << can.size() << '\n';
    for(auto x : can) cout << x << " ";
    cout << '\n';
    return 0;
}