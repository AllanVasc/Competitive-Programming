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

#define ull __int128_t

const int MOD = 1e9 + 7;

const int ms = 300005;
ull seg[4 * ms], lazy[4 * ms];

struct Query{
    int l, r, val;
    Query(int l, int r, int val) : l(l), r(r), val(val) {}
};

void build(int p, int l, int r){
    if(l == r){
        seg[p] = 0;
        lazy[p] = 0;
    }
    else{
        int m = (l + r) >> 1;
        int lc = 2*p;
        int rc = lc + 1;
        build(lc, l, m);
        build(rc, m + 1, r);
        seg[p] = seg[lc] + seg[rc];
    }
}

void propagate(int p, int l, int r){
    if(lazy[p] == 0) return;
    seg[p] += ( (ull) r - l + 1) * lazy[p];
    if(l != r){
        lazy[2*p] += lazy[p];
        lazy[2*p + 1] += lazy[p];
    }
    lazy[p] = 0;
}

void update(int p, int l, int r, int ql, int qr, int x){
    propagate(p, l, r);
    if(l >= ql && r <= qr){
        lazy[p] = x;
        propagate(p, l, r);
        return;
    }
    int m = (l + r) >> 1;
    int lc = 2*p;
    int rc = lc + 1;
    if(qr <= m) update(lc, l, m, ql, qr, x);
    else if(ql > m) update(rc, m + 1, r, ql, qr, x);
    else{
        update(lc, l, m, ql, qr, x);
        update(rc, m + 1, r, ql, qr, x);
    }
    seg[p] = seg[lc] + seg[rc];
}

ull query(int p, int l, int r, int ql, int qr){
    propagate(p, l, r);
    if(l >= ql && r <= qr) return seg[p];
    int m = (l + r) >> 1;
    int lc = 2*p;
    int rc = lc + 1;
    if(qr <= m) return query(lc, l, m, ql, qr);
    else if(ql > m) return query(rc, m + 1, r, ql, qr);
    else return query(lc, l, m, ql, qr) + query(rc, m + 1, r, ql, qr);
}

void apply(Query & query, int m){
    int l = query.l, r = query.r, x = query.val;
    if(r < l){
        update(1, 0, m - 1, l, m - 1, x);
        update(1, 0, m - 1, 0, r, x);
    }
    else{
        update(1, 0, m - 1, l, r, x);
    }
}

signed main() {
    optimize;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> sectors(n);
    for(int i = 0; i < m; i++){
        int x; cin >> x;
        x--;
        sectors[x].push_back(i);
    }
    vector<int> need(n);
    for(int i = 0; i < n; i++) cin >> need[i];
    int q; cin >> q;
    vector<Query> queries;
    for(int i = 0; i < q; i++){
        int l, r, x;
        cin >> l >> r >> x;
        l--, r--;
        queries.push_back(Query(l, r, x));
    }
    vector<int> answ(n, q + 1);
    vector<int> L(n, 0), R(n, q - 1);
    bool flag = true;
    while(flag){
        flag = false;
        vector<vector<int>> check(q);
        memset(seg, 0, sizeof seg);
        memset(lazy, 0, sizeof lazy);
        for(int i = 0; i < n; i++){
            if(L[i] > R[i]) continue;
            flag = true;
            int mid = (L[i] + R[i]) >> 1;
            check[mid].push_back(i); 
        }
        for(int i = 0; i < q; i++){
            apply(queries[i], m);
            for(auto member : check[i]){
                ull tot = 0;
                for(auto pos : sectors[member]){
                    tot += query(1, 0, m - 1, pos, pos);
                    if(tot >= need[member]) break;
                }
                if(tot >= need[member]){
                    answ[member] = min(answ[member], i);
                    R[member] = i - 1;
                }
                else{
                    L[member] = i + 1;
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(answ[i] == q + 1) cout << "NIE" << '\n';
        else cout << answ[i] + 1 << '\n';
    }
    return 0;
}