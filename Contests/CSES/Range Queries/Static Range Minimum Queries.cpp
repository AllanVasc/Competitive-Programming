#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int ms = 2*1e5;
int segtree[4*ms];
vector<int> v;

void build(int p, int l, int r){
    if(l == r){
        segtree[p] = v[l];
    }
    else{
        int m = (l + r)/2;
        int lc = 2*p;
        int rc = lc + 1;

        build(lc, l, m);
        build(rc, m+1, r);

        segtree[p] = min(segtree[lc], segtree[rc]);
    }
}

int query(int p, int l, int r, int ql, int qr){
    if(ql <= l && r <= qr){
        return segtree[p];
    }
    else{
        int m = (l+r)/2;
        int lc = 2*p;
        int rc = lc + 1;

        if(qr <= m) return query(lc, l, m, ql, qr);
        else if(ql > m) return query(rc, m+1, r, ql, qr);
        else return min(query(lc, l, m, ql, qr), query(rc, m+1, r, ql, qr));
    }
}

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    v.push_back(-1);
    for(int i = 0; i < n; i++){
        int aux;
        cin >> aux;
        v.push_back(aux);
    }

    build(1, 1, n);

    while(q--){
        int a, b;
        cin >> a >> b;

        cout << query(1, 1, n, a, b) << '\n';
    }

    return 0;
}