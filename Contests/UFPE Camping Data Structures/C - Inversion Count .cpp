// C - Inversion Count 
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = 0x3f3f3f3f;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const ll INF = 1e9 + 7;

const int MAX = 10000000 + 10;
int segTree[4*MAX];

void build(int p, int l, int r){

    if(l == r)  segTree[p] = 0;
    else{
        int m = (l+r)/2;
        int lc = 2*p;
        int rc = lc + 1;
        
        build(lc,l, m);
        build(rc,m+1,r);

        segTree[p] = segTree[lc] + segTree[rc];
    }
}

void update(int p, int l, int r, int idx){

    if(l == r)  segTree[p] = 1;
    else{
        int m = (l+r)/2;
        int lc = 2*p;
        int rc = lc + 1;

        if(idx <= m) update(lc, l, m, idx);
        else update(rc,m+1,r,idx);

        segTree[p] = segTree[lc] + segTree[rc];
    }
}

int query(int p, int l,int r, int ql, int qr){

    if(ql <= l && r <= qr){
        return segTree[p];
    }
    else{
        int m = (l+r)/2;
        int lc = 2*p;
        int rc = lc + 1;

        if(qr <= m){
            return query(lc,l,m,ql,qr);
        }
        else if(ql > m){
            return query(rc,m+1,r,ql,qr);
        }
        else{
            return query(lc,l,m,ql,qr) + query(rc,m+1,r,ql,qr);
        }
    }
}

int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<ii> v;
        for(int i = 0; i < n; i++){
            int aux;
            cin >> aux;
            v.emplace_back(aux,i+1);
        }

        sort(v.begin(),v.end());

        build(1,1,n);

        ll answ = 0;
        for(int i = 0; i < n; i++){
            
            answ += query(1,1,n,v[i].second,n);
            update(1,1,n,v[i].second);
        }

        cout << answ << '\n';
    }

    return 0;
}
