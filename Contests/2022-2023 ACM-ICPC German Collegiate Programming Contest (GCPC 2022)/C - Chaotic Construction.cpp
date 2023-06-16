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

const int ms = 1e5 + 100;
int seg[4 * ms];
void update(int p, int l, int r, int idx, int val){
    if(l == r){
        seg[p] = val;
    }
    else{
        int m = (l + r) >> 1;
        int lc = 2*p;
        int rc = lc + 1;
        if(idx <= m) update(lc, l, m, idx, val);
        else update(rc, m + 1, r, idx, val);
        seg[p] = seg[lc] + seg[rc];
    }
}

int query(int p, int l, int r, int ql, int qr){
    if(l >= ql && r <= qr){
        return seg[p];
    }
    int m = (l + r) >> 1;
    int lc = 2*p;
    int rc = lc + 1;
    if(qr <= m) return query(lc, l, m, ql, qr);
    else if(ql > m) return query(rc, m + 1, r, ql, qr);
    return (query(lc, l, m, ql, qr) + query(rc, m + 1, r, ql ,qr));
}

int32_t main() {
    optimize;
    
    int n, q;
    cin >> n >> q;

    for(int i = 0; i < q; i++){
        char cmd;
        cin >> cmd;
        if(cmd == '-'){
            int idx; cin >> idx;
            idx--;
            update(1, 0, n - 1, idx, 1);
        }
        else if(cmd == '+'){
            int idx; cin >> idx;
            idx--;
            update(1, 0, n -1, idx, 0);
        }
        else{
            int l, r;
            cin >> l >> r;
            l--, r--;
            if(l > r) swap(l, r);
            int answ1 = query(1, 0, n - 1, l, r);
            int answ2 = query(1, 0, n - 1, 0, l) + query(1, 0, n -1, r, n - 1);

            if(answ1 == 0 || answ2 == 0){
                cout << "possible" << '\n';
            }
            else{
                cout << "impossible" << '\n';
            }
        }
    }
    return 0;
}