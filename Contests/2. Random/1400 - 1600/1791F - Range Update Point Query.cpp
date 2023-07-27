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

const int ms = 2e5 + 100;
pii seg[4 * ms];
vector<int> v;

pii merge(pii & a, pii & b){
    pii answ;
    answ.first = a.first + b.first;
    answ.second = a.second && b.second;
    return answ;
}

void build(int p, int l, int r){
    if(l == r){
        seg[p].first = v[l];
        seg[p].second = (v[l] < 10);
    }
    else{
        int m = (l + r) >> 1;
        int lc = 2*p;
        int rc = lc + 1;
        build(lc, l, m);
        build(rc, m + 1, r);
        seg[p] = merge(seg[lc], seg[rc]);
    }
}

int change(int x){
    int answ = 0;
    while(x){
        answ += x % 10;
        x /= 10;
    }
    return answ;
}

void update(int p, int l, int r, int ql, int qr){
    if(seg[p].second) return;
    if(l == r){
        seg[p].first = change(seg[p].first);
        seg[p].second = (seg[p].first < 10);
    }
    else{
        int m = (l + r) >> 1;
        int lc = 2*p;
        int rc = lc + 1;
        if(qr <= m) update(lc, l, m, ql, qr);
        else if(ql > m) update(rc, m + 1, r, ql, qr);
        else{
            update(lc, l, m, ql, qr);
            update(rc, m + 1, r, ql, qr);
        }
        seg[p] = merge(seg[lc], seg[rc]);
    }
}

int query(int p, int l, int r, int idx){
    if(l == r) return seg[p].first;
    int m = (l + r) >> 1;
    int lc = 2*p;
    int rc = lc + 1;
    if(idx <= m) return query(lc, l, m, idx);
    else return query(rc, m + 1, r, idx);
}

signed main() {
    optimize;
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        v.assign(n, 0);
        for(int i = 0; i < n; i++) cin >> v[i];
        build(1, 0, n - 1);
        while(q--){
            int cmd;
            cin >> cmd;
            if(cmd == 1){
                int l, r; 
                cin >> l >> r;
                l--, r--;
                update(1, 0, n - 1, l, r);
            }
            else{
                int idx; cin >> idx;
                idx--;
                cout << query(1, 0, n - 1, idx) << '\n';
            }
        }
    }
    return 0;
}