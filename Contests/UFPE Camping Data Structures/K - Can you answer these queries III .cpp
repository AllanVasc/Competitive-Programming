//  K - Can you answer these queries III 
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18;

struct node{
    int sum, pref, suff, answ;
};

const int MAXN = 50000 + 100;
vector<int> v;
node segTree[4*MAXN];

node combine(node l, node r){
    node aux;
    aux.sum = l.sum + r.sum;
    aux.pref = max(l.pref, l.sum + r.pref);
    aux.suff = max(r.suff, r.sum + l.suff);
    aux.answ = max(max(l.answ, r.answ), l.suff + r.pref);

    return aux;
}

void build(int p, int l, int r){
    if(l == r){
        segTree[p].sum = v[l];
        segTree[p].pref = segTree[p].suff = segTree[p].answ = v[l];
    }
    else{
        int m = (l+r)/2;
        int lc = 2*p;
        int rc = lc + 1;

        build(lc,l,m);
        build(rc,m+1,r);

        segTree[p] = combine(segTree[lc], segTree[rc]);
    }
}

void update(int p, int l, int r, int idx, int value){
    if(l == r){
        segTree[p].sum = value;
        segTree[p].pref = segTree[p].suff = segTree[p].answ = value;
    }
    else{
        int m = (l+r)/2;
        int lc = 2*p;
        int rc = lc + 1;

        if(idx <= m){
            update(lc,l,m,idx,value);
        }
        else{
            update(rc,m+1,r,idx,value);
        }
        segTree[p] = combine(segTree[lc], segTree[rc]);
    }
}

node query(int p, int l, int r, int ql, int qr){
    if(ql <= l && r <= qr) return segTree[p];
    else{
        int m = (l+r)/2;
        int lc = 2*p;
        int rc = lc + 1;

        if(qr <= m) return query(lc,l,m,ql,qr);
        else if(ql > m) return query(rc,m+1,r,ql,qr);

        return combine(query(lc,l,m,ql,qr), query(rc,m+1,r,ql,qr));
    }
}

int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    
    v.assign(n+1,-1);
    for(int i = 1; i <= n; i++) cin >> v[i];
    int m;
    cin >> m;

    build(1,1,n);

    for(int i = 0; i < m; i++){
        int op, x, y;
        cin >> op >> x >> y;
        if(op == 0){
            update(1,1,n,x,y);
        }
        else{
            cout << query(1,1,n,x,y).answ << '\n';
        }

    }

    return 0;
}
