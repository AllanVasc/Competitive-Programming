//  N - Freaky Fertilizer Tests
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18;

const int MOD = 998244353;
vector<int> v;

int fastModExp(int x, int y, int p){
    int ans = 1;
    x = x % p;      
    if (x == 0) return 0; 
    while(y){ 
        if (y & 1) ans = (ans*x) % p; 
        y = y >> 1;
        x = (x*x) % p;
    }
    return ans;
}

class segTree{
    vector<int> seg;
    vector<ii> lazy;

public:

    segTree(int n){
        seg.assign(4*n, 0);
        lazy.assign(4*n, {-1,-1});
        build(1,1,n);
    }

    void update(int p, int l, int r, int ql, int qr, ii value){
        propagate(p,l,r);
        if(r < ql || l > qr) return;
        if(ql <= l && r <= qr){
            lazy[p] = value;
            propagate(p,l,r);
        }
        else{
            int m = (l+r)/2;
            int lc = 2*p;
            int rc = lc + 1;

            update(lc,l,m,ql,qr,value);
            update(rc,m+1,r,ql,qr,value);

            seg[p] = (seg[lc] + seg[rc])%MOD;
        }
    }

    int query(int p, int l, int r, int ql, int qr){
        propagate(p,l,r);
        if(r < ql || l > qr) return 0;
        if(ql <= l && r <= qr) return seg[p];

        int m = (l+r)/2;
        int lc = 2*p;
        int rc = lc + 1;

        return (query(lc,l,m,ql,qr) + query(rc,m+1,r,ql,qr))%MOD;
    }

private:
    void build(int p, int l, int r){
        if(l == r){
            seg[p] = v[l]%MOD;
            lazy[p] = {-1, -1};
        }
        else{
            int m = (l+r)/2;
            int lc = 2*p;
            int rc = lc+1;

            build(lc,l,m);
            build(rc,m+1,r);

            seg[p] = (seg[lc] + seg[rc])%MOD;
        }
    }

    void propagate(int p, int l, int r){
        if(lazy[p].first == -1) return;

        seg[p] = ((seg[p]*lazy[p].first)%MOD + lazy[p].second)%MOD;

        if(l != r){
            if(lazy[2*p].first == -1) lazy[2*p] = lazy[p];
            else{
                lazy[2*p].first *= lazy[p].first;
                lazy[2*p].first %= MOD;
                lazy[2*p].second *= lazy[p].first;
                lazy[2*p].second %= MOD;
                lazy[2*p].second += lazy[p].second;
                lazy[2*p].second %= MOD;
            }
            if(lazy[2*p+1].first == -1) lazy[2*p+1] = lazy[p];
            else{
                lazy[2*p+1].first *= lazy[p].first;
                lazy[2*p+1].first %= MOD;
                lazy[2*p+1].second *= lazy[p].first;
                lazy[2*p+1].second %= MOD;
                lazy[2*p+1].second += lazy[p].second;
                lazy[2*p+1].second %= MOD;
            }
        }
        lazy[p] = {-1,-1};
    }
};

int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;

    v.assign(n+1,-1);
    for(int i = 1; i <= n; i++) cin >> v[i];

    segTree seg(n);

    for(int i = 0; i < q; i++){
        int op;
        cin >> op;
        if(op == 1){
            int l,r,f,g,t;
            cin >> l >> r >> f >> g >> t;
            if(t == 0) continue;
            ii value;
            value.first = fastModExp(f,t,MOD);
            if(f > 1) value.second = (((g*((fastModExp(f,t,MOD) - 1 + MOD)%MOD))%MOD)*fastModExp(f-1,MOD-2,MOD))%MOD;
            else if(f == 1) value.second = (g*t)%MOD;
            else{
                value.second = g%MOD;
            }
            seg.update(1,1,n,l,r,value);
        }
        else{
            int x;
            cin >> x;
            cout << seg.query(1,1,n,x,x) << '\n';
        }
    }
    return 0;
}
