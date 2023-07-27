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

vector<pair<int,int>> range;
vector<int> queries;

bool check(int q, int n){
    vector<int> v(n, 0);
    for(int i = 0; i <= q; i++){
        v[queries[i]] = 1;
    }
    vector<int> ps(n + 1, 0);
    for(int i = 1; i <= n; i++){
        ps[i] = ps[i - 1] + v[i - 1];
    }
    for(auto [l, r] : range){
        int qtt = (r - l + 1) / 2 + 1;
        int curr = ps[r + 1] - ps[l];
        if(curr >= qtt) return true;
    }
    return false;
}
signed main() {
    optimize;
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        range.clear();
        queries.clear();
        for(int i = 0; i < m; i++){
            int l, r;
            cin >> l >> r;
            l--, r--;
            range.push_back({l, r});
        }
        int q;
        cin >> q;
        vector<int> v;
        for(int i = 0; i < q; i++){
            int x; cin >> x;
            x--;
            queries.push_back(x);
        }
        int l = 0;
        int r = q - 1;
        int answ = INF;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(check(mid, n)){
                answ = min(answ, mid);
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        cout << (answ == INF ? -1 : answ + 1) << '\n';
    }
    return 0;
}