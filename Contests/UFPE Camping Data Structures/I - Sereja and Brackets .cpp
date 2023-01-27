//  I - Sereja and Brackets 
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = 0x3f3f3f3f;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const ll INF = 1e9 + 7;

const int MAX = 1e6 + 10;

string v;

struct node{
    int open,close,answ;

    node operator+(const node &b){
        node aux;
        aux.answ = answ + b.answ + min(open, b.close); 
        aux.open = open + b.open - min(open, b.close);
        aux.close = close + b.close - min(open, b.close);
        return aux;
    }
};

node segTree[4*MAX];

void build(int p, int l, int r){
    if(l == r){
        if(v[l] == '('){
            segTree[p].open = 1;
            segTree[p].close = 0;
            
        }
        else{
            segTree[p].open = 0;
            segTree[p].close = 1;
        }

        segTree[p].answ = 0;
    }
    else{
        int m = (l+r)/2;
        int lc = 2*p;
        int rc = lc + 1;

        build(lc,l,m);
        build(rc,m+1,r);

        segTree[p] = segTree[lc] + segTree[rc];
    }
}

node query(int p, int l, int r, int ql, int qr){

    if(ql <= l && r <= qr){
        return segTree[p];
    }
    else{
        int m = (l+r)/2;
        int lc = 2*p;
        int rc = lc + 1;

        if(qr <=m) return query(lc,l,m,ql,qr);
        else if(ql > m) return query(rc,m+1,r,ql,qr);
        else{

            node left = query(lc,l,m,ql,qr);
            node right = query(rc,m+1,r,ql,qr);
            return left + right;
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

    build(1,1,v.size() - 1);

    int q;
    cin >> q;
    while(q--){
        int l,r;
        cin >> l >> r;
        cout << 2*query(1,1,v.size()-1,l,r).answ << '\n';
    }

    return 0;
}

/*

https://www.geeksforgeeks.org/range-queries-longest-correct-bracket-subsequence/

*/