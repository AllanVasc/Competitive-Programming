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
        vector<int> appear(n + m + 100, -1);
        vector<int> cnt(n + m + 100, 0);
        int k = m + 1;
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
            appear[v[i]] = 0;
        }
        for(int i = 1; i <= m; i++){
            int pos, val;
            cin >> pos >> val;
            pos--;
            int old = v[pos];
            cnt[old] += i - appear[old];
            appear[old] = -1;
            appear[val] = i;
            v[pos] = val;
        }
        for(int i = 0; i <= n + m; i++){
            if(appear[i] != -1){
                cnt[i] += m + 1 - appear[i];
            }
        }
        int answ = 0;
        for(int i = 0; i <= n + m; i++){
            if(!cnt[i]) continue;
            answ += (k *(k - 1))/2 - (k - cnt[i])*(k - cnt[i] - 1) / 2;
        }
        cout << answ << '\n';
    }
    return 0;
}