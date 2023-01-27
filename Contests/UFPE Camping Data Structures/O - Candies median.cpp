//  O - Candies median
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18;

vector<int> v;

class segTree{
    vector<int> seg;
    vector<int> lazy;

public:
    segTree(int n){
        seg.assign(4*n,0);
        lazy.assign(4*n, 0);
    }

    void update(int p, int l, int r, int ql, int qr, int value){
        propagate(p,l,r);
        if(l > qr || r < ql) return;
        if(l >= ql && r <= qr){
            lazy[p] = value;
            propagate(p,l,r);
        }
        else{
            int m = (l+r)/2;
            int lc = 2*p;
            int rc = lc + 1;

            update(lc,l,m,ql,qr,value);
            update(rc,m+1,r,ql,qr,value);

            seg[p] = seg[lc] + seg[rc];
        }
    }

    int query(int p, int l, int r, int target){
        propagate(p,l,r);
        if(l == r) return l;

        int m = (l+r)/2;
        int lc = 2*p;
        int rc = lc + 1;

        propagate(lc,l,m);
        propagate(rc,m+1,r);

        if(seg[lc] >= target) return query(lc,l,m,target);
        else return query(rc,m+1,r,target - seg[lc]);
    }

private:
    void propagate(int p, int l, int r){
        if(lazy[p] == 0) return;

        seg[p] += (r-l+1)*lazy[p];
        if(l != r){
            lazy[2*p] += lazy[p];
            lazy[2*p+1] += lazy[p];
        }
        lazy[p] = 0;
    }

};

int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;

    v.assign(n+1,-1);
    for(int i = 0; i < n; i++) cin >> v[i+1];
    segTree seg(n);

    for(int i = 0; i < q; i++){
        int t;
        cin >> t;
        
        int total = 0;
        vector<iii> qs;

        for(int j = 0; j < t; j++){
            int ql,qr,x;
            cin >> ql >> qr >> x;
            seg.update(1,1,n,ql,qr,x);
            total += (qr-ql+1)*x;
            qs.emplace_back(ql,qr,x);
        }

        if(total%2 == 1){
            int target = total/2 + 1;
            cout << v[seg.query(1,1,n,target)] << '\n';
        }
        else{
            int target = total/2;

            int a = v[seg.query(1,1,n,target)];
            int b = v[seg.query(1,1,n,target+1)];

            cout << ((a+b)/2);
            if ((a+b) % 2) cout << ".5";
            cout << "\n";
        }
        for(int j = 0; j < t; j++){
            int ql = get<0>(qs[j]);
            int qr = get<1>(qs[j]);
            int x = get<2>(qs[j]);
            seg.update(1,1,n,ql,qr,-x);
        }
    }
    return 0;
}
