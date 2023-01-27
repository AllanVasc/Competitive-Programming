// A - Distinct Characters Queries 
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = 0x3f3f3f3f;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const ll INF = 1e9 + 7;

const int MAX = 100000 + 10;

int segTree[4*MAX];

string v;

void build(int p, int l, int r){

    if(l == r){
        segTree[p] = 1 << (v[r] - 'a');
    }
    else{
        int m = (l+r)/2;
        int lc = 2*p;
        int rc = lc + 1;

        build(lc, l, m);
        build(rc, m+1, r);

        segTree[p] = segTree[lc] | segTree[rc];
    }
}

void update(int p, int l, int r, int idx, char value){

    if(l == r){
        segTree[p] = 1 << (value - 'a');
    }
    else{
        
        int m = (l+r)/2;
        int lc = 2*p;
        int rc = lc + 1;

        if(idx <= m){
            update(lc, l, m, idx, value);
        }
        else{
            update(rc, m+1, r, idx, value);
        }

        segTree[p] = segTree[lc] | segTree[rc];
    }
}

int query(int p, int l, int r, int ql, int qr){

    if(ql <= l && r <= qr){
        return segTree[p];
    }
    else{
        int m = (l+r)/2;
        int lc = 2*p;
        int rc = lc + 1;

        if(qr <= m){
            return query(lc, l , m, ql, qr);
        }
        else if(ql > m){
            return query(rc,m+1,r,ql,qr);
        }
        else{
            return query(lc, l, m, ql,qr) | query(rc, m+1, r,ql, qr);
        }
    }
}
int32_t main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string aux;
    cin >> aux;

    v = "*" + aux;

    int q;
    cin >> q;

    build(1,1, v.size() - 1);

    for(int i = 0; i < q; i++){
        int ord;
        cin >> ord;
        if(ord == 1){
            int pos;
            string c;
            cin >> pos >> c;
            update(1,1, v.size()-1, pos, c[0]);
        }
        else{
            int l,r;
            cin >> l >> r;
            cout << __builtin_popcount(query(1,1,v.size()-1, l, r)) << '\n';
        }
    }

    
    return 0;
}
