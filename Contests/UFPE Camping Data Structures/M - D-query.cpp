//  M - D-query
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18;

const int MAXN = 30000 + 10;
vector<int> v;
vector<int> b;

vector<int> seg[4*MAXN];

void build(int p,int l, int r){
    if(l == r){
        seg[p] = vector<int>(1, b[l]);
    }
    else{
        int m = (l+r)/2;
        int lc = 2*p;
        int rc = lc + 1;

        build(lc,l,m);
        build(rc,m+1,r);

        merge( seg[lc].begin(), seg[lc].end(),
               seg[rc].begin(), seg[rc].end(),
               back_inserter(seg[p]));
    }
}

int query(int p, int l, int r, int ql, int qr, int k){
    if(l >= ql && r <= qr){
        return upper_bound(seg[p].begin(), seg[p].end(), k) - seg[p].begin();
    }
    else{
        int m = (l+r)/2;
        int lc = 2*p;
        int rc = lc + 1;

        if(qr <= m){
            return query(lc,l,m,ql,qr,k);
        }
        else if(ql > m){
            return query(rc,m+1,r,ql,qr,k);
        }
        return query(lc,l,m,ql,qr,k) + query(rc,m+1,r,ql,qr,k);
    }
}

int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    v.assign(n+1, -1);
    for(int i = 0; i < n; i++) cin >> v[i+1];

    b.assign(n+1,-1);
    map<int,int> m;

    for(int i = n; i >= 1; i--){
        if(m[v[i]] == 0){
            b[i] = INF;
            m[v[i]] = i;
        }
        else{
            b[i] = m[v[i]];
            m[v[i]] = i;
        }
    }

    // for(int i = 0; i < b.size(); i++) cout << b[i] << "\n";
    
    build(1,1,n);
    int q;
    cin >> q;

    for(int i = 0; i < q; i++){
        int ql, qr;
        cin >> ql >> qr;

        cout << (qr-ql+1) - query(1,1,n,ql,qr,qr) << '\n';
    }

    return 0;
}

/*

https://stackoverflow.com/questions/39787455/is-it-possible-to-query-number-of-distinct-integers-in-a-range-in-olg-n

*/
