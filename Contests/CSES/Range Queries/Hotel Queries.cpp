#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

vector<int> segtree;
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
        build(rc, m + 1, r);

        segtree[p] = max(segtree[lc], segtree[rc]);
    }
}

int query(int p, int l, int r, int ql, int qr, int k){
    int answ;
    if(l == r){
        if(segtree[p] >= k){
            segtree[p] -= k;
            return l;
        }
        else{
            return 0;
        }
    }
    else{
        int m = (l + r)/2;
        int lc = 2*p;
        int rc = lc + 1;

        if(segtree[lc] >= k) answ = query(lc, l, m, ql, qr, k);
        else answ = query(rc, m + 1, r, ql, qr, k); 

        segtree[p] = max(segtree[lc], segtree[rc]);
        return answ;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n, m;
    cin >> n >> m;

    v.assign(n + 1, -1);
    for(int i = 1; i <= n; i++) cin >> v[i];
    segtree.assign(4*n, 0);
    build(1, 1, n);

    for(int i = 0; i < m; i++){
        int rooms;
        cin >> rooms;
        
        cout << query(1, 1, n, 1, n, rooms) << " ";
    }
    cout << '\n';
    return 0;
}