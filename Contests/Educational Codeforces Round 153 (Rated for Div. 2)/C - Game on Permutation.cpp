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

vector<int> seg;
void update(int p, int l, int r, int idx, int x){
    if(l == r){
        seg[p] = x;
    }
    else{
        int m = (l + r) >> 1;
        int lc = 2*p;
        int rc = lc + 1;
        if(idx <= m) update(lc, l, m, idx, x);
        else update(rc, m + 1, r, idx, x);
        seg[p] = max(seg[lc], seg[rc]);
    }
}
int query(int p, int l, int r, int ql, int qr){
    if(l > qr || r < ql) return 0;
    if(l >= ql && r <= qr) return seg[p];
    int m = (l + r) >> 1;
    int lc = 2*p;
    int rc = lc + 1;
    return max(query(lc, l, m, ql, qr), 
                query(rc, m + 1, r, ql, qr));
}

signed main() {
    optimize;
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        int answ = 1;
        seg.assign(4 * (n + 5), 0);
        int mn = v[0];
        for(int i = 1; i < n; i++){
            int curr;
            if(v[i] < mn) curr = 1; // n tenho movimento
            else curr = query(1, 0, n, 0, v[i]);
            if(curr){
                // tenho loose no range
                answ++;
            }
            else{
                // so tenho win, to em loose pos
                update(1, 0, n, v[i], 1);
            }
            mn = min(mn, v[i]);
        }
        cout << n - answ << '\n';
    }
    return 0;
}