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
    int n, d;
    cin >> n >> d;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.rbegin(), v.rend());
    int cnt = 0;
    int time = 0;
    for(int i = 0; i < n; i++){
        if(time + v[i] > d){
            cout << -1 << '\n';
            return 0;
        }
        time += v[i];   // time <= d
        if(i != n - 1){
            cnt += 2;
            time += 10;
        }
        else{
            int missing = d - time;
            cnt += (missing) / 5;
        }
    }
    cout << cnt << '\n';
    return 0;
}