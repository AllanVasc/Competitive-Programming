#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int ms = 2*1e5 + 100;
int seg[4 * ms];

void build(int p, int l, int r){
    if(l == r){
        seg[p] = 0;
    }
    else{
        int m = (l + r) >> 1;
        int lc = 2*p;
        int rc = lc + 1;
        build(lc, l, m);
        build(rc, m + 1, r);
        seg[p] = max(seg[lc], seg[rc]);
    }
}

void update(int p, int l, int r, int id, int val){
    if(l == r){
        seg[p] = val;
    }
    else{
        int m = (l + r) / 2;
        int lc = 2*p;
        int rc = lc + 1;
        if(id <= m){
            update(lc, l, m, id, val);
        }
        else{
            update(rc, m + 1, r, id, val);
        }
        
        seg[p] = max(seg[lc], seg[rc]);
    }
}

int query(int p, int l, int r, int ql, int qr){
    if(l > qr || r < ql) return -INF;
    if(l >= ql && r <= qr) return seg[p];
    
    int m = (l + r) >> 1;
    int lc = 2*p;
    int rc = lc + 1;

    return max(query(lc, l, m, ql, qr), query(rc,m + 1, r, ql, qr));
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> h(n);
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> h[i];
    for(int i = 0; i < n; i++) cin >> a[i];
    build(1, 1, ms);
    for(int i = n - 1; i >= 0; i--){
        // cout << "h = " << h[i] << " = " << query(1, 1, ms, h[i], ms) << '\n';
        int answ = a[i] + query(1, 1, ms, h[i], ms);
        update(1, 1, ms, h[i], answ);
    }

    cout << query(1,1,ms,1,ms) << '\n';
    return 0;
}