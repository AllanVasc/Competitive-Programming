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
        int n, m, d;
        cin >> n >> m >> d;
        vector<int> stores(m + 2);
        for(int i = 0; i < m; i++) cin >> stores[i + 1];
        stores[0] = -d + 1;
        stores[m + 1] = n + 1;

        int tot = 0;
        for(int i = 1; i <= m + 1; i++){
            tot += (stores[i] - stores[i - 1] - 1) / d;
        }
        map<int, int> freq;
        for(int i = 1; i <= m; i++){
            int cnt = tot;
            cnt -= (stores[i] - stores[i - 1] - 1) / d;
            cnt -= (stores[i + 1] - stores[i] - 1) / d;
            cnt += (stores[i + 1] - stores[i - 1] - 1) / d;
            cnt += m - 1;
            freq[cnt]++;
        }
        for(auto x : freq){
            cout << x.first << " " << x.second << '\n';
            break;
        }
    }
    return 0;
}