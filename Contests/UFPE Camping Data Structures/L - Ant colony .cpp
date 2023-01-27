//  L - Ant colony 
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = 0x3f3f3f3f;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const ll INF = 1e9 + 7;

const int MAX = 1e5 + 10;

int v[4*MAX];
ii segTree[4*MAX];

void build(int p, int l,int r){
    if(l == r){
        segTree[p] = {v[l],1};
    }
    else{
        int m = (l+r)/2;
        int lc = 2*p;
        int rc = lc + 1;

        build(lc,l,m);
        build(rc, m+1, r);
        
        int gcd_answ = __gcd(segTree[lc].first, segTree[rc].first);
        int count = 0;
        if(segTree[lc].first == segTree[rc].first){
            count = segTree[lc].second + segTree[rc].second;
        }
        else if(gcd_answ == segTree[lc].first){
            count = segTree[lc].second;
        }
        else if(gcd_answ == segTree[rc].first){
            count = segTree[rc].second;
        }
        else{
            count = 0;
        }
        segTree[p] = {gcd_answ, count};
    }
}

ii query(int p, int l, int r, int ql, int qr){

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

            ii left = query(lc,l,m,ql,qr);
            ii right = query(rc,m+1,r,ql,qr);
            
            int gcd_answ = __gcd(left.first, right.first);
            int count = 0;
            if(left.first == right.first){
                count = left.second + right.second;
            }
            else if(gcd_answ == left.first){
                count = left.second;
            }
            else if(gcd_answ == right.first){
                count = right.second;
            }
            else{
                count = 0;
            }

            return {gcd_answ, count};
        }
    }
}

int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> v[i+1];
    }

    build(1,1,n);
    
    int q;
    cin >> q;
    while(q--){
        int l,r;
        cin >> l >> r;
        cout << (r-l+1) - query(1,1,n,l,r).second << '\n';
    }

    return 0;
}
